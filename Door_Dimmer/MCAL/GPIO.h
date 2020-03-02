/************************************************************************
 * File name: GPIO.h
 *
 *
 * Description: This file contains the prototypes of the GPIO driver
 * and the macros used by the user
 *
 * owner: Ahmed GENEDI , Mohamed Anwar
 * date: 2/3/2020
 * version 1.2
 *
 ***************************************************************************/
#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_

/* GPIO signals */
#define SET   			0x01
#define RESET    		0x00

#define INPUT_FLOATING  0x00
#define OUTPUT  		0x01
#define INPUT_PULLUP	0x02
#define INPUT_PULLDOWN  0x03

/* GPIO ports */
#define PORTA   		'A'
#define PORTB   		'B'
#define PORTC   		'C'
#define PORTD   		'D'
#define PORTE   		'E'
#define PORTF   		'F'

/* GPIO pins */
#define PIN0    		0x01	
#define PIN1    		0x02
#define PIN2    		0x04
#define PIN3    		0x08
#define PIN4    		0x10
#define PIN5    		0x20
#define PIN6    		0x40
#define PIN7    		0x80



/************************************************************************
 * function name: GPIO_Init
 *
 * parameters:  Input:
 *                Port
 *                     type: uint8_t
 *                      Description: GPIO port number (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF)
 *                 Pin
 *                     type: uint8_t
 *                     Description: GPIO pin number (PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7)
 *                     
 *                 Mode
 *                     type: uint8_t
 *                     Description: Mode of the pin (OUTPUT,INPUT_FLOATING,INPUT_PULLDOWN,INPUT_PULLUP)
 *
 *              Output: NA
 *              In/out: NA
 *
 * return: OK , NOK
 * Description: a function to cofigure the mode of a specific pin on a specific port
***************************************************************************/
Error_Status GPIO_Init(uint8_t Port, uint8_t Pin, uint8_t Mode);

/************************************************************************
 * function name: GPIO_ReadPin
 *
 * parameters:  Input:
 *                Port
 *                     type: uint8_t
                        Description: GPIO port number (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF)
 *                 Pin
 *                     type: uint8_t
 *                     Description: GPIO pin number (PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,IN7)
 *
 *
 *              Output: NA
 *              In/out: Value
 *                     type: pointer to uint8_t
 *                     Description: value which to be read from specified pin on a specific port
 *
 * return: OK , NOK
 * Description: a function to Digital read data from a specific port and pin
***************************************************************************/
Error_Status GPIO_ReadPin(uint8_t Port, uint8_t Pin, uint8_t * Value);

/************************************************************************
 * function name: GPIO_WritePin
 *
 * parameters:  Input:
 *                Port
 *                     type: uint8_t
                        Description: GPIO port number (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF)
 *                 Pin
 *                     type: uint8_t
 *                     Description: GPIO pin number (PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7)
 *                 Data
 *                     type: uint8_t
 *                     Description: data which to be written on specified pin(SET,RESET)
 *
 *              Output: NA
 *              In/out: NA
 *
 * return: OK , NOK
 * Description: a function to write data to a specific port and pin
***************************************************************************/
Error_Status GPIO_WritePin(uint8_t Port, uint8_t Pin, uint8_t Value);

#endif /* MCAL_GPIO_H_ */
