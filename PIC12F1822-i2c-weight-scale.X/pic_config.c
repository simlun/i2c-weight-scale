#include "pic_config.h"


void initialize_oscillator(void) {
    // Set internal oscillator block
    OSCCONbits.SCS = 0b10;

    // Disable 4x PLL
    OSCCONbits.SPLLEN = 0;

    // Set internal oscillator frequency
    OSCCONbits.IRCF = 0b1111; // 16 MHz
}