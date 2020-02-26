/*
 * GPIO.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ahmed
 */
#include "LIB/Std_lib.h"
#include "GPIO.h"

#define GPIO_PORTF_BASE_ADDRESS     0x40025000
#define GPIO_PORTF_DATA(offset)     *((volatile uint32_t * )((uint32_t)(GPIO_PORTF_BASE_ADDRESS+(offset))))
#define GPIO_PORTF_DIR              *((volatile uint32_t * )(GPIO_PORTF_BASE_ADDRESS+0x0400))
#define GPIO_PORTF_DEN              *((volatile uint32_t * )(GPIO_PORTF_BASE_ADDRESS+0x51C))
#define GPIO_PORTF_PUR              *((volatile uint32_t * )(GPIO_PORTF_BASE_ADDRESS+0x0510))

#define GPIO_PORTF_LOCK              *((volatile uint32_t * )(GPIO_PORTF_BASE_ADDRESS+0x0520))
#define GPIO_PORTF_CR               *((volatile uint32_t * )(GPIO_PORTF_BASE_ADDRESS+0x0524))

Error_Status GPIO_Init(uint8_t Port, uint8_t Pin, uint8_t Mode)
{
    Error_Status stat = OK;
    switch (Port)
    {
    case PORTF:
        if ( Pin < 8)
        {
            GPIO_PORTF_LOCK = 0x4c4f434b;
            GPIO_PORTF_CR |= (1<<Pin);
            GPIO_PORTF_DEN |= (1 << Pin);
            if (Mode == OUT)
            {
                GPIO_PORTF_DIR |= (1 << Pin);
            }
            else if (Mode == IN_FLOATING)
            {
                GPIO_PORTF_DIR &= ~(1 <<Pin);
                GPIO_PORTF_PUR &= ~(1<< Pin);
            }
            else if (Mode == IN_PULLUP)
            {
                GPIO_PORTF_DIR &= ~(1 <<Pin);
                GPIO_PORTF_PUR |= 1<< Pin;
            }
            else
            {
                stat = NOK;
            }
        }
        else
        {
            stat = NOK;
        }
        break;
    default:
        stat = NOK;
        break;
    }
    return stat;
}
Error_Status GPIO_ReadPin(uint8_t Port, uint8_t Pin, uint8_t * Value)
{
    Error_Status stat = OK;
    switch (Port)
    {
    case PORTF:
        if ( Pin < 8)
        {
            *Value = (GPIO_PORTF_DATA(1<<(Pin+2)) >> Pin) & 0x01;
        }
        else
        {
            stat = NOK;
        }
        break;
    default:
        stat = NOK;
        break;
    }
    return stat;

}

Error_Status GPIO_WritePin(uint8_t Port, uint8_t Pin, uint8_t Value)
{
    Error_Status stat = OK;
    switch (Port)
    {
    case PORTF:
        if ( Pin < 8)
        {

            if (Value == SET)
            {

                GPIO_PORTF_DATA(1<<(Pin+2)) |= (1 << Pin);

            }
            else if (Value == RESET)
            {
                GPIO_PORTF_DATA(1<<(Pin+2)) &= ~(1 << Pin);
            }
            else
            {
                stat = NOK;
            }
        }
        else
        {
            stat = NOK;
        }
        break;
    default:
        stat = NOK;
        break;
    }
    return stat;
}
