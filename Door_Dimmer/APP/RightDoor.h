/*
 * RightDoor.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */

#ifndef APP_RIGHTDOOR_H_
#define APP_RIGHTDOOR_H_



#define RIGHTSENSOR		2


Error_Status RightDoor_init(void);

Error_Status RighttDoor_GetStatus(u8 *DoorStatus);

#endif /* APP_RIGHTDOOR_H_ */
