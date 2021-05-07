/*
** EPITECH PROJECT, 2020
** PSU, instr
** File description:
** src
*/

#include "../include/strace.h"

unsigned long get_by_name(sym_tab_t *lsm, char *name)
{
    sym_tab_t *tmp = lsm;

    while (tmp != NULL) {
        if (strcmp(tmp->name, name) == 0)
            return (tmp->address);
        tmp = tmp->next;
    }
    return (0);
}

void add_to_stack_mark(flag_t *flag, sym_tab_t *entry)
{
    if (flag->mark == NULL) {
        printf("The stack flag->mark was null\n");
        flag->mark = malloc(sizeof(stack_mark_t));
        flag->mark->name = strdup(entry->name);
        flag->mark->func_addr = strdup(entry->address);
        flag->mark->func_size = entry->size;
        flag->mark->prev = NULL;
        flag->mark->next = NULL;
        flag->mark->last = flag->mark;
    }
    else {
        flag->mark->last->next = malloc(sizeof(stack_mark_t));
        flag->mark->last->next->name = entry->name;
        flag->mark->last->next->prev = flag->mark->last;
        flag->mark->last = flag->mark->last->next;
        flag->mark->last->next = NULL;
        flag->mark->last->func_size = entry->size;
        flag->mark->last->func_addr = entry->address;
    }
}

void find_by_addr(unsigned long addr, sym_tab_t *sym, flag_t *flag)
{
    sym_tab_t *tmp = sym;

    while (tmp != NULL) {
        if (addr == tmp->address && tmp->name[0] != '_') {
            printf("Entering function %s at %#lx\n",
tmp->name, tmp->address);
            add_to_stack_mark(flag, tmp);
            assert(flag->mark != NULL);
            break;
        }
        tmp = tmp->next;
    }
}

void ret_instr(USR *regs, flag_t *flag)
{
    if (regs->rip - (flag->mark->last->func_size - 1)
        == flag->mark->last->func_addr) {
        printf("Leaving function %s\n", flag->mark->last->name);
        flag->mark->last = flag->mark->last->prev;
        if (flag->mark->last)
            free(flag->mark->last->next);
    }
}
