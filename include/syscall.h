/*
** EPITECH PROJECT, 2020
** strace
** File description:
** header
*/

#pragma once

typedef struct call_s {
    int nb;
    char *name;
    int nb_par;
    char *p_types[6];
    char *ret;
}call_t;

static const call_t table[] = {
{0, "read", 3, {"int", "char *", "size_t"}, "ssize_t"},
{1, "write", 3, {"int", "char *", "size_t"}, "ssize_t"},
{2, "open", 2, {"char *", "int"}, "int"},
{3, "close", 1, {"int"}, "int"},
{4, "stat", 2, {"char *", "struct stat *"}, "int"},
{5, "fstat", 2, {"int", "struct stat *"}, "int"},
{6, "lstat", 2, {"char *", "struct stat *"}, "int"},
{7, "poll", 3, {"struct pollfd *", "nfds_t", "int"}, "int"},
{8, "lseek", 3, {"int", "off_t", "int"}, "off_t"},
{9, "mmap", 6, {"void *", "size_t", "int", \
"int", "int", "off_t"}, "void *"},
{10, "mprotect", 3, {"void *", "size_t", "int"}, "int"},
{11, "munmap", 2, {"void *", "size_t"}, "int"},
{12, "brk", 1, {"int"}, "void *"},
{13, "rt_sigaction", 3, {"int", "struct sigaction *", \
"struct sigaction *"}, "int"},
{14, "rt_sigprocmask", 3, {"int", "sigset_t *", "sigset_t *"}, "int"},
{15, "rt_sigreturn", 1, {"unsigned long"}, "int"},
{16, "ioctl", 2, {"int", "int"}, "int"},
{17, "pread64", 4, {"int", "void *", \
"size_t", "off_t"}, "ssize_t"},
{18, "pwrite64", 4, {"int", "void *", \
"size_t", "off_t"}, "ssize_t"},
{19, "readv", 3, {"int", "struct  iovec *", "int"}, "ssize_t"},
{20, "writev", 3, {"int", "struct  iovec *", "int"}, "ssize_t"},
{21, "access", 2, {"char *", "int"}, "int"},
{22, "pipe", 1, {"int[2]"},  "int"},
{23, "select", 5, {"int", "fd_set *", "fd_set *", "fd_set *", \
"stuct timeval *"}, "int"},
{24, "sched_yield", 0, {"void"}, "int"},
{25, "mremap", 4, {"void *", "size_t", "size_t", "int"}, "void *"},
{26, "msync", 3, {"void *", "size_t", "int"}, "int"},
{27, "mincore", 3, {"void *", "size_t", "unsigned char *"}, "int"},
{28, "madvise", 3, {"void *", "size_t", "int"}, "int"},
{29, "shmget", 3, {"key_t", "size_t", "int"}, "int"},
{30, "shmat", 3, {"int", "void *", "int"}, "void *"},
{31, "shmctl", 3, {"int", "int", "struct shmid_ds *"}, "int"},
{32, "dup", 1, {"int"}, "int"},
{33, "dup2", 2, {"int", "int"}, "int"},
{34, "pause", 0, {"void"}, "int"},
{35, "nanosleep", 2, {"struct timespec *", "struct timespec *"}, "int"},
{36, "getitimer", 2, {"int", "struct itimervalq *"}, "int"},
{37, "alarm", 1, {"unsigned int"}, "unsigned int"},
{38, "setitimer", 3, {"int", "struct itimerval *", \
"struct itimerval *"}, "int"},
{39, "getpid", 0, {"void""void"}, "pid_t"},
{40, "sendfile", 4, {"int", "int", "off_t *", "size_t"}, "ssize_t"},
{41, "socket", 3, {"int", "int", "int"}, "int"},
{42, "connect", 3, {"int", "struct sockaddr *", "socklen_t"}, "int"},
{43, "accept", 3, {"int", "struct sockaddr *", "socklen_t"}, "int"},
{44, "sendto", 6, {"int", "void *", "size_t", "int", \
"struct sockaddr *", "socklen_t"}, "ssize_t"},
{45, "recvfrom", 6, \
{"int", "void *", "size_t", "int", "struct sockaddr *", \
"socklen_t *"}, "ssize_t"},
{46, "sendmsg", 3, {"int", "struct msghdr *", "int"}, "ssize_t"},
{47, "recvmsg", 3, {"int", "struct msghdr *", "int"}, "ssize_t"},
{48, "shutdown", 2, {"int", "int"}, "int"},
{49, "bind", 3, {"int", "struct sockaddr *", "socklen_t"}, "int"},
{50, "listen", 2, {"int", "int"}, "int"},
{51, "getsockname", 3, {"int", "struct sockaddr *", "socklen_t *"}, "int"},
{52, "getpeername", 3, {"int", "struct sockaddr *", "socklen_t *"}, "int"},
{53, "socketpair", 4, {"int", "int", "int", "int[2]"}, "int"},
{54, "setsockopt", 5, {"int", "int", "int", "void *", "socklen_t"}, "int"},
{55, "getsockopt", 5, {"int", "int", "int", "void *", "socklen_t"}, "int"},
{56, "clone", 2, {"int *", "struct stat *"}, "int"},
{57, "fork", 0, {"void"}, "pid_t"},
{58, "vfork", 0, {"void"}, "pid_t"},
{59, "execve", 3, {"char *", "char **", "char **"}, "int"},
{60, "exit", 1, {"int"}, "void"},
{61, "wait4", 4, {"pid_t", "int *", "int", "struct rusage *"}, "pid_t"},
{62, "kill", 2, {"pid_t", "int"}, "int"},
{63, "uname", 1, {"struct utsname *"}, "int"},
{64, "semget", 3, {"key_t", "int", "int"}, "int"},
{65, "semop", 3, {"int", "struct sembuf *", "unsigned int"}, "int"},
{66, "semctl", 3, {"int", "int", "int"}, "int"},
{67, "shmdt", 1, {"void *"}, "int"},
{68, "msgget", 2, {"key_t", "int"}, "int"},
{69, "msgsnd", 4, {"int", "void *", "size_t", "int"}, "int"},
{70, "msgrcv", 5, {"int", "void *", "size_t", "long", \
"int"}, "ssize_t"},
{71, "msgctl", 3, {"int", "int", "struct msqid_ds *"}, "int"},
{72, "fcntl", 2, {"int", "int"}, "int"},
{73, "flock", 2, {"int", "int"}, "int"},
{74, "fsync", 1, {"int"}, "int"},
{75, "fdatasync", 1, {"int"}, "int"},
{76, "truncate", 2, {"char *", "off_t"}, "int"},
{77, "ftruncate", 2, {"int", "off_t"}, "int"},
{78, "getdents", 3,
{"unsigned int", "struct linux_dirent *", "unsigned int"}, "int"},
{79, "getcwd", 2, {"char *", "unsigned long"}, "long"},
{80, "chdir", 1, {"char *"}, "int"},
{81, "fchdir", 1, {"int"}, "int"},
{82, "rename", 2, {"char *", "char *"}, "int"},
{83, "mkdir", 2, {"char *", "mode_t"}, "int"},
{84, "rmdir", 1, {"char *"}, "int"},
{85, "creat", 2, {"char *", "mode_t"}, "int"},
{86, "link", 2, {"char *", "char *"}, "int"},
{87, "unlink", 1, {"char *"}, "int"},
{88, "symlink", 2, {"char *", "char *"}, "int"},
{89, "readlink", 3, {"char *", "char *", "size_t"}, "ssize_t"},
{90, "chmod", 2, {"char *", "mode_t"}, "int"},
{91, "fchmod", 2, {"int", "mode_t"}, "int"},
{92, "chown", 3, {"char *", "uid_t", "gid_t"}, "int"},
{93, "fchown", 3, {"int", "uid_t", "gid_t"}, "int"},
{94, "lchown", 3, {"char *", "uid_t", "gid_t"}, "int"},
{95, "umask", 1, {"mode_t"}, "mode_t"},
{96, "gettimeofday", 2, {"struct timeval *", "struct timezone *"}, "int"},
{97, "getrlimit", 2, {"int", "struct rlimit *"}, "int"},
{98, "getrusage", 2, {"int", "struct rusage *"}, "int"},
{99, "sysinfo", 1, {"struct sysinfo *"}, "int"},
{100, "times", 1, {"struct tms *"}, "clock_t"},
{101, "ptrace", 4, \
{"int", "pid_t", "void *", "void *"}, "long"},
{102, "getuid", 0, {"void"}, "uid_t"},
{103, "syslog", 3, {"int", "char *", "int"}, "int"},
{104, "getgid", 0, {"void"}, "gid_t"},
{105, "setuid", 1, {"uid_t"}, "int"},
{106, "setgid", 1, {"gid_t"}, "int"},
{107, "geteuid", 0, {"void"}, "uid_t"},
{108, "getegid", 0, {"void"}, "gid_t"},
{109, "setpgid", 2, {"pid_t", "pid_t"}, "int"},
{110, "getppid", 0, {"void"}, "pid_t"},
{111, "getpgrp", 0, {"void"}, "pid_t"},
{112, "setsid", 0, {"void"}, "pid_t"},
{113, "setreuid", 2, {"uid_t", "uid_t"}, "int"},
{114, "setregid", 2, {"gid_t", "gid_t"}, "int"},
{115, "getgroups", 2, {"int", "gid_t[]"}, "int"},
{116, "setgroups", 2, {"size_t", "gid_t *"}, "int"},
{117, "setresuid", 3, {"uid_t", "uid_t", "uid_t"}, "int"},
{118, "getresuid", 3, {"uid_t *", "uid_t *", "uid_t *"}, "clock_t"},
{119, "setresgid", 3, {"gid_t", "gid_t", "gid_t"}, "int"},
{120, "getresgid", 3, {"gid_t *", "gid_t *", "gid_t *"}, "int"},
{121, "getpgid", 1, {"pid_t"}, "pid_t"},
{122, "setfsuid", 1, {"uid_t"}, "int"},
{123, "setfsgid", 1, {"uid_t"}, "int"},
{124, "getsid", 1, {"pid_t"}, "pid_t"},
{125, "capget", 2, {"cap_user_header_t", "cap_huser_data_t"}, "int"},
{126, "capset", 2, {"cap_user_header_t", "cap_huser_data_t"}, "int"},
{127, "sigpending", 1, {"sigset_t *"}, "int"},
{128, "sigtimedwait", 3, \
{"sigset_t *", "siginfo_t *", "struct timespec *"}, "int"},
{129, "sys_rt_sigqueueinfo", 3, {"int", "int", "siginfo_t *"}, "long"},
{130, "sigsuspend", 1, {"sigset_t *"}, "int"},
{131, "sigaltstack", 2, {"stack_t *", "stack_t *"}, "int"},
{132, "utime", 2, {"char *", "struct utimbuf *"}, "int"},
{133, "mknod", 3, {"char *", "mode_t", "dev_t"}, "int"},
{134, "uselib", 1, {"char *"}, "int"},
{135, "personality", 1, {"unsigned long"}, "int"},
{136, "ustat", 2, {"dev_t", "struct ustat *"}, "int"},
{137, "statfs", 2, {"char *", "struct statfs *"}, "int"},
{138, "fstatfs", 2, {"int", "struct statfs *"}, "int"},
{139, "sysfs", 3, {"struct tms *"}, "clock_t"},
{140, "getpriority", 2, {"int", "int"}, "int"},
{141, "setpriority", 3, {"int", "int", "int"}, "int"},
{142, "sched_setparam", 2, {"pid_t", "struct sched_param *"}, "int"},
{143, "sched_getparam", 2, {"pid_t", "struct sched_param *"}, "int"},
{144, "sched_setscheduler", 3, \
{"pid_t", "int", "struct sched_param *"}, "int"},
{145, "sched_getscheduler", 1, {"pid_t"}, "int"},
{146, "sched_get_priority_max", 1, {"int"}, "int"},
{147, "sched_get_priority_min", 1, {"int"}, "int"},
{148, "sched_rr_get_interval", 2, {"pid_t", "struct timespec *"}, "int"},
{149, "mlock", 2, {"void *", "size_t"}, "int"},
{150, "munlock", 2, {"void *", "size_t"}, "int"},
{151, "mlockall", 1, {"int"}, "int"},
{152, "munlockall", 0, {"void"}, "int"},
{153, "vhangup", 0, {"void"}, "int"},
{154, "modify_ldt", 3, {"int", "void *", "unsigned long"}, "int"},
{155, "pivot_root", 2, {"char *", "char *"}, "int"},
{156, "_sysctl", 1, {"struct __sysctl_args *"}, "int"},
{157, "prctl", 5, {"int", "unsigned long", "unsigned long", \
"unsigned long", "unsigned long"}, "int"},
{158, "arch_prctl", 2, {"int", "unsigned long *"}, "int"},
{159, "adjtimex", 1, {"struct timex *"}, "int"},
{160, "setrlimit", 2, {"int", "struct rlimit *"}, "int"},
{161, "chroot", 1, {"char *"}, "int"},
{162, "sync", 0, {"void"}, "void"},
{163, "acct", 1, {"char *"}, "int"},
{164, "settimeofday", 2, {"struct timeval *", "struct timezone *"}, "int"},
{165, "mount", 5, {"char *", "char *", "char *", \
"unsigned long", "void *"}, "int"},
{166, "umount2", 2, {"char *", "int"}, "int"},
{167, "swapon", 2, {"char *", "int"}, "int"},
{168, "swapoff", 1, {"char *"}, "int"},
{169, "reboot", 4, {"int", "int", "int", "void *"}, "int"},
{170, "sethostname", 2, {"char *", "size_t"}, "int"},
{171, "setdomainname", 2, {"char *", "size_t"}, "int"},
{172, "iopl", 1, {"int"}, "int"},
{173, "ioperm", 3, {"unsigned long", "unsigned long", "int"}, "int"},
{174, "create_module", 2, {"char *", "size_t"}, "caddr_t"},
{175, "init_module", 3, {"void *", "unsigned long", "char *"}, "int"},
{176, "delete_module", 2, {"char *", "int"}, "int"},
{177, "get_kernel_syms", 1, {"struct kernel_sym *"}, "int"},
{178, "query_module", 5, {"char *", "int", "void *", "size_t", \
"size_t"}, "int"},
{179, "quotactl", 4, {"int", "char *", "int", "caddr_t"}, "int"},
{180, "nfsservctl", 3, {"int", "struct nfsctl_arg *", \
"union nfsctl_res *"}, "int"},
{181, "getpmsg", 1, {"struct tms *"}, "clock_t"},
{182, "putpmsg", 1, {"struct tms *"}, "clock_t"},
{183, "afs_syscall", 1, {"struct tms *"}, "clock_t"},
{184, "tuxcall", 1, {"struct tms *"}, "clock_t"},
{185, "security", 1, {"struct tms *"}, "clock_t"},
{186, "gettid", 0, {"void"}, "pid_t"},
{187, "readahead", 3, {"int", "off64_t", "size_t"}, "ssize_t"},
{188, "setxattr", 5,
                        {"char *", "char *", "void *", "size_t", "int"}, "int"},
{189, "lsetxattr", 5, {"char *", "char *", "void *", "size_t", "int"}, "int"},
{190, "fsetxattr", 5, {"int", "char *", "void *", "size_t", "int"}, "int"},
{191, "getxattr", 4, {"char *", "char *", "void *", "size_t"}, "ssize_t"},
{192, "lgetxattr", 4, {"char *", "char *", "void *", "size_t"}, "ssize_t"},
{193, "fgetxattr", 4, {"int", "char *", "void *", "size_t"}, "ssize_t"},
{194, "listxattr", 3, {"char *", "char *", "size_t"}, "ssize_t"},
{195, "llistxattr", 3, {"char *", "char *", "size_t"}, "ssize_t"},
{196, "flistxattr", 3, {"int", "char *", "size_t"}, "ssize_t"},
{197, "removexattr", 2, {"char *", "char *"}, "int"},
{198, "lremovexattr", 2, {"char *", "char *"}, "int"},
{199, "fremovexattr", 2, {"int", "char *"}, "int"},
{200, "tkill", 2, {"int", "int"}, "int"},
{201, "time", 1, {"time_t"}, "time_t"},
{202, "futex", 6, \
{"int *", "int", "int", "struct timespec *", "int *", "int"}, "int"},
{203, "sched_setaffinity", 3, {"pid_t", "size_t", "cpu_set_t *"}, "int"},
{204, "sched_getaffinity", 3, {"pid_t", "size_t", "cpu_set_t *"}, "int"},
{205, "set_thread_area", 1, {"struct user_desc *"}, "int"},
{206, "io_setup", 2, {"unsigned int", "aio_context_t *"}, "int"},
{207, "io_destroy", 1, {"aio_context_t"}, "int"},
{208, "io_getevents", 5, {"aio_context_t", "long", \
"long", "struct io_event *", "struct timespec *"}, "int"},
{209, "io_submit", 3, {"aio_context_t", "long", "struct iocb **"}, "int"},
{210, "io_cancel", 3, \
{"aio_context_t", "struct iocb *", "struct io_event *"}, "int"},
{211, "get_thread_area", 1, {"struct user_desc *"}, "int"},
{212, "lookup_dcookie", 3, {"u64", "char *", "size_t"}, "int"},
{213, "epoll_create", 1, {"int"}, "int"},
{214, "epoll_ctl_old", 0, {"void"}, "unimplemented"},
{215, "epoll_wait_old", 0, {"void"}, "unimplemented"},
{216, "remap_file_pages", 5,  {"void *", "size_t", "int", \
"ssize_t", "int"}, "int"},
{217, "getdents64", 3, {"unsigned int", "struct linux_dirent *", \
"unsigned int"}, "int"},
{218, "set_tid_address", 1, {"int *"}, "long"},
{219, "restart_syscall", 2, {"int", "int"}, "int"},
{220, "semtimedop", 4, {"int", "struct sembuf *", "unsigned int", \
"struct timespec *"}, "int"},
{221, "fadvise64", 4, {"int", "off_t", "off_t", "int"}, "int"},
{222, "timer_create", 3, {"clockid_t", "struct sigevent *", \
"time_t *"}, "int"},
{223, "timer_settime", 4, {"timer_t", "int", "struct itimerspec *", \
"struct itimerspec *"}, "int"},
{224, "timer_gettime", 2, {"timer_t", "struct itimerspec *"}, "int"},
{225, "timer_getoverrun", 1, {"timer_t"}, "int"},
{226, "timer_delete", 1, {"timer_t"}, "int"},
{227, "clock_settime", 2, {"clockid_t", "struct timespec *"}, "int"},
{228, "clock_gettime", 2, {"clockid_t", "struct timespec *"}, "int"},
{229, "clock_getres", 2, {"clockid_t", "struct timespec *"}, "int"},
{230, "clock_nanosleep", 4, {"clockid_t", "int", "struct timespec *", \
"struct timespec *"}, "int"},
{231, "exit_group", 1, {"int"}, "int"},
{232, "epoll_wait", 4, {"int", "struct epoll_event *", "int", "int"}, "int"},
{233, "epoll_ctl", 4, {"int", "int", "int", "struct epoll_event *"}, "int"},
{234, "tgkill", 3, {"int", "int", "int"}, "int"},
{235, "utimes", 2, {"char *", "struct timeval *"}, "int"},
{236, "vserver", 2, {"int", "int"}, "int"},
{237, "mbind", 6, {"void *", "unsigned long", \
"int", "unsigned long *", "unsigned long", "unsigned int"}, "int"},
{238, "set_mempolicy", 3, {"int", "unsigned long *", "unsigned long"}, "int"},
{239, "get_mempolicy", 5, {"int *", "unsigned long *", \
"unsigned long", "unsigned long", "unsigned long"}, "int"},
{240, "mq_open", 2, {"int", "int"}, "int"},
{241, "mq_unlink", 1, {"char *"}, "int"},
{242, "mq_timedsend", 5, {"mqd_t", "char *", "size_t", \
"unsigned int", "struct timespec *"}, "int"},
{243, "mq_timedreceive", 5, {"mqd_t", "char *", "size_t", \
"unsigned int", "struct timespec *"}, "int"},
{244, "mq_notify", 2, {"mqd_t", "struct sigevent *"}, "int"},
{245, "mq_getsetattr", 3, {"mqd_t", "struct mq_attr *", \
"struct mq_attr *"}, "int"},
{246, "kexec_load", 4, {"unsigned long", "unsigned long", \
"struct kexec_segment *", "unsigned long"}, "int"},
{247, "waitid", 4, {"idtype_t", "id_t", "siginfo_t", "int"}, "int"},
{248, "add_key", 5, {"char *", "char *", "void *", "size_t", \
"key_serial_t"}, "key_serial_t"},
{249, "request_key", 4, {"char *", "char *", "char *", \
"key_serial_t"}, "key_serial_t"},
{250, "keyctl", 1, {"int"}, "int"},
{251, "ioprio_set", 3, {"int", "int", "int"}, "int"},
{252, "ioprio_get", 2, {"int", "int"}, "int"},
{253, "inotify_init", 0, {"void"}, "int"},
{254, "inotify_add_watch", 3, {"int", "char *", "uint32_t"}, "int"},
{255, "inotify_rm_watch", 2, {"int", "int"}, "int"},
{256, "migrate_pages", 4, {"int", "unsigned long", "unsigned long *", \
"unsigned long *"}, "long"},
{257, "openat", 3, {"int", "char *", "int"}, "int"},
{258, "mkdirat", 3, {"int", "char *", "mode_t"}, "int"},
{259, "mknodat", 4, {"int", "char *", "mode_t", "dev_t"}, "int"},
{260, "fchownat", 5, {"int", "char *", "uid_t", "gid_t", "int"}, "int"},
{261, "futimesat", 3, {"int", "char *", "struct timeval *"}, "int"},
{262, "newfstatat", 4, {"int", "char *", "struct stat *", "int"}, "int"},
{263, "unlinkat", 3, {"int", "char *", "int"}, "int"},
{264, "renameat", 4, {"int", "char *", "int", "char *"}, "int"},
{265, "linkat", 5, {"int", "char *", "int", "char *", "int"}, "int"},
{266, "symlinkat", 3, {"char *", "int", "char *"}, "int"},
{267, "readlinkat", 4, {"int", "char *", "char *", "size_t"}, "int"},
{268, "fchmodat", 4, {"int", "char *", "mode_t", "int"}, "int"},
{269, "faccessat", 4, {"int", "char *", "int", "int"}, "int"},
{270, "pselect6", 6, {"int", "fd_set *", "fd_set *", "fd_set *", \
"struct timespec *", "sigset_t"}, "int"},
{271, "ppoll", 4, {"struct pollfd *", "nfds_t", \
"struct timespec *", "sigset_t *"}, "int"},
{272, "unshare", 1, {"int"}, "int"},
{273, "set_robust_list", 2, {"struct robust_list_head *", "size_t"}, "long"},
{274, "get_robust_list", 5, {"int", "char *", "int", \
"char *", "int"}, "int"},
{275, "splice", 6, {"int", "loff_t *", "int", "loff_t *", \
"size_t", "unsigned int"}, "ssize_t"},
{276, "tee", 4, {"int", "int", "size_t", "unsigned int"}, "ssize_t"},
{277, "sync_file_range", 4, {"int", "off64_t", "off64_t", \
"unsigned int"}, "int"},
{278, "vmsplice", 4, {"int", "struct iovec *", "unsigned long", \
"unsigned int"}, "ssize_t"},
{279, "move_pages", 6, {"int", "unsigned long", "void **", \
"int *", "int *", "int"}, "long"},
{280, "utimensat", 4, {"int", "char *", "struct timespec[]", "int"}, "int"},
{281, "epoll_pwait", 4, {"int", "struct epoll_event *", "int", \
"int", "sigset_t"}, "int"},
{282, "signalfd", 3, {"int", "sigset_t *", "int"}, "int"},
{283, "timerfd_create", 2, {"int", "int"}, "int"},
{284, "eventfd", 2, {"unsigned int", "int"}, "int"},
{285, "fallocate", 4, {"int", "int", "off_t", "off_t"}, "int"},
{286, "timerfd_settime", 4, {"int", "int", "struct itimerspec *", \
"struct itimerspec *"}, "int"},
{287,  "timerfd_gettime", 2, {"int", "struct itimerspec *"}, "int"},
{288, "accept4", 4, {"int", "struct sockaddr *", "socklen_t", "int"}, "int"},
{289, "signalfd4", 3, {"int", "sigset_t *", "int"}, "int"},
{290, "eventfd2", 4, {"int", "char *", "struct timespec *", "int"}, "int"},
{291, "epoll_create1", 1, {"int"}, "int"},
{292, "dup3", 2, {"int", "int"}, "int"},
{293, "pipe2", 2, {"int[2]", "int"}, "int"},
{294, "inotify_init1", 1, {"int"}, "int"},
{295, "preadv", 4, {"int", "struct iovec *", "int", "off_t"}, "ssize_t"},
{296, "pwritev", 3, {"int", "struct iovec *", "int"}, "ssize_t"},
{297, "sys_rt_tgsigqueueinfo", 3, {"int", "int", "siginfo_t *"}, "long"},
{298, "perf_event_open", 4, {"int", "struct sockaddr *", \
"socklen_t", "int"}, "int"},
{299, "recvmmsg", 5, {"int", "struct mmsghdr *", "unsigned int", \
"unsigned int", "struct timespec *"}, "int"},
{300, "fanotify_init", 4, {"int", "struct sockaddr *", "socklen_t", \
"int"}, "int"},
{301, "fanotify_mark", 5, {"int", "unsigned int", "uint64_t", "int", \
"const char *"}, "int"},
{302, "prlimit", 4, {"pid_t", "int", "struct rlimit *", \
"struct rlimit *"}, "int"},
{303, "name_to_handle_at", 1, {"int"}, "int"},
{304, "open_to_handle_at", 4, {"int", "struct iovec *", \
"int", "off_t"}, "ssize_t"},
{305, "clock_adjtime", 3, {"int", "struct iovec *", "int"}, "ssize_t"},
{306, "syncfs", 1, {"int"}, "int"}, {307, "sendmmsg", 4, \
{"int", "struct mmsghdr *", "unsigned int", "unsigned int"}, "int"},
{308, "setns", 2, {"int", "int"}, "int"},
{309, "getcpu", 3, {"unsigned *", "unsigned *", \
"struct getcpu_cache *"}, "int"},
{310, "process_vm_readv", 6, {"pid_t", "struct iovec *", "unsigned long", \
"struct iovec *", "unsigned long", "unsigned long"}, "ssize_t"},
{311, "process_vm_writev", 6, \
{"pid_t", "struct iovec *", "unsigned long", \
"struct iovec *", "unsigned long", "unsigned long"}, "ssize_t"},
{312, "kcmp", 5, {"pid_t", "pid_t", "int", "unsigned long", \
"unsigned long"}, "int"},
{313, "finit_module", 3, {"int", "char *", "int"}, "int"},
{314, "sched_setattr", 3, {"pid_t", "struct sched attr *", \
"unsigned int"}, "int"},
{315, "sched_getattr", 4, {"pid_t", "struct sched attr *", \
"unsigned int", "unsigned int"}, "int"},
{316, "renameat2", 5, {"int", "const char *", "int", \
"const char *", "unsigned int"}, "int"},
{317, "seccomp", 3, {"unsigned int", "unsigned int", "void *"}, "int"}
};