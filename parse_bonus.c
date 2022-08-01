/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:07:29 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:11:16 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap_bonus.h"

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

void	get_sorted(t_data *data)
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
	check_sorted(data, data->arr, data->stack_a->size);
	quick_sort(data->arr, 0, data->stack_a->size);
}

void	check_dup(t_stack *stack, int val)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (val == tmp->value)
			ft_error();
		tmp = tmp->prev;
	}
}

void	init_stack_a(char *av, t_data *data)
{
	int		val;
	int		i;
	char	**nums;

	nums = ft_split(av, " \t\v\r\f\n");
	i = -1;
	while (nums[++i])
	{
		val = ft_atoi(nums[i]);
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
	get_sorted(data);
}
