# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 13:06:20 by nheo              #+#    #+#              #
#    Updated: 2022/07/25 16:39:32 by nheo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
SRCS = main.c \
		parse.c \
		utils.c \
		operator_push.c \
		operator_swap.c \
		operator_rotate.c \
		operator_reverse_rotate.c \
		sort.c \
		solve.c

LIBFT = ./libft/libftprintf.a
LIBFT_DIR = ./libft

HDRS = ./includes

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

bonus : $(BONUS)

%.o : %.c
	cc $(CFLAGS) -c -o $@ $< -I $(HDRS)

$(NAME) :$(OBJS)
	make -C ./libft
	cc $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lftprintf

clean :
	make -C ./libft clean
	rm -f $(OBJS)

fclean : clean
	make -C ./libft fclean
	rm -f $(NAME)

re :
	make fclean
	make all

bonus :

.PHONY : clean fclean re all bonus