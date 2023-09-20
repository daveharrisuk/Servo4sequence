/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18323
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set PIN_IN0 aliases
#define PIN_IN0_TRIS                 TRISAbits.TRISA0
#define PIN_IN0_LAT                  LATAbits.LATA0
#define PIN_IN0_PORT                 PORTAbits.RA0
#define PIN_IN0_WPU                  WPUAbits.WPUA0
#define PIN_IN0_OD                   ODCONAbits.ODCA0
#define PIN_IN0_ANS                  ANSELAbits.ANSA0
#define PIN_IN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define PIN_IN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define PIN_IN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define PIN_IN0_GetValue()           PORTAbits.RA0
#define PIN_IN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define PIN_IN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define PIN_IN0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define PIN_IN0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define PIN_IN0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define PIN_IN0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define PIN_IN0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define PIN_IN0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set PIN_LED1 aliases
#define PIN_LED1_TRIS                 TRISAbits.TRISA1
#define PIN_LED1_LAT                  LATAbits.LATA1
#define PIN_LED1_PORT                 PORTAbits.RA1
#define PIN_LED1_WPU                  WPUAbits.WPUA1
#define PIN_LED1_OD                   ODCONAbits.ODCA1
#define PIN_LED1_ANS                  ANSELAbits.ANSA1
#define PIN_LED1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define PIN_LED1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define PIN_LED1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define PIN_LED1_GetValue()           PORTAbits.RA1
#define PIN_LED1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define PIN_LED1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define PIN_LED1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define PIN_LED1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define PIN_LED1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define PIN_LED1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define PIN_LED1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define PIN_LED1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set PIN_POT aliases
#define PIN_POT_TRIS                 TRISAbits.TRISA2
#define PIN_POT_LAT                  LATAbits.LATA2
#define PIN_POT_PORT                 PORTAbits.RA2
#define PIN_POT_WPU                  WPUAbits.WPUA2
#define PIN_POT_OD                   ODCONAbits.ODCA2
#define PIN_POT_ANS                  ANSELAbits.ANSA2
#define PIN_POT_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define PIN_POT_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define PIN_POT_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define PIN_POT_GetValue()           PORTAbits.RA2
#define PIN_POT_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define PIN_POT_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define PIN_POT_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define PIN_POT_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define PIN_POT_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define PIN_POT_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define PIN_POT_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define PIN_POT_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set PIN_IN1 aliases
#define PIN_IN1_PORT                 PORTAbits.RA3
#define PIN_IN1_WPU                  WPUAbits.WPUA3
#define PIN_IN1_GetValue()           PORTAbits.RA3
#define PIN_IN1_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define PIN_IN1_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)

