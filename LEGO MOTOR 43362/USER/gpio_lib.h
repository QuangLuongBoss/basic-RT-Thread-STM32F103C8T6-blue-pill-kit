/*
	**********************************************
	*@file				gpio_lib.h						*
	*@author			Vu Quang Luong				*
	*@date				18/10/2023						*
	**********************************************
*/

#ifndef	_GPIO_
#define	_GPIO_

#ifdef __cplusplus
	extern "C"{
#endif

#include "stm32f10x.h"     
#include "stm32f10x_rcc.h"  
#include "stm32f10x_gpio.h" 

#define USART1_TX			GPIO_Pin_9				// Transmit:	TX
#define USART1_RX			GPIO_Pin_10				// Receive:		RX
#define USART1_PORT		GPIOA							// Port:			A

#define SERVO_PWM_PIN			GPIO_Pin_9		// PWM Pin
#define SERVO_PWM_PORT		GPIOB					// Port:	B

void Gpio_Init(void);

#ifdef __cplusplus
}
#endif

#endif



/***********************************************/
