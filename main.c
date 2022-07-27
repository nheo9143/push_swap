/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:00:17 by nheo              #+#    #+#             */
/*   Updated: 2022/07/27 13:08:16 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include "./includes/ft_printf.h"
#include "includes/libft.h"
#include <stdlib.h>

void	print_result(t_data data)
{
	while (data.stack_a->size > 0)
	{
		ft_printf("%d\n", data.stack_a->top->value);
		data.stack_a->top = data.stack_a->top->prev;
		data.stack_a->size--;
	}
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 1)
		return (0);
	get_data(ac, &av[1], &data);
	if (data.stack_a->size > 3)
		greedy_algorithm(&data);
	else
		sort_small(&data);
	print_result(data);
	// system(("leaks push_swap"));
	exit(0);
}
