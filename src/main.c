/*
** EPITECH PROJECT, 2020
** PSU_instr,
** File description:
** call trace
*/

#include <sys/stat.h>
#include "../include/strace.h"
#include "../include/symtrack.h"

static char **get_args(int ac, int *s_f, char **av)
{
    if (ac > 2 && !strcmp(av[1], "-s")) {
        *s_f = 1;
    }
    return ((char **)&av[1 + *s_f]);
}

static void print_help(void)
{
    printf("USAGE: ftrace <command>\n");
}

static int is_pos_int(char *av2)
{
    int pid = atoi(av2);
    int num_length = 0;

    while (pid) {
        num_length++;
        pid /= 10;
    }
    if (atoi(av2) <= 0 || strlen(av2) != (size_t)num_length) {
        fprintf(stderr, "strace: Invalid process id: '%s'\n", av2);
        exit (84);
    }
    return (1);
}

static bool file_exists(char *path)
{
    struct stat buffer;
    return (stat (path, &buffer) == 0);
}

void display_sym(sym_tab_t *list_sym_tab)
{
    sym_tab_t *tmp = list_sym_tab;

    while (tmp != NULL) {
        printf("0x%08lx %s\n", tmp->address, tmp->name);
        tmp = tmp->next;
    }
}

int main(int ac, char *av[], char **envp)
{
    int s_f = 0;
    char **args;
    sym_tab_t *sym;
    if (ac < 2) {
        print_help();
        return (84);
    }
    if (ac == 2 && (!strcmp(av[1], "--h") || !strcmp(av[1], "-h"))) {
        print_help();
        return (0);
    }
    args = (char **)&av[1];
    if (!file_exists(args[0]))
        return (84);
    if (NULL == (sym = get_symbols(args[0])))
        return (84);
    return my_ftrace(args, sym, envp);
}
