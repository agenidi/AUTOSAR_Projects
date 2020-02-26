/*
 * RRC.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef MCAL_RRC_H_
#define MCAL_RRC_H_

#define GPIOA       0x80000001
#define GPIOB       0x80000002
#define GPIOC       0x80000004
#define GPIOD       0x80000008
#define GPIOE       0x80000010
#define GPIOF       0x80000020
#define UDMA        0x80002000
#define USB0        0x80010000



typedef uint32_t preph_t;

Error_Status RRC_EnablePreph(preph_t Preph);

#endif /* MCAL_RRC_H_ */
