#include "delay.h"


void delay_ms(u16 t)
{
    u32 t_now=0;
    t_now=SystemTime;
    while(SystemTime<(t_now+t));
}


void delay_us(u16 t)
{
    u8 i,j;
    while(t--)
    {   
        for(i=10;i>0;i--)
        {
            for(j=10;j>0;j--);
        }
        
    }
}






































