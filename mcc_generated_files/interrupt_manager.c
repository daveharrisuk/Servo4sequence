/**
@File interrupt_manager.c

@Project Servo4sequence

@Summary Interrupt Manager source file for PIC16F1xxx

@author Dave Harris

@date Aug 2023
*/

#include "mcc.h"
#include "interrupt_manager.h"

void __interrupt() INTERRUPT_InterruptManager (void)
{
    if(PIR0bits.TMR0IF == 1)
    {
        TMR0_ISR();
    }
    
    if(PIR1bits.TMR1IF == 1)
    {

        TMR1_ISR();
    }
}


/*------------------------ End of File --------------------------------*/
