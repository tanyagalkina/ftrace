##
## EPITECH PROJECT, 2020
## nm_objdump
## File description:
## Makefile
##

CC	= gcc

RM	= rm -f

NAME	= ftrace

SRCS	=	./src/main.c 		\
		./src/p_flag_loop.c	\
		./src/my_strace.c	\
		./src/print.c		\
		./src/print_funcs.c	\
		./src/print_funcs2.c


OBJS	= $(SRCS:.c=.o)

CFLAGS += -W -Wall -Wextra

all		: $(NAME)

$(NAME)		: $(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(FLAGS)


clean:
	$(RM) $(OBJS)

fclean:		clean
		$(RM) ftrace

re: fclean all

.PHONY: all ftrace clean fclean re
