/*
 * LDR_Config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
#include "../../STD.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>
/*--------------------------------------------------------------------------------------------*/
/*   SELECT MICROCONTROLERS PINS   */
/*--------------------------------------------------------------------------------------------*/
#define LCD_D0_PIN                PA0_PIN
#define LCD_D1_PIN                PA1_PIN
#define LCD_D2_PIN                PA2_PIN
#define LCD_D3_PIN                PA3_PIN
#define LCD_D4_PIN                PA4_PIN
#define LCD_D5_PIN                PA5_PIN
#define LCD_D6_PIN                PA6_PIN
#define LCD_D7_PIN                PA7_PIN
#define LCD_RS_PIN                PB0_PIN
#define LCD_EN_PIN                PB1_PIN
#define _8_BIT_MODE                   8
#define LCD_8_BIT_MODE_COMMAND        0x38
#define LCD_DISPLAY_ON_COMMAND        0x0C
#define LCD_RETURN_HOME_COMMAND       0x02
#define LCD_CLEAR                     0x01
#define LCD_R0_COMMAND                0x80
#define LCD_R1_COMMAND                0xC0
#define LCD_R2_COMMAND                0x94
#define LCD_R3_COMMAND                0xD4
#define NULL                          '\0'


/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_Lcd_Void_LCDInit(void);
void H_Lcd_Void_LCDWriteCharacter(u8);
void H_Lcd_Void_LCDWriteCommand(u8);
void H_Lcd_Void_LCDWriteString(u8*);
void H_Lcd_Void_LCDClear(void);
void H_Lcd_Void_LCDWriteNumber(s32);
void H_Lcd_Void_LCDGoTo(u8,u8);
void LCD_Write_float(f32 n);

#define LCD_MODE           _8_BIT_MODE

#endif /* HAL_LCD_LCD_CONFIG_H_ */
