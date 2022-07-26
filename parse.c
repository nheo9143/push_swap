/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:07:29 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:13:21 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	init_node(t_stack *stack, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		ft_error();
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (stack->top == NULL)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->next = stack->bottom;
		stack->bottom->prev = new;
		stack->bottom = new;
	}
}

void	get_pivot(t_data *data)
{
	int		i;
	t_node	*tmp;

	data->arr = (int *)malloc(sizeof(int) * data->stack_a->size);
	if (!data->arr)
		ft_error();
	i = -1;
	tmp = data->stack_a->top;
	while (++i < data->stack_a->size)
	{
		data->arr[i] = tmp->value;
		tmp = tmp->prev;
	}
	check_sorted(data->arr, data->stack_a->size);
	quick_sort(data->arr, 0, data->stack_a->size);
	data->piv1 = data->arr[data->stack_a->size / 3];
	data->piv2 = data->arr[data->stack_a->size / 3 * 2];
}

void	check_dup(t_stack *stack, int val)
{
	int		i;
	t_node	*tmp;

	i = -1;
	tmp = stack->top;
	while (++i < stack->size)
	{
		if (val == tmp->value)
			ft_error();
		tmp = tmp->prev;
	}
}

void	init_stack_a(char *av, t_data *data)
{
	int		i;
	int		val;
	char	**nums;

	i = -1;
	nums = ft_split(av, " \t\v\r\f\n");
	while (nums[++i])
	{
		val = ft_atoi((const char *)nums[i]);
		check_dup(data->stack_a, val);
		init_node(data->stack_a, val);
		data->stack_a->size++;
	}
	i = -1;
	while (nums[++i])
		free(nums[i]);
	free(nums);
}

void	get_data(int ac, char **av, t_data *data)
{
	data->stack_a = (t_stack *)malloc(sizeof(t_stack));
	data->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!data->stack_a || !data->stack_b)
		ft_error();
	data->stack_a->size = 0;
	while (ac-- > 1)
		init_stack_a(*av++, data);
	data->stack_b->size = 0;
	data->stack_b->top = NULL;
	data->stack_b->bottom = NULL;
	get_pivot(data);
}
