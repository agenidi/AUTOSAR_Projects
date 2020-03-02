/************************************************************************
 * File name: DoorSensor.c
 *
 *
 * Description: This file contains the functions implementation of the DoorSensor driver
 * used by the user
 *
 * owner: Hammam Mazen
 * date: 27/2/2020
 * version 1.1
 *
 ***************************************************************************/
 
 /***************************INCLUDES***************************************/
 
#include "LIB/Std_lib.h"
#include "MCAL/GPIO.h"
#include "MCAL/RRC.h"
#include "DoorSensor.h"

/***************************************************************************/
Error_Status DoorSensor_Init(void)
{
    Error_Status Local_Error;
    Error_Status Sensor1_State, Sensor2_State;
    if (RRC_EnablePreph(DOORSENSOR1_PORT_CLOCK) == OK)
    {
        Sensor1_State = GPIO_Init(DOORSENSOR1_PORT, DOORSENSOR1_PIN,
        DOORSENSOR1_PIN_MODE);
    }
    else
    {
        Sensor1_State = NOK;
    }
    if (RRC_EnablePreph(DOORSENSOR2_PORT_CLOCK) == OK)
    {
        Sensor2_State = GPIO_Init(DOORSENSOR2_PORT, DOORSENSOR2_PIN,
        DOORSENSOR2_PIN_MODE);
    }
    else
    {
        Sensor1_State = NOK;
    }

    if (Sensor1_State == OK && Sensor2_State == OK)
    {
        Local_Error = OK;
    }
    else
    {
        Local_Error = NOK;
    }
    return Local_Error;
}

Error_Status DoorSensor_ReadStatus(uint8_t Sensor_Ch, uint8_t*State)
{
    Error_Status Local_Error = OK;
    if (Sensor_Ch <= 2)
    {

        if (Sensor_Ch == LEFTSENSOR)
        {
            Local_Error = GPIO_ReadPin(DOORSENSOR1_PORT, DOORSENSOR1_PIN,
                                       State);
        }
        else if (Sensor_Ch == RIGHTSENSOR)
        {
            Local_Error = GPIO_ReadPin(DOORSENSOR2_PORT, DOORSENSOR2_PIN,
                                       State);
        }
    }
    else
    {
        Local_Error = NOK;
    }
    return Local_Error;
}

