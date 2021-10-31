#include <xc.h>
#include "interrupts.h"

/************************************
 * Function to turn on interrupts and set if priority is used
 * Note you also need to enable peripheral interrupts in the INTCON register to use CM1IE.
************************************/
void Interrupts_init(void)
{
	// turn on global interrupts, peripheral interrupts and the interrupt source 
	// It's a good idea to turn on global interrupts last, once all other interrupt configuration is done.
//    PIE2bits.C1IE = 1;  // enable Comparator 1 Interrupt Enable bit (Peripheral Interrupt Enable Register 2)
//    INTCONbits.GIEL = 1;  // turn on peripheral interrupts
    INTCONbits.GIE = 1;  // turn on global interrupts 
    TMR0IE = 1;
}

/************************************
 * High priority interrupt service routine
 * Make sure all enabled interrupts are checked and flags cleared
************************************/
void __interrupt(high_priority) HighISR()
{
	//add your ISR code here i.e. check the flag, do something (i.e. toggle an LED), clear the flag...
    if (TMR0IF) {
        LATHbits.LATH3 = !LATHbits.LATH3;  // toggling LED
        TMR0IF = 0;  // clear the flag
    }
}

