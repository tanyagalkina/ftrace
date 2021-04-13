/*
** EPITECH PROJECT, 2020
** PSU, instr
** File description:
** src
*/

#include "../include/strace.h"

int p_flag_loop(int pid)
{
    int ret = 0;
    const char **av = {(const char **) "tanya"};
    if (getpgid(pid) < 0) {
        fprintf(stderr, \
"strace: attach: ptrace(PTRACE_SEIZE, %d): No such process\n", pid);
        exit (84);
    }
    if (-1 == (ptrace(PTRACE_SEIZE, pid, 0, PTRACE_O_TRACESYSGOOD))) {
        fprintf(stderr, "strace: attach: ptrace(PTRACE_SEIZE, %d): ", pid);
        perror("");
        exit (84);
    }
    ptrace(PTRACE_INTERRUPT, pid, 0, 0);
    ret = do_trace(pid, 0, av);
    ptrace(PTRACE_DETACH, pid, 0, 0);
    return (ret);
}