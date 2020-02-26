/*
 * Lamp.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef ECUAL_LAMP_H_
#define ECUAL_LAMP_H_

Error_Status Lamp_Init(void);
Error_Status Lamp_Update(uint8_t Lamp_Ch, uint8_t State);

#define LAMP_PIN    1
#define LAMP_PORT   PORTF
#define LAMP_PORT_CLOCK GPIOF
#define LAMP_PIN_MODE     OUT
#define HIGH 1
#define LOW 0
#define ON 0
#define OFF 1

#define LAMP1       1

#endif /* ECUAL_LAMP_H_ */
