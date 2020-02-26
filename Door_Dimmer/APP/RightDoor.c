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
	u8 Local_Error= OK;
	Local_Error = DoorSensor_Init();
	return Local_Error;
}

Error_Status RighttDoor_GetStatus(u8 *DoorStatus)
{
	u8 Local_Error= OK;
	
	u8 State=0;
	
	Local_Error = DoorSensor_ReadStatus(RIGHTSENSOR, &State);
	*Doorstatus = State;
	
	return Local_Error;
	
}






