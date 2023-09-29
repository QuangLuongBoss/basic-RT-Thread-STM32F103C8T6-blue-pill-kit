/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-09-28     QuangLuongBoss       the first version
 */

#include "usart.h"

       rt_device_t      serial;
       uint8_t usart1_receivedchar_arr[50];
static uint8_t usart1_receivedchar_arr_index = 0;
static uint8_t usart1_received_char;
       uint8_t usart1_readreceiveddata_flag = 0;

static rt_err_t UART_recv_callback(rt_device_t dev, rt_size_t size);

void Usart1_Init(uint32_t baudrate){

    serial = rt_device_find("uart1");
    struct serial_configure usart1_config = RT_SERIAL_CONFIG_DEFAULT;
    usart1_config.baud_rate = baudrate;
    rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, & usart1_config);
    rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);                          // RX IRQ
    rt_device_set_rx_indicate(serial, UART_recv_callback);
}

static rt_err_t UART_recv_callback(rt_device_t dev, rt_size_t size){        //  USART1_IRQHandler()
    rt_device_read(serial, -1, & usart1_received_char, 1);
    if(usart1_received_char == '\n'){
        usart1_receivedchar_arr[usart1_receivedchar_arr_index - 1] = '\0';
        usart1_receivedchar_arr_index = 0;
        usart1_readreceiveddata_flag  = 1;
    }
    else{
        usart1_receivedchar_arr[usart1_receivedchar_arr_index ++] = usart1_received_char;
    }
    return 0;
}

void Usart1_SendString(char *str){
    while(*str){
        rt_device_write(serial, -1, str, 1);
        str++;
    }
}

void Usart1_SendSeries(uint8_t *series, uint8_t series_length){
    while(series_length){
        rt_device_write(serial, -1, series, 1 );
        series ++;
        series_length --;
    }

}

void Usart1_Send_I32Number(int32_t num){
    Usart1_SendString(Convert_Number_To_String(num));
}
