# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 10:25:45 by cblesche          #+#    #+#              #
#    Updated: 2016/12/19 20:40:55 by yribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
INCLUDES = includes
LIBS = libft
LIB = ft
FLAGS = -Wall -Werror -Wextra
SRCS = fillit.c reader.c tetrimino.c map.c solve.c error.c free.c check_tetrimino.c
SRCSREP = srcs
OBJS = $(SRCS:.c=.o)


all : $(NAME)

%.o : $(SRCSREP)/%.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c $^

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(FLAGS) -I$(INCLUDES) $^ -L$(LIBS) -l$(LIB) -o $@

clean :
	rm -f $(OBJS)
	make clean -C libft
fclean : clean
	make fclean -C libft
	rm -f $(NAME)
re : fclean all
