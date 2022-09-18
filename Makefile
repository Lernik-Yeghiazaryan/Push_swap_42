# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 14:22:54 by leyeghia          #+#    #+#              #
#    Updated: 2022/06/29 14:32:24 by leyeghia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= push_swap
NAME2		= checker
SRCS		= $(shell find ./src -name "*.c")
OBJS		= ${SRCS:.c=.o}
B_SRCS		= $(shell find ./bonus -name "*.c")
B_OBJS		= ${B_SRCS:.c=.o}
CC			= gcc
INCLUDES	= ./header
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

.c.o :
	${CC} ${CFLAGS} -I $(INCLUDES) -c $< -o ${<:.c=.o}

all : $(NAME1) $(NAME2)

$(NAME1) : ${OBJS}
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME1) ${OBJS}

$(NAME2) : ${B_OBJS}
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME2) ${B_OBJS}

clean :
	${RM} ${OBJS} ${B_OBJS}

fclean : clean
	${RM} ${NAME1} ${NAME2}

re : fclean all

.PHONY : all clean fclean re
