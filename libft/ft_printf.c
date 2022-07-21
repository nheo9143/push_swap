/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:09:15 by nheo              #+#    #+#             */
/*   Updated: 2022/03/09 13:20:36 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int	(*fp(int type))(int type, long value)
{
	if (type == 'c' || type == 'd' || type == 'i')
		return (fp_value);
	if (type == 'u' || type == 'x' || type == 'X')
		return (fp_value);
	if (type == 's' || type == 'p')
		return (fp_addr);
	else
		return (0);
}

int	print_by_type(va_list ap, const char *format)
{
	int				type;
	int				len;
	int				temp;

	len = 0;
	while (*format)
	{
		if (*format == '%' && *(++format) != '%')
		{
			type = *format;
			temp = fp(type)(type, va_arg(ap, long));
			if (temp < 0)
				return (-1);
			len += temp;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = print_by_type(ap, format);
	va_end(ap);
	return (len);
}
