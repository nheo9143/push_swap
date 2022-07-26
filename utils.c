/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:40 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:08:15 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
