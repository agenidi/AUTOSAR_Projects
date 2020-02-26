/*
 * DoorSensor.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef ECUAL_DOORSENSOR_H_
#define ECUAL_DOORSENSOR_H_

ErrorStd DoorSensor_Init(void);
 ErrorStd DoorSensor_ReadStatus(u8 Sensor_Ch,u8*state);

#define DOORSENSOR1_PIN    PIN0
#define DOORSENSOR1_PORT    'A'
#define DOORSENSOR1_PIN_MODE   

#define DOORSENSOR2_PIN    PIN1
#define DOORSENSOR2_PORT    'A'
#define DOORSENSOR2_PIN_MODE   

#define LEFTSENSOR   1
#define RIGHTSENSOR  2

#endif /* ECUAL_DOORSENSOR_H_ */
