/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rotate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:28 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:10:01 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

static void	rotate_stack(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size > 1)
	{
		tmp = stack->top;
		stack->top = tmp->prev;
		stack->top->next = NULL;
		tmp->next = stack->bottom;
		tmp->prev = NULL;
		stack->bottom->prev = tmp;
		stack->bottom = tmp;
	}
}

void	operation_ra(t_data *data)
{
	rotate_stack(data->stack_a);
}

void	operation_rb(t_data *data)
{
	rotate_stack(data->stack_b);
}

void	operation_rr(t_data *data)
{
	rotate_stack(data->stack_a);
	rotate_stack(data->stack_b);
}
