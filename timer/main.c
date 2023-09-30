/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-09-29     RT-Thread    first version
 */

#include "timer_lib.h"

int main(void)
{
    rt_pin_mode( GET_PIN(C,13), PIN_MODE_OUTPUT);
    Timer2_BasicInit(500);
    while(1){

    }
    return 0;
}
