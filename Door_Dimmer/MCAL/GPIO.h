/*
 * DIO.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_

#define PORTF               'F'
#define OUT                 1
#define IN_FLOATING         0
#define IN_PULLUP           2
#define SET                 1
#define RESET               0
Error_Status GPIO_Init(uint8_t Port, uint8_t Pin, uint8_t Mode);
Error_Status GPIO_ReadPin(uint8_t Port, uint8_t Pin, uint8_t * Value);
Error_Status GPIO_WritePin(uint8_t Port, uint8_t Pin, uint8_t Value);

#endif /* MCAL_GPIO_H_ */
