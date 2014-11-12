#include <xc.h>
#include "pic_config.h"

#include <stdlib.h>
#include <stdint.h>

#include "adc.h"


void initialize_voltage_reference(void) {
    // Set voltage
    //FVRCONbits.ADFVR = 0b01; // 1.024 V
    FVRCONbits.ADFVR = 0b10; // 2.048 V
    //FVRCONbits.ADFVR = 0b11; // 4.096 V

    // Enable
    FVRCONbits.FVREN = 1;

    // Wait for stabilization
    while (FVRCONbits.FVRRDY == 0);
}

void initialize_adc(void) {
    // Set A4 pin as input to allow external control of the voltage
    TRISA4 = 1;

    // Configure pin as analog input
    ANSELAbits.ANSA4 = 1;

    // Select ADC conversion clock
    //ADCON1bits.ADCS = 0b101; // Fosc/16
    ADCON1bits.ADCS = 0b010; // Fosc/32
    //ADCON1bits.ADCS = 0b110; // Fosc/64

    // Select ADC result format
    ADCON1bits.ADFM = 1; // Right justified

    // Select voltage reference
    ADCON1bits.ADPREF = 0b11; // Internal fixed voltage reference module

    // Select ADC input channel
    ADCON0bits.CHS = 0b00011; // AN3 (RA4, pin 3)

    // Turn on ADC module
    ADCON0bits.ADON = 1;
}

uint16_t analog_read(void) {
    // Wait the required aquisition time
    __delay_us(5);

    // Start conversion
    ADCON0bits.GO = 1;

    // Wait until conversion is done
    while (ADCON0bits.nDONE == 1);

    // Read and return A/D converted value
    return ADRES;
}