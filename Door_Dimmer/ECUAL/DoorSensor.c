/*
 * DoorSensor.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */
 
 
 ErrorStd DoorSensor_Init(void)
 {
	u8 Local_Error = OK;
	GPIO_Init(DOORSENSOR1_PORT,DOORSENSOR1_PIN,DOORSENSOR1_PIN_MODE);
	GPIO_Init(DOORSENSOR2_PORT,DOORSENSOR2_PIN,DOORSENSOR2_PIN_MODE);
	return Local_Error;
 }
 
 ErrorStd DoorSensor_ReadStatus(u8 Sensor_Ch,u8*State)
 {
	if(Sensor_Ch <= 2)
	{ u8 Local_Error= OK;
		if(Sensor_Ch==LEFTSENSOR)
		{
			*State =GPIO_ReadPin(DOORSENSOR1_PORT,DOORSENSOR1_PIN)
		}
		else if(Sensor_Ch==RIGHTSENSOR)
		{
			*State =GPIO_ReadPin(DOORSENSOR2_PORT,DOORSENSOR2_PIN)
		}
	}
	else
	{
		Local_Error=NOK:
	}
	}
 }




