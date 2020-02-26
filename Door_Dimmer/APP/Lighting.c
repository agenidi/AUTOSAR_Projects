/*
 * Lighting.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef APP_LIGHTING_C_
#define APP_LIGHTING_C_

#include "Lighting.h"

Error_Status Lighting_init(void)
{
	u8 Local_Error= OK;
	Local_Error = Lamp_Init();
	
	return Local_Error;
}

Error_Status Lighting_Control(void)
{
	u8 Local_Error= OK;
	u8 LampState = 0;
	
	if(LampState == LIGHT_ON || LampState == LIGHT_OFF)
		Local_Error = Lamp_Update(Lamp_ch, LampState);
	else
		Local_Error=NOK;
	
	return Local_Error
	
}


#endif /* APP_LIGHTING_C_ */







