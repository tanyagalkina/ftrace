/*
** EPITECH PROJECT, 2020
** PSU, instr
** File description:
** src
*/

#include "../include/strace.h"

/*void print_sig(siginfo_t info)
{
    char *sig;
    if (sig_tab[info.si_signo].macro && info.si_signo != 0) {
        sig = strdup(sig_tab[info.si_signo].macro);
        printf("Received signal %s\n", sig);
    }
}*/

sym_tab_t *add_node(sym_tab_t *list, sym_tab_t *new_elem)
{
    sym_tab_t *tmp = list;

    if (list == NULL)
        return (new_elem);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_elem;
    new_elem->prev = tmp;
    return (list);
}

sym_tab_t *create_node(Elf64_Sym current, uint32_t link, Elf *e)
{
    sym_tab_t *elem;

    size_t size = current.st_size;
    unsigned long addr = current.st_value;

    elem = malloc(sizeof(sym_tab_t));
    if (elem == NULL)
        return (NULL);
    elem->address = addr;
    elem->name = strdup(elf_strptr(e, link, current.st_name));
    elem->size = size;
    elem->next = NULL;
    elem->prev = NULL;
    return (elem);
}
