/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_reverse_rotate_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:21 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:10:04 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

static void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size > 1)
	{
		tmp = stack->bottom;
		stack->bottom = stack->bottom->next;
		stack->bottom->prev = NULL;
		tmp->next = NULL;
		stack->top->next = tmp;
		tmp->prev = stack->top;
		stack->top = tmp;
	}
}

void	operation_rra(t_data *data)
{
	reverse_rotate_stack(data->stack_a);
}

void	operation_rrb(t_data *data)
{
	reverse_rotate_stack(data->stack_b);
}

void	operation_rrr(t_data *data)
{
	reverse_rotate_stack(data->stack_a);
	reverse_rotate_stack(data->stack_b);
}
