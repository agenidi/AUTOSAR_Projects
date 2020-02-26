/*
 * LeftDoor.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef APP_LEFTDOOR_C_
#define APP_LEFTDOOR_C_

#include "Std_lib.h"
#include "LeftDoor.h"


Error_Status LeftDoor_init(void)
{
	 u8 Local_Error= OK;
	Local_Error = DoorSensor_Init();
	return Local_Error;
}

Error_Status LeftDoor_GetStatus(u8 *DoorStatus)
{
	 u8 Local_Error= OK;
	
	u8 State=0;
	
	Local_Error = DoorSensor_ReadStatus(LEFTSENSOR, &State);
	*Doorstatus = State;
	return Local_Error;
	
}



#endif /* APP_LEFTDOOR_C_ */
