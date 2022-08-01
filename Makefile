# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 13:06:20 by nheo              #+#    #+#              #
#    Updated: 2022/07/29 14:16:34 by nheo             ###   ########.fr        #
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
		greedy.c \
		greedy_utils.c \
		cost.c \
		quick_sort.c

BONUS_SRCS = main_bonus.c \
			parse_bonus.c \
			utils_bonus.c \
			operator_push_bonus.c \
			operator_swap_bonus.c \
			operator_rotate_bonus.c \
			operator_reverse_rotate_bonus.c \
			quick_sort_bonus.c \
			get_next_line_bonus.c

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

HDRS = ./includes

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

bonus : $(BONUS)

%.o : %.c
	cc $(CFLAGS) -c -o $@ $< -I $(HDRS)

$(NAME) : $(OBJS)
	make -C ./libft
	cc $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

$(BONUS) : $(BONUS_OBJS)
	make -C ./libft
	cc $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

clean :
	make -C ./libft clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	make -C ./libft fclean
	rm -f $(NAME) $(BONUS)

re :
	make fclean
	make all

.PHONY : clean fclean re all bonus