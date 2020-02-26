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
	Error_Status Error = E_Ok;
	Error = Lamp_Init();
	return Error;
}

Error_Status Lighting_Control(void)
{
	Error_Status Error = E_Ok;
	u8 LampState = 0;
	
	if(LampState == LIGHT_ON || LampState == LIGHT_OFF)
		Error = Lamp_Update(Lamp_ch, LampState);
	else
		Error = E_Nok
	
	return Error
	
}


#endif /* APP_LIGHTING_C_ */







