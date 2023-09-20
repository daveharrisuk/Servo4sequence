/**@file main.c        @PROJECT_NAME Servo4sequence

@version 0.2
@history 10-Jul-2023 v0.0 DH started
@history 22-Aug-2023 v0.1 DH 1st working version
@history 05-Sep-2023 v0.2 DH debugged working version, minus setup mode

@brief Environment
   Language  C  Version C99.
   IDE       Microchip MPLAB X v6.10, with MCC(MPLAB Code Configurator) v5.3.7
   Compiler  XC8 v2.41 (free). Device Family Pack: PIC16F1xxxx_DFP v1.20.366
   MCU       Microchip PIC16F18323
   PCB       KiCad project.

@brief Peripheral configuration (setup in MCC)
   FOSC - HFINTOSC 32MHz
   TMR0 - 8 bit, FOSC/4, PreScaler 1:1, period 10 us, interrupt, PWM duty cycle
   TMR1 - 16 bit, FOSC/4, PreScaler 1:4, period 4 ms, interrupt, PWM period
   ADC  - 10 bit, FOSC/32 (TAD 1.0 us), conversion 11.5 us, right align.

@brief MCU pin/port usage.  Pins names configured in MCC.
   PIC16F18323 SOIC14 top view   +----u----+ 
                     +5.0V - VDD | 1    14 | VSS - 0V
         PIN_SV1 - out RA5 - RA5 | 2    13 | RA0/ICSPDAT - RA0 in^ - PIN_IN0
         PIN_SV2 - out RA4 - RA4 | 3    12 | RA1/ICSPCLK - RA1 out - PIN_LED1
  PIN_IN1 in^ RA3 - RA3/MCLR/VPP | 4    11 | RA2 - AN2 analog - PIN_POT
         PIN_SV3 - out RC5 - RC5 | 5    10 | RC0 - RC0 out - PIN_LED2
         PIN_SV4 - out RC4 - RC4 | 6     9 | RC1 - RC1 in^ - PIN_J_DIR
        PIN_J_A0 - in^ RC3 - RC3 | 7     8 | RC2 - RC2 in^ - PIN_J_A1
                                 +---------+                       ( ^ has WPU)
@remark The 5pin header has 3 connection purposes: ICSP, setup & operate

@TODO Setup mode

@brief Memory Summary
    Program space        used   4A1h (  1185) of   800h words   ( 57.9%)
    Data space           used    4Bh (    75) of   100h bytes   ( 29.3%)
    EEPROM space         used     8h (     8) of   100h bytes   (  3.1%)
*/

/****************************************************************************
@brief  Disable selected compiler warnings 
@remark  MCC is very lax! 
*/
#pragma warning disable 520  /* function is never called */
#pragma warning disable 1510 /* non-reentrant, so function duplicated */


/****************************************************************************
@brief Includes headers/libraries
*/
#include "main.h" /* data values. This includes mcc_generated_files/mcc.h  */


/****************************************************************************
@brief function tmr0_ISR() - PWM duty cycle maker, called every 10 us.
@remark interrupt_manager.c is modified MCC generated, for speed improvement.
@remark Foreground process, TMR0 overflow every 10us, ISR timed under 5.7us.
@param  none
@return none
*/

void tmr0_ISR(void)
{
    count10us++;
    switch( svoPhase )
    {
        case SV1:
            if( count10us >= data[SV1].cur )            /* end pulse Servo 1 */
                PIN_SV1_LAT = data[SV1].shutdownState;  /* set pin low or    */
            break;                                      /*  high if shutdown */
        case SV2:
            if( count10us >= data[SV2].cur )            /* end pulse Servo 2 */
                PIN_SV2_LAT = data[SV2].shutdownState;  /* set pin low or    */
            break;                                      /*  high if shutdown */
        case SV3:
            if( count10us >= data[SV3].cur )            /* end pulse Servo 3 */
                PIN_SV3_LAT = data[SV3].shutdownState;  /* set pin low or    */
            break;                                      /*  high if shutdown */          
        case SV4:
            if( count10us >= data[SV4].cur )            /* end pulse Servo 4 */
                PIN_SV4_LAT = data[SV4].shutdownState;  /* set pin low or    */
            break;                                      /*  high if shutdown */
        default: break;
    }
}


/****************************************************************************
@brief function tmr1_ISR() - PWM period maker, starts pulses 4 ms intervals
@remark Foreground process. ISR TMR1 overflow every 4 ms
@param  none
@return none
*/

