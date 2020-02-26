/*
 * RightDoor.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */


#include "Std_lib.h"
#include "RightDoor.h"




Error_Status RightDoor_init(void)
{
	Error_Status Error = E_Ok;
	Error = DoorSensor_Init();
	return Error;
}

Error_Status RighttDoor_GetStatus(u8 *DoorStatus)
{
	Error_Status error = E_ok;
	
	u8 State=0;
	
	Error = DoorSensor_ReadStatus(RIGHTSENSOR, &State);
	*Doorstatus = State;
	
	return Error;
	
}






