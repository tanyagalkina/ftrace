/*
** EPITECH PROJECT, 2020
** strace
** File description:
** header
*/

#pragma once

typedef struct sig_s {
    unsigned int nb;
    unsigned int hex;
    char *macro;
}sign_t;

const sign_t sig_tab[] = {
        {0, 0x0, "INVALID"},
        {1, 0x1, "SIGHUP"},
        {2, 0x2, "SIGINT"},
        {3, 0x3, "SIGQUIT"},
        {4, 0x4, "SIGILL"},
        {5, 0x5, "SIGTRAP"},
        {6, 0x6, "SIGABRT"},
        {7, 0x7, "SIGBUS"},
        {8, 0x8, "SIGFPE"},
        {9, 0x9, "SIGKILL"},
        {10, 0x0a, "SIGUSR1"},
        {11, 0x0b, "SIGSEGV"},
        {12, 0x0c, "SIGUSR2"},
        {13, 0x0d, "SIGPIPE"},
        {14, 0x0e, "SIGALRM"},
        {15, 0x0f, "SIGTERM"},
        {16, 0x10, "SIGSTKFLT"},
        {17, 0x11, "SIGCHLD"},
        {18, 0x12, "SIGCONT"},
        {19, 0x13, "SIGSTOP"},
        {20, 0x14, "SIGTSTP"},
        {21, 0x15, "SIGTTIN"},
        {22, 0x16, "SIGTTOU"},
        {23, 0x17, "SIGURG"},
        {24, 0x18, "SIGXCPU"},
        {25, 0x19, "SIGXFSZ"},
        {26, 0x1a, "SIGVTALRM"},
        {27, 0x1b, "SIGPROF"},
        {28, 0x1c, "SIGWINCH"},
        {29, 0x1d, "SIGPOLL"},
        {30, 0x1e, "SIGPWR"},
        {31, 0x1f, "SIGSYS"},
        {32, 0x20, "SIGRTMIN-2"},
        {33, 0x21, "SIGRTMIN-1"},
        {34, 0x22, "SIGRTMIN"},
        {35, 0x23, "SIGRTMIN+1"},
        NULL
};

