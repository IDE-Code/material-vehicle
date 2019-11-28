#include "pwm.h"


void TIM8_PWM_Init(u32 arr,u32 psc)  
{                              
   
    GPIO_InitTypeDef GPIO_InitStructure;  
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;  
    TIM_OCInitTypeDef  TIM_OCInitStructure;  
      
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);         
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);    
  
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM8); 
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM8);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM8); 
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM8);
          
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;          
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;       
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;      
    GPIO_Init(GPIOC,&GPIO_InitStructure);              
      
    TIM_TimeBaseStructure.TIM_Prescaler=psc; 
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period=arr;  
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;   
    TIM_TimeBaseInit(TIM8,&TIM_TimeBaseStructure);
      
  
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;	
    TIM_OCInitStructure.TIM_Pulse = 0; 
    TIM_OC1Init(TIM8, &TIM_OCInitStructure);  
    TIM_OC2Init(TIM8, &TIM_OCInitStructure); 
    TIM_OC3Init(TIM8, &TIM_OCInitStructure); 
    TIM_OC4Init(TIM8, &TIM_OCInitStructure);
      
    TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable); 
    TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable); 
    TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable); 
    TIM_OC4PreloadConfig(TIM8, TIM_OCPreload_Enable); 
      			
		TIM_CtrlPWMOutputs(TIM8,ENABLE);	//MOE 主输出使能	
		
    TIM_ARRPreloadConfig(TIM8,ENABLE);
		
    TIM_Cmd(TIM8, ENABLE); 
    
    TIM_SetCompare1(TIM8,0);
    TIM_SetCompare2(TIM8,0);
    TIM_SetCompare3(TIM8,0);
    TIM_SetCompare4(TIM8,0);
                     
}


void TIM1_PWM_Init(u32 arr,u32 psc)
{		 					 
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);   
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);	

    GPIO_PinAFConfig(GPIOA,GPIO_PinSource8,GPIO_AF_TIM1); 
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_TIM1);  

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
    GPIO_Init(GPIOA,&GPIO_InitStructure);          

    TIM_TimeBaseStructure.TIM_Prescaler=psc;  
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
    TIM_TimeBaseStructure.TIM_Period=arr;  
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
    TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStructure);
    
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
		TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);		
    TIM_OC2Init(TIM1, &TIM_OCInitStructure); 
		
		TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable); 

    TIM_CtrlPWMOutputs(TIM1,ENABLE);	//MOE 主输出使能	
		
    TIM_ARRPreloadConfig(TIM1,ENABLE);

    TIM_Cmd(TIM1, ENABLE); 

    TIM_SetCompare1(TIM1,0);
    TIM_SetCompare2(TIM1,0);
									  
}  

