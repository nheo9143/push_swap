/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:01 by nheo              #+#    #+#             */
/*   Updated: 2022/07/21 16:10:59 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == ' ' || c == '\r')
		return (1);
	return (0);
}

static int	ft_check_flow(int num, int c, int minus)
{
	num *= minus;
	c -= '0';
	if (minus == 1)
		if (num * 10 + c < num)
			ft_error();
	if (minus == -1)
		if (num * 10 - c > num)
			ft_error();
	return (0);
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static const char	*check_format(const char *str, int *minus)
{
	while (ft_isspace(*str) && *str)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*minus *= (-1);
		str++;
	}
	if (!*str)
		ft_error();
	return (str);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	minus;
	int	result;

	num = 0;
	minus = 1;
	str = check_format(str, &minus);
	while (ft_isdigit(*str) && *str)
	{
		if (ft_check_flow(num, *str, minus))
			return (ft_check_flow(num, *str, minus) - 2);
		num *= 10;
		num += *str - '0';
		str++;
	}
	result = (int)(num * minus);
	return (result);
}
