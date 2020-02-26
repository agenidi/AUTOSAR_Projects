/**
 * main.c
 */
#include "LIB/Std_lib.h"
#include "APP/LeftDoor.h"
#include "APP/RightDoor.h"
#include "APP/Lighting.h"
int main(void)
{
    uint8_t leftdoor_stat;
    uint8_t Rightdoor_stat;

    LeftDoor_init();
    RightDoor_init();
    Lighting_init();
    while (1)
    {
        RighttDoor_GetStatus(&Rightdoor_stat);
        LeftDoor_GetStatus(&leftdoor_stat);
        Lighting_Control(Rightdoor_stat);
        Lighting_Control(leftdoor_stat);
    }
    return 0;
}
