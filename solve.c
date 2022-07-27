/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:07:23 by nheo              #+#    #+#             */
/*   Updated: 2022/07/27 13:06:22 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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
			// operation_pb(data);
			operation_ra(data);
	}
	while (data->stack_a->size > 3)
		operation_pb(data);
}

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

void	get_min_max_cost(t_data *data, int target, int *cost)
{
	t_node	*tmp;

	tmp = data->stack_a->top;
	while (tmp)
	{
		if (tmp->value == target)
			break;
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
			break;
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

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	check_min(int a, int b, int min)
{
	if (a * b > 0)
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a) < min);
		else
			return (ft_abs(b) < min);
	}
	return (ft_abs(a) + ft_abs(b) < min);
}

int	get_min_sum(int a, int b)
{
	if (a * b > 0)
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		else
			return (ft_abs(b));
	}
	return (ft_abs(a) + ft_abs(b));
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

void	move_a_b(t_data *data, int *a_cost, int *b_cost)
{
	if (*a_cost * *b_cost > 0)
	{
		while (*a_cost && *b_cost)
		{
			if (*a_cost > 0)
			{
				operation_rr(data);
				(*a_cost)--;
				(*b_cost)--;
			}
			else
			{
				operation_rrr(data);
				(*a_cost)++;
				(*b_cost)++;
			}
		}
	}
}

void	move_a(t_data *data, int *a_cost)
{
	while (*a_cost)
	{
		if (*a_cost > 0)
		{
			operation_ra(data);
			(*a_cost)--;
		}
		else
		{
			operation_rra(data);
			(*a_cost)++;
		}
	}
}

void	move_b(t_data *data, int *b_cost)
{
	while (*b_cost)
	{
		if (*b_cost > 0)
		{
			operation_rb(data);
			(*b_cost)--;
		}
		else
		{
			operation_rrb(data);
			(*b_cost)++;
		}
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

void	get_ra_cost(t_data *data, int *cost)
{
	t_node	*tmp;

	tmp = data->stack_a->top;
	while (tmp)
	{
		if (tmp->value == data->a_max)
		{
			(*cost)++;
			break;
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
			break;
		tmp = tmp->next;
		(*cost)++;
	}
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
