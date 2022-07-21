/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:35 by nheo              #+#    #+#             */
/*   Updated: 2022/07/21 11:59:42 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size > 1)
	{
		tmp = stack->top;
		stack->top = stack->top->prev;
		stack->top->next = NULL;
		tmp->next = stack->top;
		tmp->prev = stack->top->prev;
		stack->top->prev = tmp;
	}
}

void	operation_sa(t_data *data)
{
	swap_stack(data->stack_a);
	write(1, "sa\n", 3);
}

void	operation_sb(t_data *data)
{
	swap_stack(data->stack_b);
	write(1, "sb\n", 3);
}

void	operation_ss(t_data *data)
{
	swap_stack(data->stack_a);
	swap_stack(data->stack_b);
	write(1, "ss\n", 3);
}
