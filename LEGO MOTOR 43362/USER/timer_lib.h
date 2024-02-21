/*
	********************************************************************************************
	*@file				timer_lib.h																												*
	*@author			Vu Quang Luong																								*
	*@date				24/05/2023																										*
	********************************************************************************************
*/

#ifndef __TIMER__
#define __TIMER__

#ifdef __cplusplus
	extern "C"{
#endif

#include "stm32f10x.h"     
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

extern volatile uint32_t timer4_ticks;

void Timer2_Base_Init(uint16_t timer_mode, uint16_t timer_period, uint16_t timer_prescaler, uint16_t clock_division, uint8_t repetition_counter, FunctionalState new_state);
void Timer3_Base_Init(uint16_t timer_mode, uint16_t timer_period, uint16_t timer_prescaler, uint16_t clock_division, uint8_t repetition_counter, FunctionalState new_state);
void Timer4_Base_Init(uint16_t timer_mode, uint16_t timer_period, uint16_t timer_prescaler, uint16_t clock_division, uint8_t repetition_counter, FunctionalState new_state);

void Timer_OCx_Init(TIM_TypeDef* TIMx, uint8_t OCx, uint16_t timer_oc_mode, uint16_t timer_output_state, uint16_t timer_pulse, uint16_t timer_oc_polarity);
void Timer_OCx_SetPulse(TIM_TypeDef* TIMx, uint8_t OCx, uint16_t timer_pulse);

void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);

uint32_t SysTick_Millis(void);
uint32_t Timer1_Millis(void);
uint32_t Timer2_Millis(void);
uint32_t Timer3_Millis(void);
uint32_t Timer4_Millis(void);

void Reset_Timer2_Ticks(void);
void Reset_Timer3_Ticks(void);
void Reset_Timer4_Ticks(void);

void Timer2_Delay_Ms(uint32_t t);
void Timer3_Delay_Ms(uint32_t t);
void Timer4_Delay_Ms(uint32_t t);

#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ***********************************************/
/*********************************************************************************************/

