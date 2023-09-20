# Servo4sequence
Operate 4 servo sequentially and only 1 at a time.

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
