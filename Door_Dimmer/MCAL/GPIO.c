/************************************************************************
 * File name: GPIO.c
 *
 *
 * Description: This file contains the implementation of the GPIO driver
 *
 * owner: Ahmed GENEDI , Mohamed Anwar
 * date: 2/3/2020
 * version 1.2
 *
 ***************************************************************************/
#include "LIB/Std_lib.h"
#include "GPIO.h"
/* GPIO PORTF registers */
#define GPIO_PORTF_APB_BASE_ADDRESS 0x40025000
#define GPIO_PORTF_DATA(offset)     *((volatile uint32_t * )((uint32_t)(GPIO_PORTF_APB_BASE_ADDRESS+(offset))))
#define GPIO_PORTF_DIR              *((volatile uint32_t * )(GPIO_PORTF_APB_BASE_ADDRESS+0x0400))
#define GPIO_PORTF_DEN              *((volatile uint32_t * )(GPIO_PORTF_APB_BASE_ADDRESS+0x51C))
#define GPIO_PORTF_PUR              *((volatile uint32_t * )(GPIO_PORTF_APB_BASE_ADDRESS+0x0510))
#define GPIO_PORTF_LOCK             *((volatile uint32_t * )(GPIO_PORTF_APB_BASE_ADDRESS+0x0520))
#define GPIO_PORTF_CR               *((volatile uint32_t * )(GPIO_PORTF_APB_BASE_ADDRESS+0x0524))

/* GPIO PORTE registers */
#define GPIO_PORTE_APB_BASE_ADDRESS 0x40024000
#define GPIO_PORTE_DATA(offset)     *((volatile uint32_t * )((uint32_t)(GPIO_PORTF_APB_BASE_ADDRESS+(offset))))
#define GPIO_PORTE_DIR              *((volatile uint32_t * )(GPIO_PORTE_APB_BASE_ADDRESS+0x0400))
#define GPIO_PORTE_DEN              *((volatile uint32_t * )(GPIO_PORTE_APB_BASE_ADDRESS+0x51C))
#define GPIO_PORTE_PUR              *((volatile uint32_t * )(GPIO_PORTE_APB_BASE_ADDRESS+0x0510))
#define GPIO_PORTE_LOCK             *((volatile uint32_t * )(GPIO_PORTE_APB_BASE_ADDRESS+0x0520))
#define GPIO_PORTE_CR               *((volatile uint32_t * )(GPIO_PORTE_APB_BASE_ADDRESS+0x0524))

/* GPIO PORTD registers */
#define GPIO_PORTD_APB_BASE_ADDRESS 0x40007000
#define GPIO_PORTD_DATA(offset)     *((volatile uint32_t * )((uint32_t)(GPIO_PORTD_APB_BASE_ADDRESS+(offset))))
#define GPIO_PORTD_DIR              *((volatile uint32_t * )(GPIO_PORTD_APB_BASE_ADDRESS+0x0400))
#define GPIO_PORTD_DEN              *((volatile uint32_t * )(GPIO_PORTD_APB_BASE_ADDRESS+0x51C))
#define GPIO_PORTD_PUR              *((volatile uint32_t * )(GPIO_PORTD_APB_BASE_ADDRESS+0x0510))
#define GPIO_PORTD_LOCK             *((volatile uint32_t * )(GPIO_PORTD_APB_BASE_ADDRESS+0x0520))
#define GPIO_PORTD_CR               *((volatile uint32_t * )(GPIO_PORTD_APB_BASE_ADDRESS+0x0524))

/* GPIO PORTC registers */
#define GPIO_PORTC_APB_BASE_ADDRESS 0x40006000
#define GPIO_PORTC_DATA(offset)     *((volatile uint32_t * )((uint32_t)(GPIO_PORTC_APB_BASE_ADDRESS+(offset))))
#define GPIO_PORTC_DIR              *((volatile uint32_t * )(GPIO_PORTC_APB_BASE_ADDRESS+0x0400))
#define GPIO_PORTC_DEN              *((volatile uint32_t * )(GPIO_PORTC_APB_BASE_ADDRESS+0x51C))
#define GPIO_PORTC_PUR              *((volatile uint32_t * )(GPIO_PORTC_APB_BASE_ADDRESS+0x0510))
#define GPIO_PORTC_LOCK             *((volatile uint32_t * )(GPIO_PORTC_APB_BASE_ADDRESS+0x0520))
#define GPIO_PORTC_CR               *((volatile uint32_t * )(GPIO_PORTC_APB_BASE_ADDRESS+0x0524))

/* GPIO PORTB registers */
#define GPIO_PORTB_APB_BASE_ADDRESS 0x40005000
#define GPIO_PORTB_DATA(offset)     *((volatile uint32_t * )((uint32_t)(GPIO_PORTB_APB_BASE_ADDRESS+(offset))))
#define GPIO_PORTB_DIR              *((volatile uint32_t * )(GPIO_PORTB_APB_BASE_ADDRESS+0x0400))
#define GPIO_PORTB_DEN              *((volatile uint32_t * )(GPIO_PORTB_APB_BASE_ADDRESS+0x51C))
#define GPIO_PORTB_PUR              *((volatile uint32_t * )(GPIO_PORTB_APB_BASE_ADDRESS+0x0510))
#define GPIO_PORTB_LOCK             *((volatile uint32_t * )(GPIO_PORTB_APB_BASE_ADDRESS+0x0520))
#define GPIO_PORTB_CR               *((volatile uint32_t * )(GPIO_PORTB_APB_BASE_ADDRESS+0x0524))

