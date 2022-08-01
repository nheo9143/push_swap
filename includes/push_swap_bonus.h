/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:58:51 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 12:16:11 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_data
{
	int				*arr;
	int				sorted;
	t_stack			*stack_a;
	t_stack			*stack_b;
}	t_data;

typedef struct s_file
{
	int		fd;
	size_t	len;
	char	*saveline;
}	t_file;

void	read_line(t_file *list);
char	*get_a_line(t_file *list);
char	*get_next_line(int fd);
void	ft_error(void);
void	ft_ko(void);
void	ft_ok(void);
void	operation_sa(t_data *data);
void	operation_sb(t_data *data);
void	operation_ss(t_data *data);
void	operation_pa(t_data *data);
void	operation_pb(t_data *data);
void	operation_ra(t_data *data);
void	operation_rb(t_data *data);
void	operation_rr(t_data *data);
void	operation_rra(t_data *data);
void	operation_rrb(t_data *data);
void	operation_rrr(t_data *data);
void	get_data(int ac, char **av, t_data *data);
void	init_stack_a(char *av, t_data *data);
void	init_node(t_stack *stack, int value);
void	quick_sort(int *nums, int start, int end);
void	check_sorted(t_data *data, int *arr, int size);
void	check_result(t_data data);

#endif
