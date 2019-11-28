#include "motor.h"

int16_t M1_Speed=0,M2_Speed=0,M3_Speed=0;
int16_t a,b;
void Car_Speed_Set(int16_t Vx,int16_t Vy,int16_t Vw)
{
    M1_Speed=  Vx*0.5f - Vy*0.866f - Vw;
    M2_Speed= -Vx                  - Vw;
    M3_Speed=  Vx*0.5f + Vy*0.866f - Vw; 
	a=M1_Speed;b=M3_Speed;
}


void M1_PWM_Set(int16_t pwm)
{
    if(pwm>8000)pwm=8000;
    if(pwm<-8000)pwm=-8000;
    
    if(pwm>=0)
    {
        TIM_SetCompare2(TIM8,pwm);
        TIM_SetCompare1(TIM8,0);
    }
    else
    {
        TIM_SetCompare2(TIM8,0);
        TIM_SetCompare1(TIM8,-pwm);
    }

}


void M2_PWM_Set(int16_t pwm)
{
   if(pwm>8000)pwm=8000;
    if(pwm<-8000)pwm=-8000;
    
    if(pwm>=0)
    {
        TIM_SetCompare3(TIM8,pwm);
        TIM_SetCompare4(TIM8,0);
    }
    else
    {
        TIM_SetCompare3(TIM8,0);
        TIM_SetCompare4(TIM8,-pwm);
    }

}


void M3_PWM_Set(int16_t pwm)
{
    if(pwm>8000)pwm=8000;
    if(pwm<-8000)pwm=-8000;
    
    if(pwm>=0)
    {
        TIM_SetCompare2(TIM1,pwm);
        TIM_SetCompare1(TIM1,0);
    }
    else
    {
        TIM_SetCompare2(TIM1,0);
        TIM_SetCompare1(TIM1,-pwm);
    }

}

