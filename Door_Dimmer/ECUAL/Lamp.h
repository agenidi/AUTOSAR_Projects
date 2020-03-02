/************************************************************************
 * File name: Lamp.h
 *
 *
 * Description: This file contains the prototypes of Lamp driver
 * and the macros used by the user
 *
 * owner: Hammam Mazen
 * date: 27/2/2020
 * version 1.1
 *
 ***************************************************************************/

#ifndef ECUAL_LAMP_H_
#define ECUAL_LAMP_H_


/************************************************************************
 * Function name: Lamp_Init
 *
 * parameters:  
 *              Input: void
 *              Output: NA
 *              In/out: NA
 * return: OK, NOK
 * Description: a function to initialize the lamp .
 ***************************************************************************/
 
Error_Status Lamp_Init(void);

/************************************************************************
 * Function name: Lamp_Update
 *
 * parameters:  Input:
 *                 Lamp_Ch
 *                     type: uint8_t
                        Description: Lamp Channel
 *                 State
 *                     type: uint8_t
 *                     Description: Lamp Status (ON, OFF)
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to initialize all the GPIO Groups in the configurations
 ***************************************************************************/
 
Error_Status Lamp_Update(uint8_t Lamp_Ch, uint8_t State);

/*Lamp Configurations*/
#define LAMP_PIN               1
#define LAMP_PORT              PORTF
#define LAMP_PORT_CLOCK        GPIOF
#define LAMP_PIN_MODE          OUT

/*Lamp Pin Value*/
#define HIGH 1
#define LOW 0

/*Lamp Status*/
#define ON 0
#define OFF 1

/*Lamp Channel Configuration*/
#define LAMP1       1

#endif /* ECUAL_LAMP_H_ */
