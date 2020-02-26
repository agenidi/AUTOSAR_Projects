/*
 * DoorSensor.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef ECUAL_DOORSENSOR_H_
#define ECUAL_DOORSENSOR_H_

Error_Status DoorSensor_Init(void);
Error_Status DoorSensor_ReadStatus(uint8_t Sensor_Ch, uint8_t*state);

#define DOORSENSOR1_PIN          0
#define DOORSENSOR1_PORT        PORTF
#define DOORSENSOR1_PORT_CLOCK  GPIOF
#define DOORSENSOR2_PORT_CLOCK  GPIOF
#define DOORSENSOR1_PIN_MODE   IN_PULLUP

#define DOORSENSOR2_PIN    4
#define DOORSENSOR2_PORT    PORTF
#define DOORSENSOR2_PIN_MODE   IN_PULLUP

#define LEFTSENSOR   1
#define RIGHTSENSOR  2

#endif /* ECUAL_DOORSENSOR_H_ */
