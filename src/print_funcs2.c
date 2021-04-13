/*
** EPITECH PROJECT, 2020
** PSU, instr
** File description:
** src
*/

#include "../include/strace.h"

void p_int(unsigned long long reg, tools_t pr_tools)
{
    if (pr_tools.s_f)
        printf("%d", (int)reg);
    else {
        if ((int)reg == 0)
            printf("0x0");
        else
            printf("%p", (int)reg);
    }
}

void p_long(unsigned long long reg, tools_t pr_tools)
{
    if (pr_tools.s_f)
        printf("%ld", (long)reg);
    else {
        if (!(long)reg)
            printf("0x0");
        else
            printf("%p", (long) reg);
    }
}

void p_uint(unsigned long long reg, tools_t pr_tools)
{
    if (pr_tools.s_f)
        printf("%u", (unsigned int)reg);
    else {
        if ((unsigned int) reg == 0)
            printf("0x0");
        else
            printf("%p", (unsigned int) reg);
    }
}

void p_ulong(unsigned long long reg, tools_t pr_tools)
{
    if (pr_tools.s_f)
        printf("%lu", (unsigned long)reg);
    else {
        if (!(unsigned long) reg)
            printf("0x0");
        else
            printf("%p", (unsigned long) reg);
    }
}

void p_pointer(unsigned long long reg, tools_t pr_tools)
{
    if (reg == 0) {
        if (pr_tools.s_f)
            printf("NULL");
        else
            printf("0x0");
    } else
        printf("%p", (void *)reg);
}
