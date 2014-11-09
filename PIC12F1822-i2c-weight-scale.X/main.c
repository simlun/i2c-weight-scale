// ----------------------------------------------------------------------
// Includes
#include <xc.h>
#include "pic_config.h"

#include <stdlib.h>
#include <stdint.h>

#include "i2c.h"


// ----------------------------------------------------------------------
// Data
volatile uint16_t foo;


// ----------------------------------------------------------------------
// Configuration and initialization functions
void initialize_data_variables(void) {
    foo = 0x4711;
}

void initialize_io(void) {
    // Set A5 pin as an output
    TRISA5 = 0;
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