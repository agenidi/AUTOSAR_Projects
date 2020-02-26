/*
 * DoorSensor.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */
 
 
 Error_Status DoorSensor_Init(void)
 {
	Error_Status Local_Error;
	Error_Status Sensor1_State,Sensor2_State ;
	Sensor1_State=GPIO_Init(DOORSENSOR1_PORT,DOORSENSOR1_PIN,DOORSENSOR1_PIN_MODE);
	Sensor2_State=GPIO_Init(DOORSENSOR2_PORT,DOORSENSOR2_PIN,DOORSENSOR2_PIN_MODE);
	if(Sensor1_State==OK && Sensor2_State==OK)
	{
		Local_Error=OK;
	}
	else{
		Local_Error=NOK;
	}
	return Local_Error;
 }
 
 Error_Status DoorSensor_ReadStatus(uint8_t Sensor_Ch,uint8_t*State)
 {
	if(Sensor_Ch <= 2)
	{ Error_Status Local_Error= OK;
	
		if(Sensor_Ch==LEFTSENSOR)
		{
			Local_Error =GPIO_ReadPin(DOORSENSOR1_PORT,DOORSENSOR1_PIN,&State);
		}
		else if(Sensor_Ch==RIGHTSENSOR)
		{
			Local_Error =GPIO_ReadPin(DOORSENSOR2_PORT,DOORSENSOR2_PIN,&State);
		}
	}
	else
	{
		Local_Error=NOK:
	}
	}
 }




