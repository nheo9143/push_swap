/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_swap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:35 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:09:58 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

static void	swap_stack(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size > 1)
	{
		tmp = stack->top;
		stack->top = tmp->prev;
		stack->top->next = NULL;
		if (stack->top->prev)
			stack->top->prev->next = tmp;
		else
			stack->bottom = tmp;
		tmp->next = stack->top;
		tmp->prev = stack->top->prev;
		stack->top->prev = tmp;
	}
}

void	operation_sa(t_data *data)
{
	swap_stack(data->stack_a);
}

void	operation_sb(t_data *data)
{
	swap_stack(data->stack_b);
}

void	operation_ss(t_data *data)
{
	swap_stack(data->stack_a);
	swap_stack(data->stack_b);
}
