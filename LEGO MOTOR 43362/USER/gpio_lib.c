#include "gpio_lib.h"

void Gpio_Init(void){
	GPIO_InitTypeDef gpio;
	
	/* Enable Peripheral Clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC,ENABLE);
	
	/* USART1 TX */
	gpio.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio.GPIO_Pin = USART1_TX;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART1_PORT,&gpio);
	
	/* USART1 RX */
	gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;									
	gpio.GPIO_Pin = USART1_RX;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART1_PORT,&gpio);
	
	/* SERVO */
	gpio.GPIO_Mode = GPIO_Mode_AF_PP;									
	gpio.GPIO_Pin = SERVO_PWM_PIN;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SERVO_PWM_PORT,&gpio);
	
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;									
	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&gpio);
}
