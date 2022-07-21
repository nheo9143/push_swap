/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:13:31 by nheo              #+#    #+#             */
/*   Updated: 2021/11/22 19:48:16 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			len;
	unsigned char	*ptr;

	i = 0;
	len = count * size;
	ptr = 0;
	ptr = (unsigned char *)malloc(len);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, len);
	return ((void *)ptr);
}
