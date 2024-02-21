/*
	**********************************************
	*@file				lego_motor_43362.h		*
	*@author			Vu Quang Luong				*
	*@date				20/02/2024						*
	**********************************************
*/

#ifndef	__LEGO_MOTOR_43362__
#define	__LEGO_MOTOR_43362__

#ifdef __cplusplus
	extern "C"{
#endif

#include "timer_lib.h"
#include "stm32f10x_gpio.h"


/* Use L298N Module */
#define PERIOD		7199
#define PRESCALE	0
#define IN1_PIN		GPIO_Pin_9		// T4C4
#define IN2_PIN 	GPIO_Pin_8		// T4C3
#define IN3_PIN 	GPIO_Pin_7		// T4C2
#define IN4_PIN		GPIO_Pin_6		// T4C1
#define IN_PORT		GPIOB					// Timer4
#define MOTOR_A		'A'
#define MOTOR_B		'B'
#define FORWARD		'F'
#define BACKWARD	'B'

void Pwm_Init(void);
void LegoMotor_SetForward(char motor);
void LegoMotor_SetBackward(char motor);
void LegoMotor_SetLevel(char motor, uint8_t level);

#ifdef __cplusplus
}
#endif

#endif



/***********************************************/
