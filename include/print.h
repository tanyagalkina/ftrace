/*
** EPITECH PROJECT, 2020
** strace
** File description:
** header
*/

#pragma once
#include "strace.h"

const print_t p_table[] = {
        {"void", NULL},
        {"char *", &p_str},
        {"int[2]", &p_pointer},
        {"char **", &p_str2d},
        {"unsigned int", &p_uint},
        {"u64", &p_ulong},
        {"int", &p_int},
        {"uint32_t", &p_uint},
        {"long", &p_long},
        {"unsigned long", &p_ulong},
        {"size_t", &p_ulong},
        {"ndfs_t", &p_int},
        {"ssize_t", &p_long},
        {"caddr_t", &p_str},
        {"socklen_t", &p_ulong},
        {"uid_t", &p_int},
        {"off_t", &p_ulong},
        {"key_t", &p_ulong},
        {"gid_t", &p_int},
        {"gid_t[]", &p_pointer},
        {"cap_huser_data_t", &p_pointer},
        {"pid_t", &p_int},
        {"clock_t", &p_ulong},
        {"cap_user_header_t", &p_pointer},
        {"cpu_set_t", &p_ulong},
        {"idtype_t", &p_ulong},
        {"dev_t", &p_ulong},
        {"off64_t", &p_ulong},
        {"aio_context_t", &p_ulong},
        {"mqd_t", &p_int},
        {"key_serial_t", &p_ulong},
        {"unimplemented", &p_unimplemented},
        {"default", &p_pointer},
        {NULL, NULL}
};