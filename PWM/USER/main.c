#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM
#include "pwm.h" 
#include "Delay.h"
#define PRESCALER 0
#define PWM_DUTY	7199
int i=0;

int main (void){
	SystemInit();
	Fn_DELAY_Init(72);
	SystemCoreClockUpdate();
	PWM_Init(RCC_TIM4,TIM4,TIM4_CCR4_PB9,PRESCALER,PWM_DUTY);	// Basic Timer4 10 kHz

	
	//analogWrite(TIM1,1,50);
	//analogWrite(TIM2,2,30);
	//analogWrite(TIM3,3,50);
	//analogWrite(TIM1,1,10);
	//analogWrite(TIM4,4,10);
	//Fn_DELAY_ms(3000);		
	analogWrite(TIM4,4,100);
//	GPIO_InitTypeDef gpio;.
//	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
//	gpio.GPIO_Pin  = GPIO_Pin_8;
//	gpio.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB,&gpio);
	
	while(1)
	{
	//	analogWrite(TIM2,2,33);
	//	Fn_DELAY_ms(15);	
  //  analogWrite(TIM1,1,50);
	//	Fn_DELAY_ms(15);			
	}
}
