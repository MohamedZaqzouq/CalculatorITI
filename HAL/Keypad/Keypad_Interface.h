/*
 * Keypad_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

/*============================================================================================*/
/*   INCLUDES   */
/*============================================================================================*/
#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>
/*============================================================================================*/
/*   SELECT MICROCONTROLERS PINS   */
/*============================================================================================*/
#define KEYPAD_R0_PIN            PC5_PIN
#define KEYPAD_R1_PIN            PC4_PIN
#define KEYPAD_R2_PIN            PC3_PIN
#define KEYPAD_R3_PIN            PC2_PIN

#define KEYPAD_C0_PIN            PD7_PIN
#define KEYPAD_C1_PIN            PD6_PIN
#define KEYPAD_C2_PIN            PD5_PIN
#define KEYPAD_C3_PIN            PD3_PIN

/*============================================================================================*/
/*   SELECT KEYPAD_DEBOUNCING_TIME IN MILLI SECOND   */
/*============================================================================================*/
#define KEYPAD_DEBOUNCING_TIME   30


/*============================================================================================*/
#define KEYPAD_MODEL             KEYPAD_MODEL_B
/*============================================================================================*/
/*   DEFINES   */
/*============================================================================================*/
#define KEYPAD_PRESSED                 0
#define KEYPAD_RELEASED                1
#define KEYPAD_MODEL_A       1
#define KEYPAD_MODEL_B       2
/*============================================================================================*/
/*   PROTOTYPES   */
/*============================================================================================*/
void H_KeyPad_Void_KeyPadInit(void);
u8   H_KeyPad_U8_KeyPadRead(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
