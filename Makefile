# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 17:11:00 by rponsonn          #+#    #+#              #
#    Updated: 2021/04/21 17:24:23 by rponsonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC		=	srcs/

DIR_HEAD	=	includes/

DIR_LIB		=	srcs/libft/

DIR_OBJ		=	obj/



SRCS			=	${DIR_SRC}ft_printf.c ${DIR_SRC}ft_printf_util.c ${DIR_SRC}ft_printf_parse.c \
					${DIR_SRC}ft_printf_hex.c ${DIR_SRC}ft_printf_arg.c ${DIR_SRC}ft_printf_arg2.c \
					${DIR_SRC}ft_printf_util2.c
OBJS			=	$(SRCS:.c=.o)

NAME			=	libftprintf.a
LIBFT_A			=	libft.a
CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

.c.o:
					${CC} ${CFLAGS} -I${DIR_HEAD} -c $< -o ${<:.c=.o}

${NAME}:			${OBJS}
					@make bonus -C ${DIR_LIB}
					@echo Copying ${LIBFT_A} to root
					@cp ${DIR_LIB}${LIBFT_A} ${NAME}
					@ar -rcs ${NAME} ${OBJS}
all:				${NAME}

test:				
					@echo Compiling Testing program
					make bonus -C ${DIR_LIB}
					cp ${DIR_LIB}${LIBFT_A} ${LIBFT_A}
					cp ${DIR_HEAD}ft_printf.h ft_printf.h
					cp ${DIR_HEAD}libft.h libft.h
					cp ${DIR_HEAD}ft_printf.h ${DIR_SRC}ft_printf.h
					cp ${DIR_HEAD}libft.h ${DIR_SRC}libft.h
					gcc -g main.c ${SRCS} ${LIBFT_A}
					rm -f ft_printf.h libft.h ${DIR_SRC}ft_printf.h ${DIR_SRC}libft.h ${LIBFT_A}
					@echo Running test program
					@./a.out

clean:
					${RM} ${OBJS}
					@make clean -C ${DIR_LIB}
fclean:				clean
					${RM} ${NAME}
					${RM} ${DIR_SRC}${LIBFT_A}
					${RM} ${DIR_HEAD}*.gch
					@make fclean -C ${DIR_LIB}
re:					fclean ${NAME}
.PHONY:				all clean fclean re