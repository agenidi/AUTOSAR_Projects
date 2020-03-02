/************************************************************************
 * File name: DoorSensor.h
 *
 *
 * Description: This file contains the prototypes of the DoorSensor driver
 * and the macros used by the user
 *
 * owner: Hammam Mazen
 * date: 27/2/2020
 * version 1.1
 *
 ***************************************************************************/

#ifndef ECUAL_DOORSENSOR_H_
#define ECUAL_DOORSENSOR_H_

/************************************************************************
 * Function name: DoorSensor_Init
 *
 * parameters:  
 *              Input: void
 *              Output: NA
 *              In/out: NA
 * return: OK, NOK
 * Description: a function to initialize the door sensor .
 ***************************************************************************/
 
Error_Status DoorSensor_Init(void);

/************************************************************************
 * Function name: DoorSensor_ReadStatus
 *
 * parameters:  Input:
 *                 Sensor_Ch
 *                     type: uint8_t
                       Description: Sensor Channel (LEFTSENSOR, RIGTHSENSOR)
 *                 State
 *                     type: uint8_t*
 *                     Description: Sensor Status (PRESSED,RELEASED)
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to Get status of Door sensor
 ***************************************************************************/
 
Error_Status DoorSensor_ReadStatus(uint8_t Sensor_Ch, uint8_t*state);

/*Sensor1 Configurations*/
#define DOORSENSOR1_PIN          0
#define DOORSENSOR1_PORT        PORTF
#define DOORSENSOR1_PORT_CLOCK  GPIOF
#define DOORSENSOR1_PIN_MODE   IN_PULLUP

/*Sensor2 Configurations*/
#define DOORSENSOR2_PIN    4
#define DOORSENSOR2_PORT    PORTF
#define DOORSENSOR2_PORT_CLOCK  GPIOF
#define DOORSENSOR2_PIN_MODE   IN_PULLUP

/*Sensor Channels*/
#define LEFTSENSOR   1
#define RIGHTSENSOR  2

#endif /* ECUAL_DOORSENSOR_H_ */
