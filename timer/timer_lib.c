/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-09-30     QuangLuongBoss       the first version
 */

#include "timer_lib.h"

static uint8_t led_state = PIN_HIGH;

static void Timer2_IRQ_Callback(void *parameter){
    rt_pin_write(GET_PIN(C,13), led_state);
    led_state = !led_state;
}

void Timer2_BasicInit(uint32_t time){
    /* Way 1
    rt_timer_t timer2;
    timer2 = rt_timer_create("timer2", Timer2_IRQ_Callback,
                             RT_NULL, time,
                             RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    rt_timer_start(timer2);
    */

    // Way 2
    struct rt_timer timer2;
    rt_timer_init(&timer2, "timer2",   /* Timer name is timer2 */
            Timer2_IRQ_Callback, /* Callback handler for timeout */
                          RT_NULL, /* Entry parameter of the timeout function */
                          time, /* Timing length is 30 OS Tick */
                          RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER); /* One-shot timer */
    rt_timer_start(&timer2);

}

