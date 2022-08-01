/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:40 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:08:40 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"
#include "includes/libft.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_ko(void)
{
	write(1, "KO\n", 3);
	exit(0);
}

void	ft_ok(void)
{
	write(1, "OK\n", 3);
	exit(0);
}

void	check_result(t_data data)
{
	int	i;

	i = -1;
	if (data.stack_b->size > 0)
		ft_ko();
	while (++i < data.stack_a->size)
	{
		if (data.stack_a->top->value != data.arr[i])
			ft_ko();
		data.stack_a->top = data.stack_a->top->prev;
		data.stack_a->size--;
	}
	ft_ok();
}

void	check_sorted(t_data *data, int *arr, int size)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			flag = 1;
	}
	if (!flag)
		data->sorted = 1;
}
