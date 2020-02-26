/*
 * LeftDoor.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef APP_LEFTDOOR_H_
#define APP_LEFTDOOR_H_

#define LEFTSENSOR 	1


Error_Status LeftDoor_init(void);
Error_Status LeftDoor_GetStatus(u8 *DoorStatus);


#endif /* APP_LEFTDOOR_H_ */
