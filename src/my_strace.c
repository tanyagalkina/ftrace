/*
** EPITECH PROJECT, 2020
** PSU, instr
** File description:
** src
*/

#include "../include/strace.h"
#include "../include/syscall.h"
#include "../include/signal.h"

void print_sig(siginfo_t info)
{
    char *sig;
    if (sig_tab[info.si_signo].macro && info.si_signo != 0) {
        sig = strdup(sig_tab[info.si_signo].macro);
        printf("Received signal %s\n", sig);
    }
}

static void tail(USR u_in, int pid, int status, int s_f)
{
    siginfo_t sig;
    ptrace(PTRACE_GETREGS, pid, NULL, &u_in);
    if (s_f)
        printf("Syscall %s(0) = ?\n", table[u_in.rax].name);
    else
        printf("Syscall exit_group(0x0) = ?\n");

    printf("+++ exited with %d +++\n", WEXITSTATUS(status));
}

int do_trace(int pid, int s_f, char **av)
{
    int status;
    USR u_in;
    struct rusage r_us;
    siginfo_t sig;
    wait4(pid, &status, 0, &r_us);
    while (WIFSTOPPED(status) && (WSTOPSIG(status) == SIGTRAP \
    || WSTOPSIG(status) == SIGSTOP)) {
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        wait4(pid, &status, 0, &r_us);
        ptrace(PTRACE_GETREGS, pid, NULL, &u_in);
        if_call(pid, &u_in, s_f, av[0]);
        ptrace(PTRACE_GETSIGINFO, pid, NULL, &sig);
        if (sig.si_signo != 0X05)
            print_sig(sig);
        if (WIFEXITED(status))
            break;
    }
    tail(u_in, pid, status, s_f);
    return (0);
}

void if_call(int pid, USR *regs, int s_f, char *path)
{
    (void)path;
    tools_t pr_tools;
    pr_tools.pid = pid;
    pr_tools.s_f = s_f;
    if ((int)regs->orig_rax < 300 && (int)regs->orig_rax > -1) {
    //if ((int)regs->orig_rax != -1) {
        printf("Syscall %s", table[regs->orig_rax].name);
        pr_tools.call_nb = (unsigned int)regs->orig_rax;
        if (regs->orig_rax == 59) {
            printf("(\"Syscall %s\")", path);
        } else
            p_args(regs, pr_tools);
        p_retcode(regs, s_f, pr_tools);
    }
}

int my_ftrace(int ac, char **av, char **envp, int s_f)
{
    pid_t pid;
    int ret;

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
        return do_trace(pid, s_f, av);
    }
    return (0);
}