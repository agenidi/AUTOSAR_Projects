/*
 * RightDoor.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */


#include "LIB/Std_lib.h"
#include "RightDoor.h"




Error_Status RightDoor_init(void)
{
	Error_Status Local_Error= OK;
	Local_Error = DoorSensor_Init();
	return Local_Error;
}

Error_Status RighttDoor_GetStatus(uint8_t *DoorStatus)
{
	Error_Status Local_Error= OK;
	
	uint8_t State=0;
	
	Local_Error = DoorSensor_ReadStatus(RIGHTSENSOR, &State);
	*DoorStatus = State;
	
	return Local_Error;
	
}






