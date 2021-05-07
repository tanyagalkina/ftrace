/*
** EPITECH PROJECT, 2020
** PSU, instr
** File description:
** src
*/

#include <assert.h>
#include "../include/strace.h"
#include "../include/syscall.h"

static void tail(USR u_in, int pid, int status, int s_f)
{
    ptrace(PTRACE_GETREGS, pid, NULL, &u_in);
    if (u_in.rax == 231)
        printf ("Leaving function main\n");
    printf("Syscall exit_group(0x%llx) = ?\n", (long long)WEXITSTATUS(status));
    printf("+++ exited with %d +++\n", WEXITSTATUS(status));
}

void print_syscall(USR *regs, tools_t pr_tools, prog_t prog )
{
    printf("Syscall %s", table[regs->orig_rax].name);
    pr_tools.call_nb = (unsigned int) regs->orig_rax;
    if (regs->orig_rax == 59) {
        printf("(\"Syscall %s\")", prog.path);
    } else
        p_args(regs, pr_tools);
    p_retcode(regs, 0, pr_tools);

}

void opcode_eval(prog_t prog, USR *regs, sym_tab_t *sym)
{
    static flag_t flag;
    tools_t pr_tools;
    pr_tools.pid = prog.pid;
    pr_tools.s_f = 0;
    long val = (ptrace(PTRACE_PEEKTEXT, prog.pid, regs->rip, NULL));
    unsigned char f = (unsigned)0xFF & val;

    if (f == 0xe8) {
        long offset = ptrace(PTRACE_PEEKTEXT, prog.pid, regs->rip + 1, 0);
        unsigned long addr = regs->rip + (long)(int)(offset & \
(unsigned long)0xFFFFFFFF) + 5;
        find_by_addr(addr, sym, &flag);
    }
    else if ((int)regs->orig_rax < 300 && (int)regs->orig_rax > -1)
        print_syscall(regs, pr_tools, prog);
    if (f == 0xc3 && flag.mark)
        ret_instr(regs, &flag);
}

int do_trace(prog_t prog, sym_tab_t *sym)
{
    int status;
    USR u_in;
    struct rusage r_us;
    siginfo_t sig;
    wait4(prog.pid, &status, 0, &r_us);
    printf ("Entering function main at %#lx\n", get_by_name(sym, "main"));
    while (WIFSTOPPED(status) && (WSTOPSIG(status) == SIGTRAP \
    || WSTOPSIG(status) == SIGSTOP)) {
        ptrace(PTRACE_SINGLESTEP, prog.pid, NULL, NULL);
        wait4(prog.pid, &status, 0, &r_us);
        ptrace(PTRACE_GETREGS, prog.pid, NULL, &u_in);
        ptrace(PTRACE_GETSIGINFO, prog.pid, NULL, &sig);
        if (sig.si_signo != 0X05)
            print_sig(sig);
        opcode_eval(prog, &u_in, sym);
        if (WIFEXITED(status))
            break;
    }
    tail(u_in, prog.pid, status, 0);
    return (0);
}

int my_ftrace(char **av, sym_tab_t *sym, char **envp)
{
    pid_t pid;
    int ret;
    prog_t prog;
    pid = fork();
    if (pid == -1) {
        exit (84);
    }
    if (pid == 0) {
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        ret = execve(av[0], av, envp);
        if (ret == -1) {
            perror("execve: ");
            exit (84);
        }
    } else {
        prog.pid = pid;
        prog.path = av[0];
        return do_trace(prog, sym);
    }
    return (0);
}
