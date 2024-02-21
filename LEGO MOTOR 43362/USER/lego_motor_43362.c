#include "lego_motor_43362.h"

GPIO_InitTypeDef gpio;

void Pwm_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	/* IN2 & In4 */
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;									
	gpio.GPIO_Pin = IN2_PIN | IN4_PIN;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(IN_PORT,&gpio);
	GPIO_ResetBits(IN_PORT, IN2_PIN | IN4_PIN);
	
	/* IN1 & IN3 */
	gpio.GPIO_Mode = GPIO_Mode_AF_PP;									
	gpio.GPIO_Pin = IN1_PIN | IN3_PIN;
	GPIO_Init(IN_PORT,&gpio);
	
//	uint16_t pulse;
//	pulse = 200*original_degree/9 + 1000;
	Timer4_Base_Init(0x0000, PERIOD, PRESCALE, 0x0000, 0, ENABLE);		// 10 kHz
	Timer_OCx_Init(TIM4, 4, TIM_OCMode_PWM1, ENABLE, 0, TIM_OCPolarity_High);
	Timer_OCx_Init(TIM4, 3, TIM_OCMode_PWM1, ENABLE, 0, TIM_OCPolarity_High);
	Timer_OCx_Init(TIM4, 2, TIM_OCMode_PWM1, ENABLE, 0, TIM_OCPolarity_High);
	Timer_OCx_Init(TIM4, 1, TIM_OCMode_PWM1, ENABLE, 0, TIM_OCPolarity_High);
}

// IN2 = 0, IN1 = PWM
// IN4 = 0, IN3 = PWM
void LegoMotor_SetForward(char motor){
	switch(motor){
		case 'A':
			gpio.GPIO_Mode = GPIO_Mode_Out_PP;
			gpio.GPIO_Pin = IN2_PIN;
			GPIO_Init(IN_PORT,&gpio);
			GPIO_ResetBits(IN_PORT, IN2_PIN);
			gpio.GPIO_Pin = IN1_PIN;
			gpio.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_Init(IN_PORT,&gpio);
		case 'B':
			gpio.GPIO_Mode = GPIO_Mode_Out_PP;
			gpio.GPIO_Pin = IN4_PIN;
			GPIO_Init(IN_PORT,&gpio);
			GPIO_ResetBits(IN_PORT, IN4_PIN);
			gpio.GPIO_Pin = IN3_PIN;
			gpio.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_Init(IN_PORT,&gpio);
	}								
}

// Backward = ! Forward
void LegoMotor_SetBackward(char motor){
	switch(motor){
		case 'A':
			gpio.GPIO_Mode = GPIO_Mode_Out_PP;
			gpio.GPIO_Pin = IN1_PIN;
			GPIO_Init(IN_PORT,&gpio);
			GPIO_ResetBits(IN_PORT, IN1_PIN);
			gpio.GPIO_Pin = IN2_PIN;
			gpio.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_Init(IN_PORT,&gpio);
		case 'B':
			gpio.GPIO_Mode = GPIO_Mode_Out_PP;
			gpio.GPIO_Pin = IN3_PIN;
			GPIO_Init(IN_PORT,&gpio);
			GPIO_ResetBits(IN_PORT, IN3_PIN);
			gpio.GPIO_Pin = IN4_PIN;
			gpio.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_Init(IN_PORT,&gpio);
	}	
}

void LegoMotor_SetLevel(char motor, uint8_t level){
	switch(motor){
		case 'A':
			Timer_OCx_SetPulse(TIM4,3,(uint16_t)PERIOD*level/100);
			Timer_OCx_SetPulse(TIM4,4,(uint16_t)PERIOD*level/100);
		case 'B':
			Timer_OCx_SetPulse(TIM4,1,(uint16_t)PERIOD*level/100);
			Timer_OCx_SetPulse(TIM4,2,(uint16_t)PERIOD*level/100);
	}	
}








