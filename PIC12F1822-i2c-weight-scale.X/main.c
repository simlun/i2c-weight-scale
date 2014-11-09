#include <xc.h>

// ----------------------------------------------------------------------
// PIC12F1822 Configuration Bit Settings
// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = HI        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), high trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

#define _XTAL_FREQ 16000000

// #pragma config statements should precede project file includes.


// ----------------------------------------------------------------------
// Includes and type declarations
#include <stdlib.h>
#include <stdint.h>

typedef unsigned char bool;
#define true 1
#define false 0


// ----------------------------------------------------------------------
// Data
volatile uint16_t foo;


// ----------------------------------------------------------------------
// Configuration and initialization functions
void initialize_data_variables(void) {
    foo = 0x4711;
}


void initialize_oscillator(void) {
    // Set internal oscillator block
    OSCCONbits.SCS = 0b10;

    // Disable 4x PLL
    OSCCONbits.SPLLEN = 0;

    // Set internal oscillator frequency
    OSCCONbits.IRCF = 0b1111; // 16 MHz
}


void initialize_io(void) {
    // Set A5 pin as an output
    TRISA5 = 0;
}


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

volatile static bit i2c_buffer_index = 0;

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


// ----------------------------------------------------------------------
// Logic functions
void blink_once(void) {
    PORTAbits.RA5 = 1;
    __delay_ms(100);
    PORTAbits.RA5 = 0;
    __delay_ms(100);
}


// ----------------------------------------------------------------------
// Main
int main(void) {
    initialize_oscillator();
    initialize_data_variables();
    initialize_io();
    initialize_i2c_readonly_slave(0x11);

    blink_once();

    while (1) {
        __delay_ms(1000);
        foo++;
    }
}


// ----------------------------------------------------------------------
// Interrupt Service Routine
void interrupt ISR(void) {
    i2c_2_byte_master_read_request_handler(&foo);
}
