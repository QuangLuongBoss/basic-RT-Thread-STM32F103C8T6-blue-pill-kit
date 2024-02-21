#include "timer_lib.h"

volatile uint32_t timer4_ticks=0;
TIM_OCInitTypeDef tim_oc_init;

#ifdef USE_TIM2_TIM3
void Timer2_Base_Init(uint16_t timer_mode, uint16_t timer_period, uint16_t timer_prescaler, uint16_t clock_division, uint8_t repetition_counter, FunctionalState new_state){
	TIM_TimeBaseInitTypeDef tim_init_tydef;
	NVIC_InitTypeDef nvic_init_tydef;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);

	tim_init_tydef.TIM_CounterMode = timer_mode;
	tim_init_tydef.TIM_Period = timer_period;												/* Gia tri nap lai					*/
	tim_init_tydef.TIM_Prescaler = timer_prescaler;									/* Ty le chia tan	PSC + 1		*/
	tim_init_tydef.TIM_ClockDivision = clock_division;
	tim_init_tydef.TIM_RepetitionCounter = repetition_counter;			/* So lan dem lap cua Timer	*/
	TIM_TimeBaseInit(TIM2, &tim_init_tydef);
	TIM_Cmd(TIM2,new_state);

	/* NVIC	*/
	TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE);
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	nvic_init_tydef.NVIC_IRQChannel = TIM2_IRQn;
	nvic_init_tydef.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_init_tydef.NVIC_IRQChannelSubPriority = 0;
	nvic_init_tydef.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init_tydef);
}
void Timer3_Base_Init(uint16_t timer_mode, uint16_t timer_period, uint16_t timer_prescaler, uint16_t clock_division, uint8_t repetition_counter, FunctionalState new_state){
	TIM_TimeBaseInitTypeDef tim_init_tydef;
	NVIC_InitTypeDef nvic_init_tydef;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

	tim_init_tydef.TIM_CounterMode = timer_mode;
	tim_init_tydef.TIM_Period = timer_period;												/* Gia tri nap lai					*/
	tim_init_tydef.TIM_Prescaler = timer_prescaler;									/* Ty le chia tan	PSC + 1		*/
	tim_init_tydef.TIM_ClockDivision = clock_division;
	tim_init_tydef.TIM_RepetitionCounter = repetition_counter;			/* So lan dem lap cua Timer	*/
	TIM_TimeBaseInit(TIM3, &tim_init_tydef);
	TIM_Cmd(TIM3,new_state);

	/* NVIC	*/
	TIM_ITConfig(TIM3,TIM_IT_Update, ENABLE);
	TIM_ClearFlag(TIM3,TIM_FLAG_Update);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	nvic_init_tydef.NVIC_IRQChannel = TIM3_IRQn;
	nvic_init_tydef.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_init_tydef.NVIC_IRQChannelSubPriority = 0;
	nvic_init_tydef.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init_tydef);
}

void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)	!= RESET){
		timer2_ticks++;
	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
}
void TIM3_IRQHandler(void){
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)	!= RESET){
		timer3_ticks++;
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
}

void Timer2_Delay_Ms(uint32_t t){
	uint32_t start = timer2_ticks;
  uint32_t end = start +  t;
	if (start < end){ 
  	while((timer2_ticks >= start) && (timer2_ticks < end));
  }
	else{ 
    while((timer2_ticks >= start) || (timer2_ticks < end));
  }
}
void Timer3_Delay_Ms(uint32_t t){
	uint32_t start = timer3_ticks;
  uint32_t end = start +  t;
	if (start < end){ 
  	while((timer3_ticks >= start) && (timer3_ticks < end));
  }
	else{ 
    while((timer3_ticks >= start) || (timer3_ticks < end));
  }
}

#endif

