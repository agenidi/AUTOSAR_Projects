/*
 * RRC.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef MCAL_RRC_H_
#define MCAL_RRC_H_

#define PORTA       0x80000001
#define PORTB       0x80000002
#define PORTC       0x80000004
#define PORTD       0x80000008
#define PORTE       0x80000010
#define GPIOF       0x80000020
#define UDMA        0x80002000
#define USB0        0x80010000



typedef uint32_t preph_t;

Error_Status RRC_EnablePreph(preph_t Preph);

#endif /* MCAL_RRC_H_ */
