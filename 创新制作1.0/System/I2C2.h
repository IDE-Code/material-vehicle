#ifndef __I2C_H
#define	__I2C_H

#include "stm32f4xx.h"

#define OLED_I2C_WR	0		/* д����bit */
#define OLED_I2C_RD	1		/* ������bit */

/* ����I2C�������ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����4�д��뼴������ı�SCL��SDA������ */
#define OLED_GPIO_PORT_I2C	GPIOB			/* GPIO�˿� */
#define OLED_RCC_I2C_PORT 	RCC_AHB1Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define OLED_I2C_SCL_PIN		GPIO_Pin_10			/* ���ӵ�SCLʱ���ߵ�GPIO */
#define OLED_I2C_SDA_PIN		GPIO_Pin_11			/* ���ӵ�SDA�����ߵ�GPIO */


/* �����дSCL��SDA�ĺ꣬�����Ӵ���Ŀ���ֲ�ԺͿ��Ķ��� */
#if 1	/* �������룺 1 ѡ��GPIO�Ŀ⺯��ʵ��IO��д */
	#define OLED_I2C_SCL_1()  GPIO_SetBits(OLED_GPIO_PORT_I2C, OLED_I2C_SCL_PIN)		/* SCL = 1 */
	#define OLED_I2C_SCL_0()  GPIO_ResetBits(OLED_GPIO_PORT_I2C, OLED_I2C_SCL_PIN)		/* SCL = 0 */
	
	#define OLED_I2C_SDA_1()  GPIO_SetBits(OLED_GPIO_PORT_I2C, OLED_I2C_SDA_PIN)		/* SDA = 1 */
	#define OLED_I2C_SDA_0()  GPIO_ResetBits(OLED_GPIO_PORT_I2C, OLED_I2C_SDA_PIN)		/* SDA = 0 */
	
	#define OLED_I2C_SDA_READ()  GPIO_ReadInputDataBit(OLED_GPIO_PORT_I2C, OLED_I2C_SDA_PIN)	/* ��SDA����״̬ */
#else	/* �����֧ѡ��ֱ�ӼĴ�������ʵ��IO��д */
    /*��ע�⣺����д������IAR��߼����Ż�ʱ���ᱻ�����������Ż� */
	#define OLED_I2C_SCL_1()  OLED_GPIO_PORT_I2C->BSRR = OLED_I2C_SCL_PIN				/* SCL = 1 */
	#define OLED_I2C_SCL_0()  OLED_GPIO_PORT_I2C->BRR = OLED_I2C_SCL_PIN				/* SCL = 0 */
	
	#define OLED_I2C_SDA_1()  OLED_GPIO_PORT_I2C->BSRR = OLED_I2C_SDA_PIN				/* SDA = 1 */
	#define OLED_I2C_SDA_0()  OLED_GPIO_PORT_I2C->BRR = OLED_I2C_SDA_PIN				/* SDA = 0 */
	
	#define OLED_I2C_SDA_READ()  ((OLED_GPIO_PORT_I2C->IDR & OLED_I2C_SDA_PIN) != 0)	/* ��SDA����״̬ */
#endif

#define OLED_ADDRESS	0x78 //ͨ������0R����,������0x78��0x7A������ַ -- Ĭ��0x78

uint8_t OLED_CheckDevice(uint8_t _Address);//���I2C�����豸OLED
void I2C_WriteByte(uint8_t addr,uint8_t data);
void WriteCmd(unsigned char I2C_Command);
void WriteDat(unsigned char I2C_Data);
void OLED_Init(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
uint8_t OLED_Test(void) ;//OLED������
void i2c_Start(void);
void i2c_Stop(void);
void i2c_SendByte(uint8_t _ucByte);
uint8_t i2c_ReadByte(void);
uint8_t i2c_WaitAck(void);
void i2c_Ack(void);
void i2c_NAck(void);

void i2c_CfgGpio(void);
void i2c_Delay(void);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size);
u32 oled_pow(u8 m,u8 n);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size2);

#endif
