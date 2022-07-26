/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:58:51 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 12:55:06 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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
	int				piv1;
	int				piv2;
	int				a_min;
	int				a_max;
	int				min_move;
	t_stack			*stack_a;
	t_stack			*stack_b;
}	t_data;

int		ft_atoi(const char *str);
void	ft_error(void);
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
void	quick_sort(int *nums, int start, int end);
void	greedy_algorithm(t_data *data);
void	sort_small(t_data *data);
void	check_sorted(int *arr, int size);
int		ft_abs(int num);
void	get_ra_cost(t_data *data, int *cost);
void	get_rra_cost(t_data *data, int *cost);
void	get_cost_a(t_data *data, int new, int *cost);
void	get_mid_cost(t_data *data, int new, int *cost);
void	get_min_max_cost(t_data *data, int target, int *cost);
void	move_a_b(t_data *data, int *a_cost, int *b_cost);
void	move_a(t_data *data, int *a_cost);
void	move_b(t_data *data, int *b_cost);
int		check_min(int a, int b, int min);
int		get_min_sum(int a, int b);
void	last_sort(t_data *data);

#endif
