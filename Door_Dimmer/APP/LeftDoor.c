/*
 * LeftDoor.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef APP_LEFTDOOR_C_
#define APP_LEFTDOOR_C_

#include "LIB/Std_lib.h"
#include "LeftDoor.h"


Error_Status LeftDoor_init(void)
{
	 Error_Status Local_Error= OK;
	Local_Error = DoorSensor_Init();
	return Local_Error;
}

Error_Status LeftDoor_GetStatus(uint8_t *DoorStatus)
{
    Error_Status Local_Error= OK;
	
	
	Local_Error = DoorSensor_ReadStatus(LEFTSENSOR, DoorStatus);
	return Local_Error;
	
}



#endif /* APP_LEFTDOOR_C_ */
