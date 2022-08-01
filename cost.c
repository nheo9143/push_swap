/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:09:30 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:10:46 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	get_min_max_cost(t_data *data, int target, int *cost)
{
	t_node	*tmp;

	tmp = data->stack_a->top;
	while (tmp)
	{
		if (tmp->value == target)
			break ;
		tmp = tmp->prev;
		(*cost)++;
	}
	if (target == data->a_max)
		(*cost)++;
}

void	get_mid_cost(t_data *data, int new, int *cost)
{
	t_node	*tmp;

	tmp = data->stack_a->top;
	while (tmp)
	{
		if (!tmp->prev || (tmp->value < new && new < tmp->prev->value))
			break ;
		tmp = tmp->prev;
		(*cost)++;
	}
	(*cost)++;
}

void	get_cost_a(t_data *data, int new, int *cost)
{
	if (data->a_max < new)
		get_min_max_cost(data, data->a_max, cost);
	else if (data->a_min > new)
		get_min_max_cost(data, data->a_min, cost);
	else
		get_mid_cost(data, new, cost);
	if (*cost >= (data->stack_a->size + 1) / 2)
		*cost = (data->stack_a->size - *cost) * -1;
}

void	get_ra_cost(t_data *data, int *cost)
{
	t_node	*tmp;

	tmp = data->stack_a->top;
	while (tmp)
	{
		if (tmp->value == data->a_max)
		{
			(*cost)++;
			break ;
		}
		tmp = tmp->prev;
		(*cost)++;
	}
}

void	get_rra_cost(t_data *data, int *cost)
{
	t_node	*tmp;

	tmp = data->stack_a->bottom;
	while (tmp)
	{
		if (tmp->value == data->a_max)
			break ;
		tmp = tmp->next;
		(*cost)++;
	}
}
