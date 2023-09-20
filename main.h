/**@headerfile main.h        PROJECT_NAME Servo4sequencer
*****************************************************************************
@brief  header file for main.c

@author ©2023 Dave Harris, Andover, UK.  (MERG member 'WortingUK')
@copyright Creative Commons BY-NC-SA (Attribution-NonCommercial-ShareAlike)

@version 0.1
@history 10-JUL-2023 DH started

*/
#pragma once /* header include guard */

/****************************************************************************
@brief include/libraries
*/

#include "mcc_generated_files/mcc.h" /* MPLABX Code Configurator generated */



#include "configuration.h"  /* user servo configuration data  */


/****************************************************************************
@brief enumerators
*/

enum index_t { SV1 = 0, SV2, SV3, SV4, SVCOUNT };  /* servos index */

enum state_t { ACTIVE, DWELL, INACTIVE };

/****************************************************************************
@brief structures
*/

struct data_t
{
    uint8_t pw[2];              /* end point pulse width */
    uint8_t cur;                /* current pulse width   */
    uint8_t shut20msCountDown;  /* countdown to servo signal shut off */
    bool targetEnd;             /* target end of duty cycle change    */
    bool shutdownState;         /* tell ISR to shut down servo signal */
};


/****************************************************************************
@brief Global variables
   communication between foreground ISR code and background code
*/

volatile struct data_t data[SVCOUNT]; /* servo data array */

volatile uint8_t count10us = 0;   /* increments pulse width every 10us  */
        /* 150x10us =1.50ms mid pos pulse - limits: 50 =0.5ms to 250 =2.5 ms */

volatile enum index_t svoPhase = SVCOUNT; /* PWM generation slot */

volatile bool tick20msFlag = false; /* flag to awake background process */

volatile uint16_t dwell20msCountDown = 1; /* 10bit AD = 0 to 20.5 seconds */

uint16_t dwell20msInit; /* set from ADC read pot read */ 

bool order21 = false; /* true is reverse order of 1/2 */

bool order43 = false; /* true is reverse order of 3/4 */

bool shutDownSetting = false;

volatile enum state_t state = DWELL; /* ACTIVE, DWELL or INACTIVE */

bool input0 = false;
bool input1 = false;
bool inputsOne = false; /* true is inputs two */
bool jumpA0 = false;
bool jumpA1 = false;
bool jumpDir = false;

bool setupMode = false;

uint8_t svoAddr = 0; /* address = A0 + (A1 x 2 ) */

const uint8_t HB20msINIT = 100;

uint8_t heartBeat20msCountDown = 100;

const uint8_t SHUT20msINIT = 50; /* 1 second servo shut down if JDIR is hi */


/****************************************************************************
@brief function prototypes
*/

/* background process */

void main(void);    /* Power up code - main loop - background process */

void initSys(void); /* main Initialise code */

void runSettingUpMode(void);

void runOperateMode(void);

void actionShutdowns(void);

void processInputs(void);

void getInputs(void); /* true if setup mode */

void actionHeartBeat(void);

/* foreground process */

void tmr0_ISR(void);    /* PWM duty cycle, on TMR0 overflow every 10 us */

void tmr1_ISR(void);    /* PWM period, on TMR1 overflow every 4 ms */

bool isServoActive( uint8_t );  /* process one servo */

void findServoToMove(void);  /* order all servo movements */


/**************************** End of File **********************************/
