/*
  ******************************************************************************
  * @file		pwm.h                                                              *
  * @author	Nguyen Quang Bien                                                  *
  * @date		04/08/2018                                                         *
  ******************************************************************************
*/
	
#ifndef __PWM__
#define __PWM__

#ifdef __cplusplus
 extern "C" {
#endif	 
#include "stm32f10x.h"                
#include "stm32f10x_rcc.h"              
#include "stm32f10x_gpio.h"           
#include "stm32f10x_tim.h"
	 
#define TIM1_CCR1_PA8   GPIO_Pin_8 
#define TIM1_CCR2_PA9	GPIO_Pin_9	 
#define TIM1_CCR3_PA10	GPIO_Pin_10 
#define TIM1_CCR4_PA11	GPIO_Pin_11
#define TIM1_CCR1_2_PA8_9		0x0300
#define TIM1_CCR3_4_PA10_11	0x0C00
#define TIM1_CCR_ALL 				0x0F00
	 
	 
#define TIM2_CCR1_PA0  GPIO_Pin_0
#define TIM2_CCR2_PA1  GPIO_Pin_1
#define TIM2_CCR3_PA2  GPIO_Pin_2 
#define TIM2_CCR4_PA3	 GPIO_Pin_3
#define TIM2_CCR1_2_PA0_1	0x0003
#define TIM2_CCR3_4_PA2_3	0x000C
#define TIM2_CCR_ALL 			0x000F


#define TIM3_CCR1_PA6  GPIO_Pin_6
#define TIM3_CCR2_PA7	 GPIO_Pin_7
#define TIM3_CCR3_PB0	 GPIO_Pin_0 
#define TIM3_CCR4_PB1	 GPIO_Pin_1	 
#define TIM3_CCR1_2_PA6_7	0x00C0
#define TIM3_CCR3_4_PB0_1	0x0003
#define TIM3_CCR_ALL 			0x00C3

#define TIM4_CCR1_PB6  GPIO_Pin_6
#define TIM4_CCR2_PB7	 GPIO_Pin_7
#define TIM4_CCR3_PB8	 GPIO_Pin_8 
#define TIM4_CCR4_PB9	 GPIO_Pin_9
#define TIM4_CCR1_2_PB6_7	0x00C0
#define TIM4_CCR3_4_PA8_9	0x0300
#define TIM4_CCR_ALL 			0x03C0

#define RCC_TIM1  RCC_APB2Periph_TIM1
#define RCC_TIM2	RCC_APB1Periph_TIM2 
#define RCC_TIM3	RCC_APB1Periph_TIM3
#define RCC_TIM4	RCC_APB1Periph_TIM4

void PWM1_GPIO(uint16_t GPIO_Pin);
void PWM2_GPIO(uint16_t GPIO_Pin);
void PWM3_GPIO(uint16_t GPIO_Pin);
void PWM4_GPIO(uint16_t GPIO_Pin);
	 
void PWM_Init(uint32_t RCC_Timx, TIM_TypeDef* Timer, uint16_t TIMx_CCRx_Px, uint16_t PRESCALER, uint16_t PWM_DUTY);
void analogWrite(TIM_TypeDef* timer, uint8_t channels, uint16_t high_pulse_width);
#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ********************************/
/******************************************************************************/
