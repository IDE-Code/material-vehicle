#include "system.h"  


u32 SystemTime=0;






void SysTick_Handler(void)
{
    SystemTime++;
}











