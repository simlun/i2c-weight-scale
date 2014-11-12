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

volatile uint16_t foo[30];
volatile uint8_t foo_index;


// ----------------------------------------------------------------------
// Configuration and initialization functions
void initialize_io(void) {
    // Set A5 pin as an output
    TRISA5 = 0;

    int i;
    for (i = 0; i < 30; i++) {
        foo[i] = 0;
    }
    foo_index = 0;
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
        foo[foo_index] = analog_read();
        foo_index++;
        if (foo_index > 30) {
            foo_index = 0;
        }

        uint16_t tmp = 0;
        int i;
        for (i = 0; i < 30; i++) {
            tmp += foo[i];
        }
        tmp = tmp / 30;
        analog_value = tmp;
    }
}


// ----------------------------------------------------------------------
// Interrupt Service Routine
void interrupt ISR(void) {
    i2c_2_byte_master_read_request_handler(&analog_value);
}