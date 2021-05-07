/*
** EPITECH PROJECT, 2020
** strace
** File description:
** header
*/

#ifndef FTRACE_SYMTRACK_H
#define FTRACE_SYMTRACK_H

#include <libelf.h>

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

sym_tab_t *create_node(Elf64_Sym current, uint32_t link, Elf *e);
sym_tab_t *add_node(sym_tab_t *list, sym_tab_t *new_elem);
unsigned long get_by_name(sym_tab_t *lsm, char *name);
void add_to_stack_mark(flag_t *flag, sym_tab_t *entry);
void find_by_addr(unsigned long addr, sym_tab_t *sym, flag_t *flag);
sym_tab_t *get_symbols(char *path);

#endif //FTRACE_SYMTRACK_H
