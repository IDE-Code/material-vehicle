#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "system.h" 

#define DEBUG_USART                             UART5
#define DEBUG_USART_CLK                         RCC_APB1Periph_UART4
#define DEBUG_USART_BAUDRATE                    115200  //´®¿Ú²¨ÌØÂÊ

#define DEBUG_USART_RX_GPIO_PORT                GPIOC
#define DEBUG_USART_RX_GPIO_CLK                 RCC_AHB1Periph_GPIOC
#define DEBUG_USART_RX_PIN                      GPIO_Pin_11
#define DEBUG_USART_RX_AF                       GPIO_AF_UART4
#define DEBUG_USART_RX_SOURCE                   GPIO_PinSource11

#define DEBUG_USART_TX_GPIO_PORT                GPIOC
#define DEBUG_USART_TX_GPIO_CLK                 RCC_AHB1Periph_GPIOC
#define DEBUG_USART_TX_PIN                      GPIO_Pin_10
#define DEBUG_USART_TX_AF                       GPIO_AF_UART4
#define DEBUG_USART_TX_SOURCE                   GPIO_PinSource10

#define DEBUG_USART_IRQHandler                  UART5_IRQHandler
#define DEBUG_USART_IRQ                 				UART4_IRQn
/************************************************************/

void Debug_USART_Config(void);
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);

void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);

#endif /* __USART1_H */

