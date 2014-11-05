#include <xc.h>

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

// #pragma config statements should precede project file includes.

#include <stdlib.h>


#define _XTAL_FREQ 16000000


void configure_oscillator(void) {
    // Set internal oscillator block
    OSCCONbits.SCS = 0b10;

    // Disable 4x PLL
    OSCCONbits.SPLLEN = 0;

    // Set internal oscillator frequency
    OSCCONbits.IRCF = 0b1111; // 16 MHz
}


void configure_io(void) {
    // Set A5 pin as an output
    TRISA5 = 0;
}


void blink_once(void) {
    PORTAbits.RA5 = 1;
    __delay_ms(500);
    PORTAbits.RA5 = 0;
    __delay_ms(500);
}


void configure_i2c(void) {
    // Set SCL and SDA pins as inputs by settings the TRIS bits (p. 229)
    TRISA1 = 1; // SCL
    TRISA2 = 1; // SDA

    // Setup MSSP as I2C slave mode, 7-bit address
    // with Start and Stop bit interrupts
    SSPCON1bits.SSPM = 0b1110;

    // Set I2C slave address to decimal 17
    SSP1ADDbits.SSPADD = 0b00100010; // Shifted 1 bit to the left
    
    // Enable the MSSP module
    SSPCON1bits.SSPEN = 1;

    // Enable the MSSP interrupt
    SSP1IE = 1;
    
    // Enable all active peripheral interrupts
    PEIE = 1;

    // Enable all active interrupts
    GIE = 1;
}


int main(void) {
    configure_oscillator();
    configure_io();

    blink_once();

    configure_i2c();

    blink_once();

    while (1);
}


typedef unsigned char bool;
#define true    1
#define false   0

bool is_i2c_write_operation_and_got_address_byte(void) {
    return false; // TODO
}

bool is_i2c_write_operation_and_got_data_byte(void) {
    return false; // TODO
}

bool is_i2c_read_operation_and_got_address_byte(void) {
    // S = 1, D_A = 0, R_W = 1
    if (SSP1STATbits.S == 1 && SSP1STATbits.D_nA == 0 && SSP1STATbits.R_nW == 1) {
        return true;
    } else {
        return false;
    }
}

void interrupt ISR(void) {
    if (SSP1IF == 1) {
        SSP1IF = 0;
        
        // Read address
        if (is_i2c_write_operation_and_got_address_byte()) {

        } else if (is_i2c_write_operation_and_got_data_byte()) {

        } else if (is_i2c_read_operation_and_got_address_byte()) {
            unsigned char buffer;
            buffer = SSP1BUF;

            SSP1BUF = 'a';

            SSP1CON1bits.CKP = 1;
            
            blink_once();
        }
    }
}
