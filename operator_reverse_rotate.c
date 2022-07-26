/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:21 by nheo              #+#    #+#             */
/*   Updated: 2022/07/26 17:07:32 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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
	write(1, "rra\n", 4);
}

void	operation_rrb(t_data *data)
{
	reverse_rotate_stack(data->stack_b);
	write(1, "rrb\n", 4);
}

void	operation_rrr(t_data *data)
{
	reverse_rotate_stack(data->stack_a);
	reverse_rotate_stack(data->stack_b);
	write(1, "rrr\n", 4);
}
