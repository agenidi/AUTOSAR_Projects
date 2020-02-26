/*
 * Lamp.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

ErrorStd Lamp_Init(void)
{
	u8 Local_Error=GPIO_Init(LAMP_PORT,LAMP_PIN,LAMP_PIN_MODE);
	
	return Local_Error;
}

ErrorStd Lamp_Update(uint8_t Lamp_Ch,uint8_t State)
{
	u8 Local_Error;
	if(Lamp_Ch==LAMP1)
	{
		if(State==ON)
			GPIO_Write(LAMP_PORT,LAMP_PIN,HIGH);
		else if(State==OFF)
			GPIO_Write(LAMP_PORT,LAMP_PIN,LOW);
		Local_Error=OK;
	}
	else{
		Local_Error=NOK;
	}
	return Local_Error;
}




