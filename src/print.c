/*
** EPITECH PROJECT, 2020
** PSU, instr
** File description:
** src
*/

#include "../include/strace.h"
#include "../include/syscall.h"
#include "../include/print.h"
#include "../include/error.h"

unsigned long long int get_reg(USR *regs, int param_nb)
{
    switch (param_nb) {
        case -1:
            return (regs->rax);
        case 0:
            return (regs->rdi);
        case 1:
            return (regs->rsi);
        case 2:
            return (regs->rdx);
        case 3:
            return (regs->rcx);
        case 4:
            return (regs->r8);
        case 5:
            return (regs->r9);
        default:
            return (0);
    }
}

static void print_arg(char *type, int nb, USR *regs, tools_t pr_tools)
{
    int i = 0;
    if (type[strlen(type) - 1] == '*'
        && strcmp(type, "char *") && strcmp(type, "char **"))
        p_pointer(get_reg(regs, nb), pr_tools);
    else
    {
        while (p_table[i + 1].type != NULL && strcmp(p_table[i].type, type))
            ++i;
        p_table[i].func(get_reg(regs, nb), pr_tools);
    }
}

void p_args(USR *regs, tools_t pr_tools)
{
    int i = 0;
    printf("(");
    while (i < table[pr_tools.call_nb].nb_par - 1)
    {
        if (i != 0)
            printf(", ");
        print_arg(table[pr_tools.call_nb].p_types[i], i, regs, pr_tools);
        ++i;
    }
    if (table[pr_tools.call_nb].nb_par \
!= 1 && table[pr_tools.call_nb].nb_par != 0)
        printf(", ");
    print_arg(table[pr_tools.call_nb].p_types[i], i, regs, pr_tools);
    printf(")");

}

static void print_s_retcode(char *type, USR *regs, tools_t pr_tools)
{
    int error = 0;

    if ((long long)regs->rax < 0) {
        if (-regs->rax <= ERRNO_MAX)
            error = -regs->rax;
        printf(" = -1 %s (%s)\n", err_table[error].macro, strerror(error));
    } else {
        printf(" = ");
        print_arg(type, -1, regs, pr_tools);
        printf("\n");
    }
}

void p_retcode(USR *regs, int s_f, tools_t pr_tools)
{
    char *type = strdup(table[(uint)regs->orig_rax].ret);

    if (regs->orig_rax == 60 || regs->orig_rax == 231) {
    //if (regs->rax == 60 || regs->rax == 231) {
        printf(" = ?\n");
        return;
    }
    if (s_f == 0 && (long long)regs->rax < 0) {
        printf(" = 0x%llx\n", -1);
    }
    else if (s_f == 0) {
        printf(" = 0x%llx\n", regs->rax);
    } else
        print_s_retcode(type, regs, pr_tools);
}

/*void	print_return_value(struct user_regs_struct *regs,
                           int pid, int is_s)
{
    struct user_regs_struct	regs2;
    int			type = table[regs->rax].ret;

    ptrace(PTRACE_GETREGS, pid, NULL, &regs2);
    if (regs->rax == 60 || regs->rax == 231)
        dprintf(1, "?\n");
    else {

            dprintf(1, "0x%llx\n", regs2.rax);
        }
}*/


