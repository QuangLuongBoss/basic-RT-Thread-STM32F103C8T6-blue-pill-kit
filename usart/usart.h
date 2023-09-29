/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-09-28     QuangLuongBoss       the first version
 */
#ifndef APPLICATIONS_USART_H_
#define APPLICATIONS_USART_H_

#include <rtthread.h>
#include <board.h>
#include <rtdevice.h>

extern uint8_t usart1_receivedchar_arr[50];
extern uint8_t usart1_readreceiveddata_flag;

extern rt_device_t serial;
extern uint8_t rk_ok_flag;

void Usart1_Init(uint32_t baudrate);
void Usart1_SendString(char *str);
void Usart1_SendSeries(uint8_t *series, uint8_t series_length);
void Usart1_Send_I32Number(int32_t num);

#endif /* APPLICATIONS_USART_H_ */
