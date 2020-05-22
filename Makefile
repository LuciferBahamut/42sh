##
## EPITECH PROJECT, 2020
## PSU_minishell1_2019
## File description:
## Makefile
##

SRC	=	src/parsing/init.c 		\
		src/parsing/tool.c 		\
		src/parsing/split.c		\
		src/utility/utility1.c 		\
		src/utility/utility2.c 		\
		src/utility/utility3.c 		\
		src/bin_exec.c 			\
		src/bin_exec_2.c		\
		src/cmd_exec.c 			\
		src/dir_change.c 		\
		src/dir_change_2.c		\
		src/dir_change_3.c		\
		src/env_gestion.c 		\
		src/env_gestion2.c 		\
		src/env_modif.c 		\
		src/my_echo.c			\
		src/main.c 			\

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CPPFLAGS=	-I./include

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ)

debug   :       CFLAGS += -g
debug   :       re

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
