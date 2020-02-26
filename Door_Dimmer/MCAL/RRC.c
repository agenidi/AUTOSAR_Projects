/*
 * RRC.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */
#include "LIB/Std_lib.h"
#include "RRC.h"

#define SYS_CTRL_BASE_ADDRESS   0x400FE000
#define RCGC2                   *((volatile uint32_t * const)(SYS_CTRL_BASE_ADDRESS+0x108))
#define RCGC1                   *((volatile uint32_t * const)(SYS_CTRL_BASE_ADDRESS+0x104))

#define RCGC1_MASK    0x40000000
#define RCGC2_MASK    0x80000000

/*This function is used to enbale the clock of a certain prephiral
 * input options of preph_t are:
 *  GPIOA
    GPIOB
    GPIOC
    GPIOD
    GPIOE
    GPIOF
    UDMA
    USB0
 */
Error_Status RRC_EnablePreph(preph_t Preph)
{
    Error_Status stat = OK;
    if ((Preph & RCGC2_MASK) == RCGC2_MASK)
    {
        Preph &= ~(RCGC2_MASK);
        RCGC2 |= Preph;
    }
    else if (Preph & RCGC1_MASK == RCGC1_MASK)
    {
        Preph &= ~(RCGC1_MASK);
        RCGC1 |= Preph;
    }
    else
    {
        stat = NOK;
    }
    return stat;
}

