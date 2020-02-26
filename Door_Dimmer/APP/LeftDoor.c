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
	Error_Status Error = E_Ok;
	Error = DoorSensor_Init();
	return Error;
}

Error_Status LeftDoor_GetStatus(u8 *DoorStatus)
{
	Error_Status error = E_ok;
	
	u8 State=0;
	
	Error = DoorSensor_ReadStatus(LEFTSENSOR, &State);
	*Doorstatus = State;
	return Error;
	
}



#endif /* APP_LEFTDOOR_C_ */
