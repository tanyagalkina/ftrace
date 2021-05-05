/*
** EPITECH PROJECT, 2020
** strace
** File description:
** header
*/

#ifndef FTRACE_SYMTRACK_H
#define FTRACE_SYMTRACK_H

#include "../include/strace.h"

typedef struct sym_tab {
    unsigned long address;
    char *name;
    size_t size;
    struct sym_tab *next;
    struct sym_tab *prev;
}sym_tab_t;

typedef struct stack_mark {
    size_t func_size;
    unsigned long long int func_addr;
    char *name;
    struct stack_mark *next;
    struct stack_mark *prev;
    struct stack_mark *last;
}stack_mark_t;

typedef struct flag {
    stack_mark_t *mark;

}flag_t;

sym_tab_t *get_symbols(char *path);

#endif //FTRACE_SYMTRACK_H
