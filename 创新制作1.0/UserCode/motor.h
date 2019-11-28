#ifndef __MOTOR_H
#define __MOTOR_H
#include "system.h"

extern int16_t M1_Speed,M2_Speed,M3_Speed;

void M1_PWM_Set(int16_t pwm);
void M2_PWM_Set(int16_t pwm);
void M3_PWM_Set(int16_t pwm);

void Car_Speed_Set(int16_t Vx,int16_t Vy,int16_t Vw);

extern int16_t M1_Speed,M2_Speed,M3_Speed;

#endif

