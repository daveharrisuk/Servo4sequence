/**@headerfile configuration.h        PROJECT_NAME Servo4sequencer
@brief Servo configuration data
@author ©2023 Dave Harris, Andover, UK.  (MERG member 'WortingUK')
@copyright Creative Commons BY-NC-SA (Attribution-NonCommercial-ShareAlike)
@version 1.0
@history 10-JUL-2023 DH started
*/
#pragma once /* header include guard */

#define DC_MIDPOS   150 /* 1.5 ms mid position at 10us intervals */
                        /* MINPOS = 50 = 0.5 ms,  MAXPOS = 250 = 2.5 ms */

/* define servo data written to EEPROM */

#define SV1P0   DC_MIDPOS-24    /* servo 1, end position 0 */
#define SV1P1   DC_MIDPOS+35    /* servo 1, end position 1 */

#define SV2P0   DC_MIDPOS+38    /* servo 2, end position 0 */
#define SV2P1   DC_MIDPOS-26    /* servo 2, end position 1 */

#define SV3P0   DC_MIDPOS-33    /* servo 3, end position 0 */
#define SV3P1   DC_MIDPOS+30    /* servo 3, end position 1 */

#define SV4P0   DC_MIDPOS+33    /* servo 4, end position 0 */
#define SV4P1   DC_MIDPOS-36    /* servo 4, end position 1 */


/* store in EEPROM */
__EEPROM_DATA (SV1P0, SV1P1, SV2P0, SV2P1, SV3P0, SV3P1, SV4P0, SV4P1);

//__EEPROM_DATA (DC_MIDPOS, DC_MIDPOS, DC_MIDPOS, DC_MIDPOS, 0, 0, 0, 0);

/* EEPROM address enums */
enum{ Ea1P0 = 0, Ea1P1, Ea2P0, Ea2P1, Ea3P0, Ea3P1, Ea4P0, Ea4P1,
      Ea1CU = 8, Ea2CU, Ea3CU, Ea4CU  };

/**************************end of file***************************************/
