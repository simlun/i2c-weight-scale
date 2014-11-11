// ----------------------------------------------------------------------
// Includes
#include <xc.h>
#include "pic_config.h"

#include <stdlib.h>
#include <stdint.h>

#include "i2c.h"
#include "adc.h"


// ----------------------------------------------------------------------
// Data
volatile uint16_t analog_value = 0x4711;


// ----------------------------------------------------------------------
// Configuration and initialization functions
void initialize_io(void) {
    // Set A5 pin as an output
    TRISA5 = 0;
}


// ----------------------------------------------------------------------
// Logic functions
void blink_once(void) {
    PORTAbits.RA5 = 1;
    __delay_ms(25);
    PORTAbits.RA5 = 0;
}


// ----------------------------------------------------------------------
// Main
int main(void) {
    initialize_oscillator();
    initialize_io();
    initialize_voltage_reference();
    initialize_adc();
    initialize_i2c_readonly_slave(0x11);

    blink_once();

    while (1) {
        analog_value = analog_read();
    }
}


// ----------------------------------------------------------------------
// Interrupt Service Routine
void interrupt ISR(void) {
    i2c_2_byte_master_read_request_handler(&analog_value);
}