void tmr1_ISR(void)
{
    count10us = 0; /* start new servo signal phase at 10us counter of zero */
    switch( svoPhase )
    {
        case SVCOUNT:   
            svoPhase = SV1;     /* start PWM pulse Servo 1 */
            PIN_SV1_LAT = HIGH;
            break;
        case SV1:  
            svoPhase = SV2;     /* start PWM pulse Servo 2 */
            PIN_SV2_LAT = HIGH;
            break;
        case SV2:  
            svoPhase = SV3;     /* start PWM pulse Servo 3 */
            PIN_SV3_LAT = HIGH;
            break;
        case SV3:  
            svoPhase = SV4;     /* start PWM pulse Servo 4 */
            PIN_SV4_LAT = HIGH;
            break;
        default: /* SV4 or none of the above - happens every 20 ms  */   
            svoPhase = SVCOUNT;
            tick20msFlag = true; /* flag to background process in main loop */
            if( state != DWELL )
                findServoToMove();
            break;
    }
}


/*****************************************************************************
@brief function findServoToMove() - move servos in sequence
@remark  Called every 20 ms from tmr1_ISR()
@remark Foreground process 
@param  none
@return none
*/

void findServoToMove(void)
{
    if( order43 & order21 ) /* reverse order SV4/3/2/1 */
    {
        if( isServoActive( SV4 ) ) return; 
        if( isServoActive( SV3 ) ) return; 
        if( isServoActive( SV2 ) ) return; 
        if( isServoActive( SV1 ) ) return; 
    }
    else
    {
        if( order21 )
        {                   
            if( isServoActive( SV2 ) ) return; 
            if( isServoActive( SV1 ) ) return; 
        }
        else
        {
            if( isServoActive( SV1 ) ) return; 
            if( isServoActive( SV2 ) ) return; 
        }

        if( order43 )
        {                   
            if( isServoActive( SV4 ) ) return; 
            if( isServoActive( SV3 ) ) return; 
        }
        else
        {
            if( isServoActive( SV3 ) ) return; 
            if( isServoActive( SV4 ) ) return; 
        }
    }
}


/*****************************************************************************
@brief function isServoActive() - inc or dec DC current for one servo
@remark  Called every 20 ms from processChangeOrder()
@remark Foreground process 
@param  uint8_t svo - servo channel index
@return bool - servo active true or false 
*/

bool isServoActive( uint8_t svo )
{
    if( data[svo].cur == data[svo].pw[ data[svo].targetEnd ]  )
        return false; /* servo is not active */ 
    else
    {
        data[svo].shutdownState = false; /* clear shut down state */
        
        if( data[svo].cur > data[svo].pw[ data[svo].targetEnd ] )
            data[svo].cur--;
        else
            data[svo].cur++; 

        if( data[svo].cur != data[svo].pw[ data[svo].targetEnd ] )
            state = ACTIVE; /* servo is moving */
        else
        { /* just arrived at servo end position */
            data[svo].shut20msCountDown = shutDownSetting ? SHUT20msINIT : 0;
            state = DWELL; /* start dwell period */
        }
        return true; /* servo active or dwell */
    }
} 


/****************************************************************************
@brief function processInputs()
@brief Background process
@param  none
@return none
*/

void processInputs(void)
{
        data[SV1].targetEnd = input0;
        data[SV2].targetEnd = input0;
        order21 = input0;
        if( inputsOne )
        {
            order43 = input0; /* inputs are one, so for SV3/4 use input0 */
            data[SV3].targetEnd = input0;
            data[SV4].targetEnd = input0;
        }
        else /* inputs are two, for SV3/4 use in1 */
        {
            order43 = input1;
            data[SV3].targetEnd = input1;
            data[SV4].targetEnd = input1;
        }
}


/****************************************************************************
@brief function getInputs() - called from loop()
@brief Background process
@param  none
@return none
*/

void getInputs(void)
{
    input0 = PIN_IN0_GetValue();    /* dual purpose input */
    input1 = PIN_IN1_GetValue();    /* dual purpose input */
    jumpA0 = PIN_J_A0_GetValue();   /* dual purpose jumper */
    jumpA1 = PIN_J_A1_GetValue();   /* dual purpose jumper */
    jumpDir = PIN_J_DIR_GetValue(); /* dual purpose jumper */
    
//    PIN_LED1_SetDigitalInput();      /* setup externally pulls LED1 PIN up */
//    setupMode = PIN_LED1_GetValue(); /* reads PIN as true for setup mode */
//    PIN_LED1_SetDigitalOutput();     /* restore PIN as output */
//  
//    if( setupMode )
//    {
//        shutDownSetting = false;
//        inputsOne = true;
//        svoAddr = jumpA0 & ( jumpA1 << 1 ); /* address = A0 + (A1 x 2 ) */
//        dwell20msInit = 0;
//        PIN_LED2_LAT = HIGH;
//    }
//    else /* operate mode */
    {
        shutDownSetting = jumpDir;
        inputsOne = jumpA1;
        dwell20msInit = ADC_GetConversion(PIN_POT);
        PIN_LED2_LAT = LOW;
    }
}


