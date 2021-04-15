# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 17:11:00 by rponsonn          #+#    #+#              #
#    Updated: 2021/04/15 19:24:17 by rponsonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_SRC		=	./srcs/
PATH_HEAD		=	./includes/

SRCS			=	${PATH_SRC}ft_printf.c ${PATH_SRC}ft_printf_util.c ${PATH_SRC}ft_printf_parse.c \
					${PATH_SRC}ft_printf_hex.c ${PATH_SRC}ft_print_arg.c
OBJS			=	$(SRCS:.c=.o)

NAME			=	printf.a
CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

.c.o:
					${CC} ${CFLAGS} -I${PATH_HEAD} -c $< -o ${<:.c=.o}

${NAME}:			${OBJS}
					ar -rcs ${NAME} ${OBJS}
all:				@cd srcs/libft/
					@make bonus
					@echo Make Bonus
					${NAME}

clean:
					${RM} ${OBJS}
fclean:				clean
					${RM} ${NAME}
re:					fclean ${NAME}
.PHONY:				all clean fclean re