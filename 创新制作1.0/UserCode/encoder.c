#include "encoder.h"

int T3_Encoder_Value=0;
int T2_Encoder_Value=0;
int T5_Encoder_Value=0;

void TIM5_Encoder_Init(void)
{
        GPIO_InitTypeDef                ENCODER;
        TIM_TimeBaseInitTypeDef         TIMER5;
        TIM_ICInitTypeDef               IC_ENCODER;
        NVIC_InitTypeDef                nvic;

        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//时钟
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
        
        GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,        GPIO_AF_TIM5);//引脚复用
        GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,        GPIO_AF_TIM5);
    
        ENCODER.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;//引脚初始化
        ENCODER.GPIO_Mode = GPIO_Mode_AF;
        ENCODER.GPIO_Speed = GPIO_Speed_100MHz;
        ENCODER.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init(GPIOA, &ENCODER);
    
        TIMER5.TIM_Prescaler = 0;//定时器初始化
        TIMER5.TIM_Period = 0xffff;  //500*4
        TIMER5.TIM_ClockDivision = TIM_CKD_DIV1;
        TIMER5.TIM_CounterMode = TIM_CounterMode_Up;   
        TIM_TimeBaseInit(TIM5, &TIMER5);
        
        TIM_EncoderInterfaceConfig(TIM5, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling, TIM_ICPolarity_Falling);//定时器Encoder模式
        
        IC_ENCODER.TIM_Channel        =        TIM_Channel_1;//通道选择
        IC_ENCODER.TIM_ICSelection        =        TIM_ICSelection_DirectTI;
        TIM_ICInit(TIM5, &IC_ENCODER);
        IC_ENCODER.TIM_Channel        =        TIM_Channel_2;
        IC_ENCODER.TIM_ICSelection        =        TIM_ICSelection_DirectTI;
        TIM_ICInit(TIM5, &IC_ENCODER);
        
        nvic.NVIC_IRQChannel = TIM5_IRQn;//中断设置
        nvic.NVIC_IRQChannelPreemptionPriority = 1;
        nvic.NVIC_IRQChannelSubPriority = 1;
        nvic.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&nvic);
        
        TIM_ClearFlag(TIM5, TIM_FLAG_Update);//清标识，开中断
        TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
        
        TIM_SetCounter(TIM5,0x8000); 
        TIM_Cmd(TIM5, ENABLE);
}

int TIM5_Encoder_Read(void)
{
        int cnt = 0;
        cnt = TIM_GetCounter(TIM5) - 0x8000;    
        TIM_SetCounter(TIM5, 0x8000);
        return cnt;
}

void TIM2_Encoder_Init(void)
{
        GPIO_InitTypeDef                ENCODER;
        TIM_TimeBaseInitTypeDef         TIMER2;
        TIM_ICInitTypeDef               IC_ENCODER;
        NVIC_InitTypeDef                nvic;

        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOA, ENABLE);//时钟
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
        
        GPIO_PinAFConfig(GPIOA,GPIO_PinSource5,        GPIO_AF_TIM2);//引脚复用
        GPIO_PinAFConfig(GPIOB,GPIO_PinSource3,        GPIO_AF_TIM2);
    
        ENCODER.GPIO_Pin = GPIO_Pin_5;//引脚初始化
        ENCODER.GPIO_Mode = GPIO_Mode_AF;
        ENCODER.GPIO_Speed = GPIO_Speed_100MHz;
        ENCODER.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init(GPIOA, &ENCODER);
        
				ENCODER.GPIO_Pin = GPIO_Pin_3;//引脚初始化
        ENCODER.GPIO_Mode = GPIO_Mode_AF;
        ENCODER.GPIO_Speed = GPIO_Speed_100MHz;
        ENCODER.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init(GPIOB, &ENCODER);
				
        TIMER2.TIM_Prescaler = 0;//定时器初始化
        TIMER2.TIM_Period = 0xffff;  //500*4
        TIMER2.TIM_ClockDivision = TIM_CKD_DIV1;
        TIMER2.TIM_CounterMode = TIM_CounterMode_Up;   
        TIM_TimeBaseInit(TIM2, &TIMER2);
        
        TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling, TIM_ICPolarity_Falling);//定时器Encoder模式
        
        IC_ENCODER.TIM_Channel        =        TIM_Channel_1;//通道选择
        IC_ENCODER.TIM_ICSelection        =        TIM_ICSelection_DirectTI;
        TIM_ICInit(TIM2, &IC_ENCODER);
        IC_ENCODER.TIM_Channel        =        TIM_Channel_2;
        IC_ENCODER.TIM_ICSelection        =        TIM_ICSelection_DirectTI;
        TIM_ICInit(TIM2, &IC_ENCODER);
        
        nvic.NVIC_IRQChannel = TIM2_IRQn;//中断设置
        nvic.NVIC_IRQChannelPreemptionPriority = 1;
        nvic.NVIC_IRQChannelSubPriority = 1;
        nvic.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&nvic);
        
        TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清标识，开中断
        TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
        
        TIM_SetCounter(TIM2,0x8000); 
        TIM_Cmd(TIM2, ENABLE);
}

int TIM2_Encoder_Read(void)
{
        int cnt = 0;
        cnt = TIM_GetCounter(TIM2) - 0x8000;    
        TIM_SetCounter(TIM2, 0x8000);
        return cnt;
}


void TIM3_Encoder_Init(void)
{
        GPIO_InitTypeDef                ENCODER;
        TIM_TimeBaseInitTypeDef         TIMER3;
        TIM_ICInitTypeDef               IC_ENCODER;
        NVIC_InitTypeDef                nvic;

        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//时钟
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
        
        GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,        GPIO_AF_TIM3);//引脚复用
        GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,        GPIO_AF_TIM3);
    
        ENCODER.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;//引脚初始化
        ENCODER.GPIO_Mode = GPIO_Mode_AF;
        ENCODER.GPIO_Speed = GPIO_Speed_100MHz;
        ENCODER.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init(GPIOA, &ENCODER);
    
        TIMER3.TIM_Prescaler = 0;//定时器初始化
        TIMER3.TIM_Period = 0xffff;  //500*4
        TIMER3.TIM_ClockDivision = TIM_CKD_DIV1;
        TIMER3.TIM_CounterMode = TIM_CounterMode_Up;   
        TIM_TimeBaseInit(TIM3, &TIMER3);
        
        TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling, TIM_ICPolarity_Falling);//定时器Encoder模式
        
        IC_ENCODER.TIM_Channel        =        TIM_Channel_1;//通道选择
        IC_ENCODER.TIM_ICSelection        =        TIM_ICSelection_DirectTI;
        TIM_ICInit(TIM3, &IC_ENCODER);
        IC_ENCODER.TIM_Channel        =        TIM_Channel_2;
        IC_ENCODER.TIM_ICSelection        =        TIM_ICSelection_DirectTI;
        TIM_ICInit(TIM3, &IC_ENCODER);
        
        nvic.NVIC_IRQChannel = TIM3_IRQn;//中断设置
        nvic.NVIC_IRQChannelPreemptionPriority = 1;
        nvic.NVIC_IRQChannelSubPriority = 1;
        nvic.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&nvic);
        
        TIM_ClearFlag(TIM3, TIM_FLAG_Update);//清标识，开中断
        TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
        
        TIM_SetCounter(TIM3,0x8000); 
        TIM_Cmd(TIM3, ENABLE);
}

int TIM3_Encoder_Read(void)
{
        int cnt = 0;
        cnt = TIM_GetCounter(TIM3) - 0x8000;    
        TIM_SetCounter(TIM3, 0x8000);
        return cnt;
}
