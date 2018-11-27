/*
 * File:   newmain.c
 * Author: zachc
 * 
 * Created on October 1, 2018, 8:58 PM
 */
#include "pragma.h"
#include <pic18f25k22.h>
#include <xc.h>

// indicator LED
#define LED_DIR TRISBbits.TRISB4
#define LED_SET LATBbits.LATB4
#define LED_READ PORTBbits.RB4
#define _XTAL_FREQ 16000000
// Macros --^





void main(void) {
    
    ANSELA = 0b00000000;
    ANSELB = 0b00000000;
    ANSELC = 0b00000000;
    
    TRISCbits.RC3 = 0b0; // Out is 0, i is 1 or input, obo for binary bit 0s
    TRISBbits.RB1 = 0b0; // Test Output, see if we know what we are doing... (Do we?)
    
    // Tx and Rx ports for ESP:
    TRISCbits.RC5 = 0b0; // Tx
    TRISCbits.RC4 = 0b0; // Rx
    LATCbits.LATC5 = 0b1;
    LATCbits.LATC4 = 0b1;

    
    
    
    LATBbits.LATB1 = 0b1;
    LATCbits.LATC3 = 0b1;
    
    // Read Port
    // PORTCbits.RC3
    
    int inx;
    for( inx = 0; inx < 1000; inx++ )
    {
    LATCbits.LATC4 = 0b1;
    LATCbits.LATC5 = 0b0;
    
    LATBbits.LATB1 = 0b0;
    __delay_ms(10);
    LATBbits.LATB1 = 0b1;
    __delay_ms(10);
    
    
    LATCbits.LATC3 = 0b0;
	__delay_ms(10);
    LATCbits.LATC3 = 0b1;
    __delay_ms(10);
    
    LATCbits.LATC4 = 0b0;
    LATCbits.LATC5 = 0b1;
    __delay_ms(30);


    }
    
    
            
    return;
}
