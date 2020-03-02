/************************************************************************
 * File name: RCC.h
 *
 *
 * Description: This file contains the prototypes of the RCC driver
 *
 * owner: Ahmed GENEDI , Mohamed Anwar
 * date: 2/3/2020
 * version 1.2
 *
 ***************************************************************************/

#ifndef MCAL_RRC_H_
#define MCAL_RRC_H_

/*Perpherals macros passed to the RRC_EnablePreph function*/
#define PORTA       0x80000001
#define PORTB       0x80000002
#define PORTC       0x80000004
#define PORTD       0x80000008
#define PORTE       0x80000010
#define GPIOF       0x80000020
#define UDMA        0x80002000
#define USB0        0x80010000



typedef uint32_t preph_t;


/************************************************************************
 * function name: RRC_EnablePreph
 *
 * parameters:  Input:
 *                Preph
 *                     type: preph_t
 *                      Description: Perpheral name :
 *											GPIOA,
 *											GPIOB,
 *											GPIOC,
 *											GPIOD,
 *											GPIOE,
 *											GPIOF,
 *											UDMA,
 *											USB0                 
 *              Output: NA
 *              In/out: NA
 *
 * return: OK , NOK
 * Description: a function to enable the wanted perpheral clock
***************************************************************************/
Error_Status RRC_EnablePreph(preph_t Preph);

#endif /* MCAL_RRC_H_ */
