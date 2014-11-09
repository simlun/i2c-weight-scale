#include <xc.h>

#include <stdlib.h>
#include <stdint.h>

#include "bool.h"

// ----------------------------------------------------------------------
// Data
volatile static bit i2c_buffer_index = 0;


// ----------------------------------------------------------------------
// I2C implementation
void initialize_i2c_readonly_slave(uint8_t seven_bit_address) {
    // Set SCL and SDA pins as inputs by settings the TRIS bits (p. 229)
    TRISA1 = 1; // SCL
    TRISA2 = 1; // SDA

    // Setup MSSP as I2C slave mode, 7-bit address
    // with Start and Stop bit interrupts
    SSPCON1bits.SSPM = 0b1110;

    // Set I2C slave address
    SSP1ADDbits.SSPADD = seven_bit_address << 1;

    // Enable the MSSP module
    SSPCON1bits.SSPEN = 1;

    // Enable the MSSP interrupt
    SSP1IE = 1;

    // Enable all active peripheral interrupts
    PEIE = 1;

    // Enable all active interrupts
    GIE = 1;
}

bool is_i2c_read_operation_and_last_bit_was_an_address_byte(void) {
    // "State 3" from the Microchip application notes AN734
    // S = 1, D_A = 0, R_W = 1
    return (SSP1STATbits.S == 1 && SSP1STATbits.D_nA == 0 && SSP1STATbits.R_nW == 1);
}

bool is_i2c_read_operation_and_last_byte_was_a_data_byte(void) {
    // "State 4" from the Microchip application notes AN734
    // S = 1, D_A = 1, R_W = 1, BF = 0
    return (SSP1STATbits.S == 1 && SSP1STATbits.D_nA == 1 && SSP1STATbits.R_nW == 1 && SSP1STATbits.BF == 0);
}

/*
 * Take a 16 bit source value and return the first 8 bits the first time this
 * function is called, then return the last 8 bits the second time. The source
 * value is stored and ignored for the second function call to protect it from
 * getting inconsistent if the source changed in between calls.
 *
 * Useful for sending an uint16_t over I2C in two subsequent 8-bit writes.
 */
uint8_t chunked(uint16_t source) {
    volatile static uint16_t my_source;

    if (i2c_buffer_index == 0) {
        my_source = source;
    }

    uint8_t chunks[2];
    chunks[0] = my_source >> 8;
    chunks[1] = (my_source << 8) >> 8;

    uint8_t return_value = chunks[i2c_buffer_index];

    i2c_buffer_index = !i2c_buffer_index;

    return return_value;
}

void i2c_write(uint8_t data) {
    // The "WriteI2C" subroutine from the Microchip application notes AN734
    // converted into C code

    // Wait for buffer to be empty
    while (SSP1STATbits.BF == 1);

    // Write data
    SSP1CON1bits.WCOL = 0;
    do {
        SSP1BUF = data;
    } while (SSP1CON1bits.WCOL == 1);

    // Release the clock, we are done
    SSP1CON1bits.CKP = 1;
}

void i2c_2_byte_master_read_request_handler(uint16_t * data_to_send_to_master) {
    if (SSP1IF == 1) {
        SSP1IF = 0;

        if (is_i2c_read_operation_and_last_bit_was_an_address_byte()) {
            // Read address from buffer, clearing BF
            unsigned char tmp = SSP1BUF;
            i2c_buffer_index = 0;
            i2c_write(chunked(*data_to_send_to_master));
        } else if (is_i2c_read_operation_and_last_byte_was_a_data_byte()) {
            i2c_write(chunked(*data_to_send_to_master));
        }
    }
}