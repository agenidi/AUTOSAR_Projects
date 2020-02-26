/*
 * Lighting.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef APP_LIGHTING_C_
#define APP_LIGHTING_C_

#include "LIB/Std_lib.h"

#include "ECUAL/Lamp.h"
#include "Lighting.h"


Error_Status Lighting_init(void)
{
	Error_Status Local_Error= OK;
	Local_Error = Lamp_Init();
	
	return Local_Error;
}

Error_Status Lighting_Control(uint8_t LampState)
{
	Error_Status Local_Error= OK;
	

	if(LampState == LIGHT_ON || LampState == LIGHT_OFF)
		Local_Error = Lamp_Update(Lamp_ch, LampState);
	else
		Local_Error=NOK;
	
	return Local_Error;
	
}


#endif /* APP_LIGHTING_C_ */







