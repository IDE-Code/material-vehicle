#ifndef __ENCODER_H
#define __ENCODER_H
#include "system.h"

extern int T3_Encoder_Value;
extern int T2_Encoder_Value;
extern int T5_Encoder_Value;

void TIM3_Encoder_Init(void);
int TIM3_Encoder_Read(void);

void TIM2_Encoder_Init(void);
int TIM2_Encoder_Read(void);

void TIM5_Encoder_Init(void);
int TIM5_Encoder_Read(void);

#endif
