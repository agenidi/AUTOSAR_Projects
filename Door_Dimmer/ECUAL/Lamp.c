/************************************************************************
 * File name: Lamp.c
 *
 *
 * Description: This file contains the implementation of Lamp driver Functions
 * used by the user
 *
 * owner: Hammam Mazen
 * date: 27/2/2020
 * version 1.1
 *
 ***************************************************************************/
 
 /********************************INCLUDES**********************************/
 
#include "LIB/Std_lib.h"
#include "MCAL/GPIO.h"
#include "MCAL/RRC.h"
#include "Lamp.h"

/***************************************************************************/

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




