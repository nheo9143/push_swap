/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:28 by nheo              #+#    #+#             */
/*   Updated: 2022/07/26 17:08:32 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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
	write(1, "ra\n", 3);
}

void	operation_rb(t_data *data)
{
	rotate_stack(data->stack_b);
	write(1, "rb\n", 3);
}

void	operation_rr(t_data *data)
{
	rotate_stack(data->stack_a);
	rotate_stack(data->stack_b);
	write(1, "rr\n", 3);
}
