/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:00:17 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:10:33 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
	exit(0);
}
