/*
 * Lamp.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */
#include "LIB/Std_lib.h"
#include "MCAL/GPIO.h"
#include "MCAL/RRC.h"
#include "Lamp.h"
Error_Status Lamp_Init(void)
{
    Error_Status Local_Error;
	Local_Error=RRC_EnablePreph(LAMP_PORT);
    Local_Error=GPIO_Init(LAMP_PORT,LAMP_PIN,LAMP_PIN_MODE);
	
	return Local_Error;
}

Error_Status Lamp_Update(uint8_t Lamp_Ch,uint8_t State)
{
	Error_Status Local_Error;
	if(Lamp_Ch==LAMP1)
	{
		if(State==ON)
		    GPIO_WritePin(LAMP_PORT,LAMP_PIN,HIGH);
		else if(State==OFF)
		    GPIO_WritePin(LAMP_PORT,LAMP_PIN,LOW);
		Local_Error=OK;
	}
	else{
		Local_Error=NOK;
	}
	return Local_Error;
}