/****************************************************************************
@brief function actionShutdowns() - called from operateMode()
@brief Background process
@param  none
@return none
*/

void actionShutdowns(void)
{
    for( uint8_t svo = 0; svo < SVCOUNT; svo++ )
    {
        if( data[svo].shut20msCountDown > 0 ) /* shutdown is counting */
            if( --data[svo].shut20msCountDown == 0 )
                data[svo].shutdownState = shutDownSetting;
    }
}


/****************************************************************************
@brief function runSettingUpMode() - Setting up mode, called every 20ms
@brief Background process
@param  none
@return none
*/

void runSettingUpMode(void)
{
    for( uint8_t svo = 0; svo < SVCOUNT; svo++ )
        data[svo].shutdownState = false;

    dwell20msCountDown = 0;
    
    /* TBA */
}


/****************************************************************************
@brief function actionHeartBeat() - called from runOperateMode every 20ms
@brief Background process
@param  none
@return none
*/

void actionHeartBeat(void)
{
    if( heartBeat20msCountDown > 0 )
    {
        heartBeat20msCountDown--;
        PIN_LED1_LAT = LOW;
    }
    else
    {
        heartBeat20msCountDown = HB20msINIT;
        PIN_LED1_LAT = HIGH;
    }
}


/****************************************************************************
@brief function runOperateMode() - Operating mode, called every 20ms
@brief Background process
@param  none
@return none
*/

void runOperateMode(void)
{
    switch( state )
    {
        case ACTIVE :
            PIN_LED1_LAT = HIGH;
            dwell20msCountDown = dwell20msInit;
            break;
        case DWELL :
            if( dwell20msCountDown > 0 ) /* dwell period */
            {
                dwell20msCountDown--;
                PIN_LED1_LAT = ! ( (uint8_t) dwell20msCountDown & 7 ); /* dim */
            }
            else
            {
                PIN_LED1_LAT = LOW;
                state = INACTIVE;
            }
            break;
        case INACTIVE :
            actionHeartBeat();
            processInputs();
            break;
    }
    actionShutdowns();
}


/****************************************************************************
@brief function initSys() - Initialise the system - Called once from main()
@brief Startup process
@param  none
@return none
*/

void initSys(void)
{
    SYSTEM_Initialize(); /* see mcc.c */
    
    data[SV1].pw[0] = eeprom_read(0);
    data[SV1].pw[1] = eeprom_read(1);
    data[SV2].pw[0] = eeprom_read(2);
    data[SV2].pw[1] = eeprom_read(3);
    data[SV3].pw[0] = eeprom_read(4);
    data[SV3].pw[1] = eeprom_read(5);
    data[SV4].pw[0] = eeprom_read(6);
    data[SV4].pw[1] = eeprom_read(7);
    data[SV1].cur = data[SV2].cur = data[SV3].cur = data[SV4].cur = DC_MIDPOS;       
    data[SV1].shut20msCountDown = data[SV2].shut20msCountDown = 
                data[SV3].shut20msCountDown = data[SV4].shut20msCountDown = 0;
    data[SV1].shutdownState = data[SV2].shutdownState =
                data[SV3].shutdownState = data[SV4].shutdownState = true;
    
    TMR0_SetInterruptHandler( *tmr0_ISR); /* 10 us interrupt, PWM Duty Cycle */
    TMR1_SetInterruptHandler( *tmr1_ISR); /* 4 ms interrupt, PWM period */
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
}


/****************************************************************************
@brief function main() - Called on power up
@param  none
@return none
*/

void main(void)
{
    initSys();
    for(uint8_t svo = 0; svo < SVCOUNT; svo++ ) /* delay start servo signals */
    {
        data[svo].shutdownState = false;
        __delay_ms(75);
    }
    state = INACTIVE;

    while( true )
    {
        if( tick20msFlag ) /* tmr1_ISR sets flag every 20 ms */
        {
            tick20msFlag = false;

            getInputs();
            if( setupMode )
                runSettingUpMode(); 
            else 
                runOperateMode();
        }
    }
}

/**************************** End of File ***********************************/
