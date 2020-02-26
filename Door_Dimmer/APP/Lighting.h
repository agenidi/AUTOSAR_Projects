/*
 * Lighting.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef APP_LIGHTING_H_
#define APP_LIGHTING_H_


#define LIGHT_ON	1
#define LIGHT_OFF	0

#define Lamp_ch		1

Error_Status Lighting_init(void);
Error_Status Lighting_Control(uint8_t LampState);


#endif /* APP_LIGHTING_H_ */

