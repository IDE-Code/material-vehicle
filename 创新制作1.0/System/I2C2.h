#ifndef __I2C_H
#define	__I2C_H

#include "stm32f4xx.h"

#define OLED_I2C_WR	0		/* 写控制bit */
#define OLED_I2C_RD	1		/* 读控制bit */

/* 定义I2C总线连接的GPIO端口, 用户只需要修改下面4行代码即可任意改变SCL和SDA的引脚 */
#define OLED_GPIO_PORT_I2C	GPIOB			/* GPIO端口 */
#define OLED_RCC_I2C_PORT 	RCC_AHB1Periph_GPIOB		/* GPIO端口时钟 */
#define OLED_I2C_SCL_PIN		GPIO_Pin_10			/* 连接到SCL时钟线的GPIO */
#define OLED_I2C_SDA_PIN		GPIO_Pin_11			/* 连接到SDA数据线的GPIO */


/* 定义读写SCL和SDA的宏，已增加代码的可移植性和可阅读性 */
#if 1	/* 条件编译： 1 选择GPIO的库函数实现IO读写 */
	#define OLED_I2C_SCL_1()  GPIO_SetBits(OLED_GPIO_PORT_I2C, OLED_I2C_SCL_PIN)		/* SCL = 1 */
	#define OLED_I2C_SCL_0()  GPIO_ResetBits(OLED_GPIO_PORT_I2C, OLED_I2C_SCL_PIN)		/* SCL = 0 */
	
	#define OLED_I2C_SDA_1()  GPIO_SetBits(OLED_GPIO_PORT_I2C, OLED_I2C_SDA_PIN)		/* SDA = 1 */
	#define OLED_I2C_SDA_0()  GPIO_ResetBits(OLED_GPIO_PORT_I2C, OLED_I2C_SDA_PIN)		/* SDA = 0 */
	
	#define OLED_I2C_SDA_READ()  GPIO_ReadInputDataBit(OLED_GPIO_PORT_I2C, OLED_I2C_SDA_PIN)	/* 读SDA口线状态 */
#else	/* 这个分支选择直接寄存器操作实现IO读写 */
    /*　注意：如下写法，在IAR最高级别优化时，会被编译器错误优化 */
	#define OLED_I2C_SCL_1()  OLED_GPIO_PORT_I2C->BSRR = OLED_I2C_SCL_PIN				/* SCL = 1 */
	#define OLED_I2C_SCL_0()  OLED_GPIO_PORT_I2C->BRR = OLED_I2C_SCL_PIN				/* SCL = 0 */
	
	#define OLED_I2C_SDA_1()  OLED_GPIO_PORT_I2C->BSRR = OLED_I2C_SDA_PIN				/* SDA = 1 */
	#define OLED_I2C_SDA_0()  OLED_GPIO_PORT_I2C->BRR = OLED_I2C_SDA_PIN				/* SDA = 0 */
	
	#define OLED_I2C_SDA_READ()  ((OLED_GPIO_PORT_I2C->IDR & OLED_I2C_SDA_PIN) != 0)	/* 读SDA口线状态 */
#endif

#define OLED_ADDRESS	0x78 //通过调整0R电阻,屏可以0x78和0x7A两个地址 -- 默认0x78

uint8_t OLED_CheckDevice(uint8_t _Address);//检测I2C总线设备OLED
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
uint8_t OLED_Test(void) ;//OLED检测测试
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
