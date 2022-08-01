/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:14:51 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:10:39 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
