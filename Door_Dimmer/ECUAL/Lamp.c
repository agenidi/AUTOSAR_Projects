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

ErrorStd Lamp_Update(u8 Lamp_Ch,u8 State)
{
	u8 Local_Error;
	if(Lamp_Ch==LAMP1)
	{
		GPIO_Write(LAMP_PORT,LAMP_PIN,State);
		Local_Error=OK;
	}
	else{
		Local_Error=NOK;
	}
	return Local_Error;
}



