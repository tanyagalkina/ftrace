/*
** EPITECH PROJECT, 2020
** strace
** File description:
** header
*/

#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <libelf.h>
#include <stdbool.h>
#include <fcntl.h>
#include <wait.h>
#include <syscall.h>
#include <unistd.h>
#include <string.h>
#include <gelf.h>

#include "../include/symtrack.h"

#define USR struct user_regs_struct

typedef struct tools_s {
    int pid;
    unsigned int call_nb;
    int s_f;
}tools_t;

typedef struct print_s {
    char *type;
    void (*func)(unsigned long long int reg, tools_t pr_tools);
}print_t;

typedef struct prog {
    char *path;
    int pid;
}prog_t;

void p_retcode(USR *regs, int s_f, tools_t pr_tools);
void p_args(USR *regs, tools_t pr_tools);
void p_str(unsigned long long reg, tools_t pr_tools);
void p_str2d(unsigned long long reg, tools_t pr_tools);
void p_unimplemented(unsigned long long reg, tools_t pr_tools);
void p_int(unsigned long long reg, tools_t pr_tools);
void p_long(unsigned long long reg, tools_t pr_tools);
void p_uint(unsigned long long reg, tools_t pr_tools);
void p_ulong(unsigned long long reg, tools_t pr_tools);
void p_pointer(unsigned long long reg, tools_t pr_tools);
int my_ftrace(char **av, sym_tab_t *sym, char **envp);
void opcode_eval(prog_t prog, USR *regs, sym_tab_t *sym);
int do_trace(prog_t prog, sym_tab_t *sym);