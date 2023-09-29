/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-09-28     QuangLuongBoss       the first version
 */
#ifndef APPLICATIONS_STRING_LIB_H_
#define APPLICATIONS_STRING_LIB_H_

#include "stdio.h"
#include "stdint.h"

uint8_t      String_Compare(char *s1, char *s2);
uint8_t      String_String(char *s1, char *s2);
uint8_t      String_Length(const char *s);
char*        Convert_Number_To_String(int32_t num);
#endif /* APPLICATIONS_STRING_LIB_H_ */