/* GPIO PORTA registers */
#define GPIO_PORTA_APB_BASE_ADDRESS 0x40004000
#define GPIO_PORTA_DATA(offset)     *((volatile uint32_t * )((uint32_t)(GPIO_PORTA_APB_BASE_ADDRESS+(offset))))
#define GPIO_PORTA_DIR              *((volatile uint32_t * )(GPIO_PORTA_APB_BASE_ADDRESS+0x0400))
#define GPIO_PORTA_DEN              *((volatile uint32_t * )(GPIO_PORTA_APB_BASE_ADDRESS+0x51C))
#define GPIO_PORTA_PUR              *((volatile uint32_t * )(GPIO_PORTA_APB_BASE_ADDRESS+0x0510))
#define GPIO_PORTA_LOCK             *((volatile uint32_t * )(GPIO_PORTA_APB_BASE_ADDRESS+0x0520))
#define GPIO_PORTA_CR               *((volatile uint32_t * )(GPIO_PORTA_APB_BASE_ADDRESS+0x0524))


#define NUMBER_OF_PINS	8

#define LOCK_PASSOWRD	0x4c4f434b

#define ONE 1

#define OFFSET_OFFSET 2

Error_Status GPIO_Init(uint8_t Port, uint8_t Pin, uint8_t Mode)
{
    Error_Status stat = OK;
    switch (Port)
    {
		case PORTA:
        if (Pin < NUMBER_OF_PINS)
        {
            GPIO_PORTA_LOCK = LOCK_PASSOWRD;
            GPIO_PORTA_CR |=  Pin;
            GPIO_PORTA_DEN |=  Pin;
            if (Mode == OUT)
            {
                GPIO_PORTA_DIR |= Pin;
            }
            else if (Mode == IN_FLOATING)
            {
                GPIO_PORTA_DIR &= ~(Pin);
                GPIO_PORTA_PUR &= ~(Pin);
            }
            else if (Mode == IN_PULLUP)
            {
                GPIO_PORTA_DIR &= ~(Pin);
                GPIO_PORTA_PUR |= Pin;
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
		case PORTB:
        if (Pin < NUMBER_OF_PINS)
        {
            GPIO_PORTB_LOCK = LOCK_PASSOWRD;
            GPIO_PORTB_CR |=  Pin;
            GPIO_PORTB_DEN |=  Pin;
            if (Mode == OUT)
            {
                GPIO_PORTF_DIR |= Pin;
            }
            else if (Mode == IN_FLOATING)
            {
                GPIO_PORTB_DIR &= ~(Pin);
                GPIO_PORTB_PUR &= ~(Pin);
            }
            else if (Mode == IN_PULLUP)
            {
                GPIO_PORTB_DIR &= ~(Pin);
                GPIO_PORTB_PUR |= Pin;
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
		case PORTC:
        if (Pin < NUMBER_OF_PINS)
        {
            GPIO_PORTC_LOCK = LOCK_PASSOWRD;
            GPIO_PORTC_CR |=  Pin;
            GPIO_PORTC_DEN |=  Pin;
            if (Mode == OUT)
            {
                GPIO_PORTC_DIR |= Pin;
            }
            else if (Mode == IN_FLOATING)
            {
                GPIO_PORTC_DIR &= ~(Pin);
                GPIO_PORTC_PUR &= ~(Pin);
            }
            else if (Mode == IN_PULLUP)
            {
                GPIO_PORTC_DIR &= ~(Pin);
                GPIO_PORTC_PUR |= Pin;
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
		case PORTD:
        if (Pin < NUMBER_OF_PINS)
        {
            GPIO_PORTD_LOCK = LOCK_PASSOWRD;
            GPIO_PORTD_CR |=  Pin;
            GPIO_PORTD_DEN |=  Pin;
            if (Mode == OUT)
            {
                GPIO_PORTD_DIR |= Pin;
            }
            else if (Mode == IN_FLOATING)
            {
                GPIO_PORTD_DIR &= ~(Pin);
                GPIO_PORTD_PUR &= ~(Pin);
            }
            else if (Mode == IN_PULLUP)
            {
                GPIO_PORTD_DIR &= ~(Pin);
                GPIO_PORTD_PUR |= Pin;
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
    case PORTE:
        if (Pin < NUMBER_OF_PINS)
        {
            GPIO_PORTE_LOCK = LOCK_PASSOWRD;
            GPIO_PORTE_CR |=  Pin;
            GPIO_PORTE_DEN |=  Pin;
            if (Mode == OUT)
            {
                GPIO_PORTE_DIR |= Pin;
            }
            else if (Mode == IN_FLOATING)
            {
                GPIO_PORTE_DIR &= ~(Pin);
                GPIO_PORTE_PUR &= ~(Pin);
            }
            else if (Mode == IN_PULLUP)
            {
                GPIO_PORTE_DIR &= ~(Pin);
                GPIO_PORTE_PUR |= Pin;
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
		    case PORTF:
        if (Pin < NUMBER_OF_PINS)
        {
            GPIO_PORTF_LOCK = LOCK_PASSOWRD;
            GPIO_PORTF_CR |=  Pin;
            GPIO_PORTF_DEN |=  Pin;
            if (Mode == OUT)
            {
                GPIO_PORTF_DIR |= Pin;
            }
            else if (Mode == IN_FLOATING)
            {
                GPIO_PORTF_DIR &= ~(Pin);
                GPIO_PORTF_PUR &= ~(Pin);
            }
            else if (Mode == IN_PULLUP)
            {
                GPIO_PORTF_DIR &= ~(Pin);
                GPIO_PORTF_PUR |= Pin;
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
	case PORTA:
        if (Pin < NUMBER_OF_PINS)
        {
            *Value = (GPIO_PORTA_DATA(ONE<<(Pin+OFFSET_OFFSET)) >> Pin) & ONE;
        }
        else
        {
            stat = NOK;
        }
        break;
	case PORTB:
        if (Pin < NUMBER_OF_PINS)
        {
            *Value = (GPIO_PORTB_DATA(ONE<<(Pin+OFFSET_OFFSET)) >> Pin) & ONE;
        }
        else
        {
            stat = NOK;
        }
        break;
	case PORTC:
        if (Pin < NUMBER_OF_PINS)
        {
            *Value = (GPIO_PORTC_DATA(ONE<<(Pin+OFFSET_OFFSET)) >> Pin) & ONE;
        }
        else
        {
            stat = NOK;
        }
        break;
	case PORTD:
        if (Pin < NUMBER_OF_PINS)
        {
            *Value = (GPIO_PORTD_DATA(ONE<<(Pin+OFFSET_OFFSET)) >> Pin) & ONE;
        }
        else
        {
            stat = NOK;
        }
        break;
	case PORTE:
        if (Pin < NUMBER_OF_PINS)
        {
            *Value = (GPIO_PORTE_DATA(ONE<<(Pin+OFFSET_OFFSET)) >> Pin) & ONE;
        }
        else
        {
            stat = NOK;
        }
        break;
    case PORTF:
        if (Pin < NUMBER_OF_PINS)
        {
            *Value = (GPIO_PORTF_DATA(ONE<<(Pin+OFFSET_OFFSET)) >> Pin) & ONE;
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
        if (Pin < NUMBER_OF_PINS)
        {

            if (Value == SET)
            {

                GPIO_PORTF_DATA(ONE<<(Pin+OFFSET_OFFSET)) |= Pin;

            }
            else if (Value == RESET)
            {
                GPIO_PORTF_DATA(ONE<<(Pin+OFFSET_OFFSET)) &= ~(Pin);
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
		    case PORTE:
        if (Pin < NUMBER_OF_PINS)
        {

            if (Value == SET)
            {

                GPIO_PORTE_DATA(ONE<<(Pin+OFFSET_OFFSET)) |= Pin;

            }
            else if (Value == RESET)
            {
                GPIO_PORTE_DATA(ONE<<(Pin+OFFSET_OFFSET)) &= ~(Pin);
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
		    case PORTD:
        if (Pin < NUMBER_OF_PINS)
        {

            if (Value == SET)
            {

                GPIO_PORTD_DATA(ONE<<(Pin+OFFSET_OFFSET)) |= Pin;

            }
            else if (Value == RESET)
            {
                GPIO_PORTD_DATA(ONE<<(Pin+OFFSET_OFFSET)) &= ~(Pin);
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
		    case PORTC:
        if (Pin < NUMBER_OF_PINS)
        {

            if (Value == SET)
            {

                GPIO_PORTC_DATA(ONE<<(Pin+OFFSET_OFFSET)) |= Pin;

            }
            else if (Value == RESET)
            {
                GPIO_PORTC_DATA(ONE<<(Pin+OFFSET_OFFSET)) &= ~(Pin);
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
		    case PORTB:
        if (Pin < NUMBER_OF_PINS)
        {

            if (Value == SET)
            {

                GPIO_PORTB_DATA(ONE<<(Pin+OFFSET_OFFSET)) |= Pin;

            }
            else if (Value == RESET)
            {
                GPIO_PORTB_DATA(ONE<<(Pin+OFFSET_OFFSET)) &= ~(Pin);
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
		    case PORTA:
        if (Pin < NUMBER_OF_PINS)
        {

            if (Value == SET)
            {

                GPIO_PORTA_DATA(ONE<<(Pin+OFFSET_OFFSET)) |= Pin;

            }
            else if (Value == RESET)
            {
                GPIO_PORTA_DATA(ONE<<(Pin+OFFSET_OFFSET)) &= ~(Pin);
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
