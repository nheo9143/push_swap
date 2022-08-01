/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:07:23 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:10:36 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	setup(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->stack_a->size)
	{
		if (data->stack_a->top->value < data->piv1)
		{
			operation_pb(data);
			operation_rb(data);
		}
		else if (data->stack_a->top->value < data->piv2)
			operation_pb(data);
		else
			operation_ra(data);
	}
	while (data->stack_a->size > 3)
		operation_pb(data);
}

void	find_min_move(t_data *data, int *a_cost, int *b_cost)
{
	int		i;
	int		tmp_a;
	int		tmp_b;
	t_node	*tmp;

	i = 0;
	tmp = data->stack_b->top;
	data->min_move = -1;
	while (tmp)
	{
		tmp_a = 0;
		get_cost_a(data, tmp->value, &tmp_a);
		tmp_b = i;
		if (tmp_b >= (data->stack_b->size + 1) / 2)
			tmp_b = (data->stack_b->size - tmp_b) * -1;
		if (check_min(tmp_a, tmp_b, data->min_move) || data->min_move == -1)
		{
			data->min_move = get_min_sum(tmp_a, tmp_b);
			*a_cost = tmp_a;
			*b_cost = tmp_b;
		}
		tmp = tmp->prev;
		i++;
	}
}

void	find_min_and_move(t_data *data)
{
	int	a_cost;
	int	b_cost;

	a_cost = 0;
	find_min_move(data, &a_cost, &b_cost);
	move_a_b(data, &a_cost, &b_cost);
	move_a(data, &a_cost);
	move_b(data, &b_cost);
}

void	greedy_algorithm(t_data *data)
{
	setup(data);
	sort_small(data);
	while (data->stack_b->size > 0)
	{
		find_min_and_move(data);
		operation_pa(data);
	}
	last_sort(data);
}
