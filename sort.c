/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:06:33 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:08:08 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_3(t_data *data)
{
	t_node	one;
	t_node	two;
	t_node	three;

	one = *data->stack_a->top;
	two = *data->stack_a->top->prev;
	three = *data->stack_a->bottom;
	if (one.value > two.value && two.value > three.value)
	{
		operation_sa(data);
		operation_rra(data);
	}
	else if (one.value > three.value && three.value > two.value)
		operation_ra(data);
	else if (two.value > one.value && one.value > three.value)
		operation_rra(data);
	else if (two.value > three.value && three.value > one.value)
	{
		operation_rra(data);
		operation_sa(data);
	}
	else if (three.value > one.value && one.value > two.value)
		operation_sa(data);
}

void	sort_2(t_data *data)
{
	t_node	one;
	t_node	two;

	one = *data->stack_a->top;
	two = *data->stack_a->top->prev;
	if (one.value > two.value)
		operation_sa(data);
}

void	sort_small(t_data *data)
{
	if (data->stack_a->size == 3)
		sort_3(data);
	else if (data->stack_a->size == 2)
		sort_2(data);
	data->a_max = data->stack_a->bottom->value;
	data->a_min = data->stack_a->top->value;
}

void	check_sorted(int *arr, int size)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			flag = 1;
	}
	if (!flag)
		exit(0);
}

void	last_sort(t_data *data)
{
	int	ra_cost;
	int	rra_cost;

	ra_cost = 0;
	rra_cost = 0;
	get_ra_cost(data, &ra_cost);
	get_rra_cost(data, &rra_cost);
	if (ra_cost < rra_cost)
	{
		while (ra_cost)
		{
			operation_ra(data);
			ra_cost--;
		}
	}
	else
	{
		while (rra_cost)
		{
			operation_rra(data);
			rra_cost--;
		}
	}
}
