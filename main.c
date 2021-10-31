// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)

// CONFIG3L
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include "interrupts.h"
#include "comparator.h"
#include "timers.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  


void main(void) {
	//call your initialisation functions to set up the hardware modules
    Comp1_init();
    Interrupts_init();
    Timer0_init();
    LEDarray_init();
    
    TRISHbits.TRISH3 = 0;
    LATHbits.LATH3 = 0;

    while (1) {
//        Sleep();
        unsigned int time = get16bitTMR0val();
        LEDarray_disp_bin(time);
//        if (T0CON0bits.T0OUT) {  // when overflow
//            // restart the timer
////            T0CON0bits.T0EN=0;  
////            T0CON0bits.T0EN=1;
//            // toggle the LED to see the timer output
//            LATHbits.LATH3 = 1;
//            __delay_ms(50);
//            LATHbits.LATH3 = 0;
//            __delay_ms(50);
//        }
    }
}