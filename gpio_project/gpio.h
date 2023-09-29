/*
    ********************************************************************************************
    *@file              gpio.h                                                                                                                    *
    *@author            Vu Quang Luong                                                                                              *
    *@date              14/09/2023                                                                                                      *
    ********************************************************************************************
*/

#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
    extern "C"{
#endif


#define LED_PC13    GET_PIN(C, 13)
#define BUTTON_A0   GET_PIN(A,0)
#define BUTTON_A1   GET_PIN(A,1)


//#include <rtthread.h>
//#include <rtdevice.h>
#include <board.h>

void Gpio_Init(void);

#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ***********************************************/
/*********************************************************************************************/
