/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    04-August-2014
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "usart.h"

/** @addtogroup Template_Project
  * @{
  */

uint16_t ucTemp;
extern int temp1,temp2,temp3,temp4,temp5,temp6;
extern int16_t i;
extern int16_t a,b;
extern int T3_Encoder_Value;
extern int T2_Encoder_Value;
extern int T5_Encoder_Value;

extern int16_t PWM1,PWM2,PWM3;
extern int16_t M1_Speed,M2_Speed,M3_Speed;
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */


/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

void DEBUG_USART_IRQHandler(void)
{
	if(USART_GetITStatus(DEBUG_USART,USART_IT_RXNE)!=RESET)
	{		
		ucTemp = USART_ReceiveData( UART5 );
	}	 
}	


void TIM8_TRG_COM_TIM14_IRQHandler(void)//5ms中断
{
	if(TIM_GetITStatus(TIM14,TIM_IT_Update)==SET) //溢出中断
	{     
        T5_Encoder_Value=TIM5_Encoder_Read();
        T2_Encoder_Value=TIM2_Encoder_Read();
        T3_Encoder_Value=TIM3_Encoder_Read();
		
		switch (ucTemp)
		{
			case 0:M1_Speed=a+3.0f;M3_Speed=b+3.0f;break;
			case 1:M1_Speed=a+2.0f;M3_Speed=b+2.0f;break;
			case 2:M1_Speed=a+0.0f;M3_Speed=b-0.0f;break;
			case 3:M1_Speed=a-2.0f;M3_Speed=b-2.0f;break;
			case 4:M1_Speed=a-3.0f;M3_Speed=b-3.0f;break;
			default:M1_Speed=a;M3_Speed=b;break;
		}
				
		M1_Speed_Ctr(M1_Speed);
        M2_Speed_Ctr(M2_Speed);
        M3_Speed_Ctr(M3_Speed);
		
	}
	TIM_ClearITPendingBit(TIM14,TIM_IT_Update);  //清除中断标志位
}


void  BASIC_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( BASIC_TIM, TIM_IT_Update) != RESET ) 
	{	
		if( Key_Scan(GPIOC,GPIO_Pin_4) == 0  )
		{
			i++;
			Car_Speed_Set(0,i,0);
		}  
		if( Key_Scan(GPIOC,GPIO_Pin_5) == 0  )
		{
			i--;
			Car_Speed_Set(0,i,0);
		}  
		TIM_ClearITPendingBit(BASIC_TIM , TIM_IT_Update);  		 
	}		 	
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
