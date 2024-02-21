/*
  ******************************************************************************
  * @file		pwm.c                                                              *
  * @author	Nguyen Quang Bien                                                  *
  * @date		04/08/2018                                                         *
  ******************************************************************************
*/
#include "pwm.h" 
/*
==============================Khoi tao GPIO va Timer==============================
*/
GPIO_InitTypeDef           GPIO_PWM;
TIM_TimeBaseInitTypeDef    TIM_PWM;
TIM_OCInitTypeDef          TIM_OCPWM;
/*
==============================Bien luu khoang pwm=============================
*/
volatile uint16_t Duty;
/*
==============================Hàm câu hinh chan pwm 1==============================
*/
void PWM1_GPIO(uint16_t GPIO_Pin)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_PWM.GPIO_Pin = GPIO_Pin;
	GPIO_PWM.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_PWM.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_PWM);
}
/*
==============================Hàm câu hinh chan pwm 2==============================
*/
void PWM2_GPIO(uint16_t GPIO_Pin)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_PWM.GPIO_Pin = GPIO_Pin;
	GPIO_PWM.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_PWM.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_PWM);
}
/*
==============================Hàm câu hinh chan pwm 3==============================
*/
void PWM3_GPIO(uint16_t GPIO_Pin)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
	
	if((GPIO_Pin==TIM3_CCR1_PA6)||(GPIO_Pin==TIM3_CCR2_PA7)||(GPIO_Pin==TIM3_CCR1_2_PA6_7))
	{
		GPIO_PWM.GPIO_Pin = GPIO_Pin;
		GPIO_PWM.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_PWM.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_Init(GPIOA, &GPIO_PWM);
	}
	if((GPIO_Pin==TIM3_CCR3_PB0)||(GPIO_Pin==TIM3_CCR4_PB1)||(GPIO_Pin==TIM3_CCR3_4_PB0_1))
	{
	GPIO_PWM.GPIO_Pin = GPIO_Pin;
	GPIO_PWM.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_PWM.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_PWM);
	}
	
	if(GPIO_Pin==TIM3_CCR_ALL)
	{
		GPIO_PWM.GPIO_Pin = TIM3_CCR1_2_PA6_7;
		GPIO_PWM.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_PWM.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_Init(GPIOA, &GPIO_PWM);
		
		GPIO_PWM.GPIO_Pin = TIM3_CCR3_4_PB0_1;
		GPIO_PWM.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_PWM.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_Init(GPIOB, &GPIO_PWM);
	}
}
/*
==============================Hàm câu hinh chan pwm 4==============================
*/
void PWM4_GPIO(uint16_t GPIO_Pin)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_PWM.GPIO_Pin = GPIO_Pin ;
	GPIO_PWM.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_PWM.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_PWM);
	
}
/*
==============================Hàm khoi tao PWM==============================
*/
void PWM_Init(uint32_t RCC_Timx, TIM_TypeDef* Timer, uint16_t TIMx_CCRx_Px, uint16_t PRESCALER, uint16_t PWM_DUTY)
{
	Duty = PWM_DUTY;
	if(RCC_Timx == RCC_TIM1)
		RCC_APB2PeriphClockCmd(RCC_Timx, ENABLE);
	else
		RCC_APB1PeriphClockCmd(RCC_Timx, ENABLE);
	if(Timer == TIM1)
		PWM1_GPIO(TIMx_CCRx_Px);
	else if(Timer == TIM2)
		PWM2_GPIO(TIMx_CCRx_Px);
	else if(Timer == TIM3)
		PWM3_GPIO(TIMx_CCRx_Px);
	else 
		PWM4_GPIO(TIMx_CCRx_Px);
	
	TIM_PWM.TIM_Prescaler = PRESCALER;  
	TIM_PWM.TIM_Period = PWM_DUTY;
	TIM_PWM.TIM_ClockDivision = 0;
	TIM_PWM.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(Timer, &TIM_PWM);
	
	TIM_OCStructInit(&TIM_OCPWM);
	TIM_OCPWM.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCPWM.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCPWM.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCPWM.TIM_OutputNState = TIM_OutputNState_Enable; 
	TIM_OCPWM.TIM_Pulse = 0;
	
	
	TIM_OC1Init(Timer, &TIM_OCPWM);  
	TIM_OC1PreloadConfig(Timer, TIM_OCPreload_Enable);

	TIM_OC2Init(Timer, &TIM_OCPWM);
	TIM_OC2PreloadConfig(Timer, TIM_OCPreload_Enable);

	TIM_OC3Init(Timer, &TIM_OCPWM);
	TIM_OC3PreloadConfig(Timer, TIM_OCPreload_Enable);

	TIM_OC4Init(Timer, &TIM_OCPWM);
	TIM_OC4PreloadConfig(Timer, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(Timer, ENABLE);
	TIM_Cmd(Timer, ENABLE);
	TIM_CtrlPWMOutputs(Timer, ENABLE);
}
/*
==============================Hàm analogWrite==============================
*/
void analogWrite(TIM_TypeDef* Timer, uint8_t channels, uint16_t high_pulse_width)
{
	switch(channels)
	{
		case 1:
			Timer->CCR1 = high_pulse_width * (Duty / 100);  
		break;
		
		case 2:
			Timer->CCR2 = high_pulse_width * (Duty / 100);  
		break;
		
		case 3:
			Timer->CCR3 = high_pulse_width * (Duty / 100);  
		break;
			
		case 4:
			Timer->CCR4 = high_pulse_width * (Duty / 100);  
		break;
	}
}

/********************************* END OF FILE ********************************/
/******************************************************************************/