/*	@Brief: parameters
	timer_mode: chon che do hoat dong
			0x0000 - count up,
			0x0010 - count down,
			0x0020 - CenterAligned1 
			0x0040 - CenterAligned2 
			0x0060 - CenterAligned3 
	timer_period: gia tri automatic reload
	timer_prescaler: ty le chia tan so vao timer
	clock_division: bo chia xung clock cho timer
			0x0000 - TIM_CKD_DIV1                       
			0x0100 - TIM_CKD_DIV2                       
			0x0200 - TIM_CKD_DIV4                       
	repetition_counter: so lan dem lap cho timer, co gia tri 8 bit
	new_state: co the la ENABLE hoac DISABLE timer
	
	@ Cach cai dat timer_period: timer_period = T.F/(k+1) - 1, trong do:
			T: thoi gian kich hoat reload
			F: tan so clock APB1, max 72 MHz
			k: he so chia tan cho vao timer4 (timer_prescaler), k: 0 -> 2^16 - 1
		=> timer_period: 0 -> 2^16 - 1
*/
void Timer4_Base_Init(uint16_t timer_mode, uint16_t timer_period, uint16_t timer_prescaler, uint16_t clock_division, uint8_t repetition_counter, FunctionalState new_state){
	TIM_TimeBaseInitTypeDef tim_init_tydef;
	NVIC_InitTypeDef nvic_init_tydef;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);

	tim_init_tydef.TIM_CounterMode = timer_mode;
	tim_init_tydef.TIM_Period = timer_period;												/* Gia tri nap lai					*/
	tim_init_tydef.TIM_Prescaler = timer_prescaler;									/* Ty le chia tan	PSC + 1		*/
	tim_init_tydef.TIM_ClockDivision = clock_division;
	tim_init_tydef.TIM_RepetitionCounter = repetition_counter;			/* So lan dem lap cua Timer	*/
	TIM_TimeBaseInit(TIM4, &tim_init_tydef);
	TIM_Cmd(TIM4,new_state);

	/* NVIC	*/
	TIM_ITConfig(TIM4,TIM_IT_Update, ENABLE);
	TIM_ClearFlag(TIM4,TIM_FLAG_Update);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	nvic_init_tydef.NVIC_IRQChannel = TIM4_IRQn;
	nvic_init_tydef.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_init_tydef.NVIC_IRQChannelSubPriority = 0;
	nvic_init_tydef.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init_tydef);
}


void TIM4_IRQHandler(void){
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)	!= RESET){
		GPIOC->ODR ^= GPIO_Pin_13;
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
}

void Timer4_Delay_Ms(uint32_t t){
	uint32_t start = timer4_ticks;
  uint32_t end = start +  t;
	if (start < end){ 
  	while((timer4_ticks >= start) && (timer4_ticks < end));
  }
	else{ 
    while((timer4_ticks >= start) || (timer4_ticks < end));
  }
}

/* @brief parameters:
	OCx: can be 1,2,3,4.
	timer_oc_mode: chon che do cho Output Compare
		TIM_OCMode_Timing  	=	0x0000
	  TIM_OCMode_Active  	=	0x0010
    TIM_OCMode_Inactive	=	0x0020
    TIM_OCMode_Toggle  	=	0x0030
    TIM_OCMode_PWM1    	=	0x0060
    TIM_OCMode_PWM2    	=	0x0070
	timer_output_state: DISABLE hoac ENABLE
	timer_oc_polarity:
		TIM_OCPolarity_High 	((uint16_t)0x0000)
    TIM_OCPolarity_Low  	((uint16_t)0x0002)

*/
void Timer_OCx_Init(TIM_TypeDef* TIMx, uint8_t OCx, uint16_t timer_oc_mode, uint16_t timer_output_state, uint16_t timer_pulse, uint16_t timer_oc_polarity){
	/* cau hinh OC channel 4 ,Mode PWM */
	tim_oc_init.TIM_OCMode = timer_oc_mode;
	tim_oc_init.TIM_OutputState = timer_output_state;
	tim_oc_init.TIM_Pulse = timer_pulse;
	tim_oc_init.TIM_OCPolarity = timer_oc_polarity;
	switch(OCx){
		case 1:	{	TIM_OC1Init(TIMx,&tim_oc_init);	break;	}
		case 2:	{	TIM_OC2Init(TIMx,&tim_oc_init);	break;	}		
		case 3:	{	TIM_OC3Init(TIMx,&tim_oc_init);	break;	}		
		case 4:	{	TIM_OC4Init(TIMx,&tim_oc_init);	break;	}		
//		default:	{
//								TIM_OC1Init(TIMx,&tim_oc_init);
//		            TIM_OC2Init(TIMx,&tim_oc_init);
//		            TIM_OC3Init(TIMx,&tim_oc_init);
//								TIM_OC4Init(TIMx,&tim_oc_init);
//							}
	}
//	TIM_ARRPreloadConfig(TIM4,ENABLE);
	TIM_CtrlPWMOutputs(TIMx, ENABLE);
}

void Timer_OCx_SetPulse(TIM_TypeDef* Timer, uint8_t OCx, uint16_t timer_pulse){
	switch(OCx){
		case 1: Timer->CCR1 = timer_pulse;
		case 2: Timer->CCR2 = timer_pulse;
		case 3: Timer->CCR3 = timer_pulse;
		case 4: Timer->CCR4 = timer_pulse;
	}
}
