/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:09:08 by nheo              #+#    #+#             */
/*   Updated: 2022/03/09 13:09:09 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_putadr(long num)
{
	int			len;
	char		*to_print;

	to_print = ft_based_num_pointer(num, 16);
	if (!to_print)
		return (-1);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(to_print, 1);
	len = 2 + ft_strlen(to_print);
	free(to_print);
	return (len);
}

static char	*ft_uppercase(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

static char	*ft_str_by_type(int type, int value)
{
	if (type == 'd' || type == 'i')
		return (ft_itoa(value));
	else if (type == 'u')
		return (ft_itoa_unsigned(value));
	else if (type == 'x')
		return (ft_based_num(value, 16));
	else if (type == 'X')
		return (ft_uppercase(ft_based_num(value, 16)));
	return (0);
}

int	fp_value(int type, long value)
{
	char	*result;
	int		len;

	len = 1;
	if (type == 'c')
		ft_putchar_fd(value, 1);
	else
	{
		result = ft_str_by_type(type, value);
		if (!result)
			return (-1);
		len = ft_strlen(result);
		ft_putstr_fd(result, 1);
		free(result);
	}
	return (len);
}

int	fp_addr(int type, long value)
{
	int			len;

	if (type == 's')
	{
		if (value == 0)
		{
			ft_putstr_fd("(null)", 1);
			len = ft_strlen("(null)");
		}
		else
		{
			ft_putstr_fd((char *)value, 1);
			len = ft_strlen((const char *)value);
		}
	}
	else
		len = ft_putadr(value);
	return (len);
}
