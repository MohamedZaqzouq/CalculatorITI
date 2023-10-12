#include "Projects_Interface.h"
#include "math.h";

int main()
{
	u8 ret=0;                                      // KEYPAD CHARACTER RECEIVER VARIABLE TO RECEIVE KEYPAD CHARACTER
	u8 infix_index=0;                              // to increment the index of the infix array to put the input expression
	u8 lcd_postfix_pos=0;                          // to increment lcd colum position while Printing the expression value
    u8 lcd_infix_pos=0;                            // to increment lcd colum position while adding the expression
    u8 f=0;

    f32 result ;
	H_KeyPad_Void_KeyPadInit(); // KEYPAD INTIALIZING
	H_Lcd_Void_LCDInit();       // LCD INTIALIZING




	H_Lcd_Void_LCDClear();                         // CLEAR LCD INITIALY
	H_Lcd_Void_LCDGoTo(0, 1);
	H_Lcd_Void_LCDWriteString(" ");            // INFIX EXPRESSION ON LCD
	H_Lcd_Void_LCDGoTo(1, 1);

	H_Lcd_Void_LCDWriteString("Result:");       // THE EXPRESSION VALUE ON LCD


	while(1){

		ret=H_KeyPad_U8_KeyPadRead();

		if(ret=='1'||ret=='2'||ret=='3'||ret=='4'||ret=='5'||   // IF FUNCTION TO CHECK USER INPUTS
				     ret=='6'||ret=='7'||ret=='8'||ret=='9'||
				     ret=='*'||ret=='/'||ret=='+'||ret=='-'||
					 ret=='.'||ret=='0')
		{
			H_Lcd_Void_LCDGoTo(0, lcd_infix_pos);
			lcd_infix_pos++;
			if(ret=='*'||ret=='/'||ret=='+'||ret=='-')  // IF FUNCTION TO CHECK IF OPERATOR IS ENTERD
			{
				H_Lcd_Void_LCDWriteCharacter(ret);
				infix[infix_index++]=ret;
				infix[infix_index++]=' ';
			}
			else
			{
				infix[infix_index++]=ret;
				H_Lcd_Void_LCDWriteCharacter(ret);
			}
		}

		else if(ret=='=')                // INCASE THE USER END THE EXPRESSION AND WANT THE RESULT
		{

			lcd_postfix_pos++;
			s8* postfix = infixToPostfix(infix);

			if(f==0){


			H_Lcd_Void_LCDGoTo(1, 8);
			result=evaluatePostfix(postfix);


			LCD_Write_float(result);


			}
			else{H_Lcd_Void_LCDClear();                         // CLEAR LCD INITIALY
			H_Lcd_Void_LCDGoTo(0, 1);
			H_Lcd_Void_LCDWriteString(" ");            // INFIX EXPRESSION ON LCD
			H_Lcd_Void_LCDGoTo(1, 1);

			H_Lcd_Void_LCDWriteString("Result:");            // THE EXPRESSION VALUE ON LCD
			ret=0;  // KEYPAD CHARACTER RECEIVER VARIABLE TO RECEIVE KEYPAD CHARACTER

			result=0;
			infix_index=0;                              // to increment the index of the infix array to put the input expression
				 lcd_postfix_pos=0;                          // to increment lcd colum position while Printing the expression value
			    lcd_infix_pos=0;                            // to increment lcd colum position while adding the expression
			    f=0;
			    continue;
			}
			f++;
		}
		else
		{

		}

	}


	return 0;
}
