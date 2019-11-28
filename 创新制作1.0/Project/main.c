#include "system.h"
#include "Sys_Tick.h"
int16_t i=0;

int temp1,temp2,temp3,temp4,temp5,temp6,temp7;
extern uint8_t ucTemp;
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Debug_USART_Config();
	SysTick_Init();
	i2c_CfgGpio();
	TIM1_PWM_Init(499,839);
    TIM8_PWM_Init(499,839);
	TIM3_Encoder_Init();
	TIM2_Encoder_Init();
	TIM5_Encoder_Init();
	TIM14_Int_Init(499,839);
    KEY_Init();
	TIMx_Configuration();
    OLED_Init();
	OLED_Fill(0x00);//全屏灭
	delay_ms(500);		// 2s
	//Usart_SendString( DEBUG_USART,"这是一个串口中断接收回显实验\n");
    while(1)
    {
		
		if(M1_Speed<0){temp1=-T5_Encoder_Value;OLED_ShowStr(0,0,(unsigned char*)"-",2);}
		else {temp1=T5_Encoder_Value;OLED_ShowStr(0,0,(unsigned char*)"+",2);}
		if(M2_Speed<0){temp3=-T2_Encoder_Value;OLED_ShowStr(0,2,(unsigned char*)"-",2);}
		else {temp3=T2_Encoder_Value;OLED_ShowStr(0,2,(unsigned char*)"+",2);}
		if(M3_Speed<0){temp5=-T3_Encoder_Value;OLED_ShowStr(0,4,(unsigned char*)"-",2);}
		else {temp5=T3_Encoder_Value;OLED_ShowStr(0,4,(unsigned char*)"+",2);}
		
		if(i<0){temp7=-i;OLED_ShowStr(8*7,0,(unsigned char*)"-",2);}
		else{temp7=i;OLED_ShowStr(8*7,0,(unsigned char*)"+",2);}
		OLED_ShowNum(8*8,0,temp7/10,1,16);
		OLED_ShowNum(8*9,0,temp7%10,1,16);
		
		OLED_ShowNum(8*8,4,ucTemp/10,1,16);
		OLED_ShowNum(8*9,4,ucTemp%10,1,16);

		OLED_ShowNum(8,0, temp1/1000,1,16);
		OLED_ShowNum(16,0,temp1%1000/100,1,16);
		OLED_ShowNum(24,0,temp1%1000%100/10,1,16);
		OLED_ShowNum(32,0,temp1%1000%100%10,1,16);
		
		OLED_ShowNum(8,2, temp3/1000,1,16);
		OLED_ShowNum(16,2,temp3%1000/100,1,16);
		OLED_ShowNum(24,2,temp3%1000%100/10,1,16);
		OLED_ShowNum(32,2,temp3%1000%100%10,1,16);

		OLED_ShowNum(8,4, temp5/1000,1,16);
		OLED_ShowNum(16,4,temp5%1000/100,1,16);
		OLED_ShowNum(24,4,temp5%1000%100/10,1,16);
		OLED_ShowNum(32,4,temp5%1000%100%10,1,16);
    }
}




