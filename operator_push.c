/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:11 by nheo              #+#    #+#             */
/*   Updated: 2022/07/21 15:56:22 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	push_stack(t_stack *cur_stack, t_stack *to_stack)
{
	t_node	*tmp;

	tmp = cur_stack->top;
	cur_stack->top = tmp->prev;
	cur_stack->size--;
	if (cur_stack->size > 0)
		cur_stack->top->next = NULL;
	tmp->prev = to_stack->top;
	if (to_stack->size > 0)
		to_stack->top->next = tmp;
	else
		to_stack->bottom = tmp;
	to_stack->top = tmp;
	to_stack->size++;
}

void	operation_pa(t_data *data)
{
	push_stack(data->stack_a, data->stack_b);
	write(1, "pa\n", 3);
}

void	operation_pb(t_data *data)
{
	push_stack(data->stack_b, data->stack_a);
	write(1, "pb\n", 3);
}
