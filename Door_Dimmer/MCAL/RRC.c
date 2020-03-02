/************************************************************************
 * File name: RCC.c
 *
 *
 * Description: This file contains the implementation of the RCC driver
 *
 * owner: Ahmed GENEDI , Mohamed Anwar
 * date: 2/3/2020
 * version 1.2
 *
 ***************************************************************************/
#include "LIB/Std_lib.h"
#include "RRC.h"
/* RCC registers */
#define SYS_CTRL_BASE_ADDRESS   0x400FE000
#define RCGC2                   *((volatile uint32_t * const)(SYS_CTRL_BASE_ADDRESS+0x108))
#define RCGC1                   *((volatile uint32_t * const)(SYS_CTRL_BASE_ADDRESS+0x104))

/*mask to determine which register (RCCG1 , RCCG2) to set to enable the wanted preipheral*/
#define RCGC1_MASK    0x40000000
#define RCGC2_MASK    0x80000000


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

