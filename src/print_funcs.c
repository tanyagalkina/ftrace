/*
** EPITECH PROJECT, 2020
** PSU, instr
** File description:
** src
*/

#include <errno.h>
#include "../include/strace.h"

static void	print_char(char c)
{
    if (((c > 32 && c < 127) || c == ' ') && c != '\0')
        printf("%c", c);
    else if (c != '\n' && c != '\0')
        printf("\\%o", c);
}

static void put_hex(unsigned long long reg)
{
    if (reg)
        printf("%p", reg);
    else
        printf("0x0");
}

void p_str(unsigned long long reg, tools_t pr_tool)
{
    int	i;
    long c;
    if (!pr_tool.s_f) {
        put_hex(reg);
        return;
    }
    printf("\"");
    i = 0;
    c = -1;
    while ((char)c != '\0' && i < 42) {
        if ((c = ptrace(PTRACE_PEEKDATA, pr_tool.pid, \
reg, NULL)) == -1)
    return ;
    print_char(c);
    ++reg;
    ++i;
}
    printf("\"");
}

void p_str2d(unsigned long long reg, tools_t pr_tool)
{
    unsigned long long	str;
    int	i = 0;
    if (!pr_tool.s_f) {
        put_hex(reg);
        return;
    }
    printf("[");
    str = (long long)-1;
    while ((void *)str != NULL && i < 6) {
        if ((str = ptrace(PTRACE_PEEKDATA, pr_tool.pid, \
reg, NULL)) == (long)-1)
        return;
        if (str)
            p_str(str, pr_tool);
        reg += sizeof(char *);
        ++i;
    }
    printf("]");
    if (i >= 6)
        printf(" ... ");
}

void p_unimplemented(unsigned long long reg, tools_t pr_tools)
{
    (void)reg;
    printf("unimplemented");
}