// get/set PIN_SV2 aliases
#define PIN_SV2_TRIS                 TRISAbits.TRISA4
#define PIN_SV2_LAT                  LATAbits.LATA4
#define PIN_SV2_PORT                 PORTAbits.RA4
#define PIN_SV2_WPU                  WPUAbits.WPUA4
#define PIN_SV2_OD                   ODCONAbits.ODCA4
#define PIN_SV2_ANS                  ANSELAbits.ANSA4
#define PIN_SV2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define PIN_SV2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define PIN_SV2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define PIN_SV2_GetValue()           PORTAbits.RA4
#define PIN_SV2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define PIN_SV2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define PIN_SV2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define PIN_SV2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define PIN_SV2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define PIN_SV2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define PIN_SV2_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define PIN_SV2_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set PIN_SV1 aliases
#define PIN_SV1_TRIS                 TRISAbits.TRISA5
#define PIN_SV1_LAT                  LATAbits.LATA5
#define PIN_SV1_PORT                 PORTAbits.RA5
#define PIN_SV1_WPU                  WPUAbits.WPUA5
#define PIN_SV1_OD                   ODCONAbits.ODCA5
#define PIN_SV1_ANS                  ANSELAbits.ANSA5
#define PIN_SV1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define PIN_SV1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define PIN_SV1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define PIN_SV1_GetValue()           PORTAbits.RA5
#define PIN_SV1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define PIN_SV1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define PIN_SV1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define PIN_SV1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define PIN_SV1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define PIN_SV1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define PIN_SV1_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define PIN_SV1_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set PIN_LED2 aliases
#define PIN_LED2_TRIS                 TRISCbits.TRISC0
#define PIN_LED2_LAT                  LATCbits.LATC0
#define PIN_LED2_PORT                 PORTCbits.RC0
#define PIN_LED2_WPU                  WPUCbits.WPUC0
#define PIN_LED2_OD                   ODCONCbits.ODCC0
#define PIN_LED2_ANS                  ANSELCbits.ANSC0
#define PIN_LED2_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define PIN_LED2_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define PIN_LED2_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define PIN_LED2_GetValue()           PORTCbits.RC0
#define PIN_LED2_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define PIN_LED2_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define PIN_LED2_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define PIN_LED2_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define PIN_LED2_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define PIN_LED2_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define PIN_LED2_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define PIN_LED2_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set PIN_J_DIR aliases
#define PIN_J_DIR_TRIS                 TRISCbits.TRISC1
#define PIN_J_DIR_LAT                  LATCbits.LATC1
#define PIN_J_DIR_PORT                 PORTCbits.RC1
#define PIN_J_DIR_WPU                  WPUCbits.WPUC1
#define PIN_J_DIR_OD                   ODCONCbits.ODCC1
#define PIN_J_DIR_ANS                  ANSELCbits.ANSC1
#define PIN_J_DIR_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define PIN_J_DIR_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define PIN_J_DIR_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define PIN_J_DIR_GetValue()           PORTCbits.RC1
#define PIN_J_DIR_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define PIN_J_DIR_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define PIN_J_DIR_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define PIN_J_DIR_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define PIN_J_DIR_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define PIN_J_DIR_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define PIN_J_DIR_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define PIN_J_DIR_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set PIN_J_A1 aliases
#define PIN_J_A1_TRIS                 TRISCbits.TRISC2
#define PIN_J_A1_LAT                  LATCbits.LATC2
#define PIN_J_A1_PORT                 PORTCbits.RC2
#define PIN_J_A1_WPU                  WPUCbits.WPUC2
#define PIN_J_A1_OD                   ODCONCbits.ODCC2
#define PIN_J_A1_ANS                  ANSELCbits.ANSC2
#define PIN_J_A1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define PIN_J_A1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define PIN_J_A1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define PIN_J_A1_GetValue()           PORTCbits.RC2
#define PIN_J_A1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define PIN_J_A1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define PIN_J_A1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define PIN_J_A1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define PIN_J_A1_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define PIN_J_A1_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define PIN_J_A1_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define PIN_J_A1_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set PIN_J_A0 aliases
#define PIN_J_A0_TRIS                 TRISCbits.TRISC3
#define PIN_J_A0_LAT                  LATCbits.LATC3
#define PIN_J_A0_PORT                 PORTCbits.RC3
#define PIN_J_A0_WPU                  WPUCbits.WPUC3
#define PIN_J_A0_OD                   ODCONCbits.ODCC3
#define PIN_J_A0_ANS                  ANSELCbits.ANSC3
#define PIN_J_A0_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define PIN_J_A0_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define PIN_J_A0_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define PIN_J_A0_GetValue()           PORTCbits.RC3
#define PIN_J_A0_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define PIN_J_A0_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define PIN_J_A0_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define PIN_J_A0_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define PIN_J_A0_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define PIN_J_A0_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define PIN_J_A0_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define PIN_J_A0_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set PIN_SV4 aliases
#define PIN_SV4_TRIS                 TRISCbits.TRISC4
#define PIN_SV4_LAT                  LATCbits.LATC4
#define PIN_SV4_PORT                 PORTCbits.RC4
#define PIN_SV4_WPU                  WPUCbits.WPUC4
#define PIN_SV4_OD                   ODCONCbits.ODCC4
#define PIN_SV4_ANS                  ANSELCbits.ANSC4
#define PIN_SV4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define PIN_SV4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define PIN_SV4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define PIN_SV4_GetValue()           PORTCbits.RC4
#define PIN_SV4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define PIN_SV4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define PIN_SV4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define PIN_SV4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define PIN_SV4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define PIN_SV4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define PIN_SV4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define PIN_SV4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set PIN_SV3 aliases
#define PIN_SV3_TRIS                 TRISCbits.TRISC5
#define PIN_SV3_LAT                  LATCbits.LATC5
#define PIN_SV3_PORT                 PORTCbits.RC5
#define PIN_SV3_WPU                  WPUCbits.WPUC5
#define PIN_SV3_OD                   ODCONCbits.ODCC5
#define PIN_SV3_ANS                  ANSELCbits.ANSC5
#define PIN_SV3_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define PIN_SV3_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define PIN_SV3_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define PIN_SV3_GetValue()           PORTCbits.RC5
#define PIN_SV3_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define PIN_SV3_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define PIN_SV3_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define PIN_SV3_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define PIN_SV3_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define PIN_SV3_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define PIN_SV3_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define PIN_SV3_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/