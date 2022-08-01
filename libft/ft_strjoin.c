/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:58:12 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 12:47:05 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;

	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (0);
	}
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = ft_calloc(len, sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcat(ptr, s1, ft_strlen(s1) + 1);
	ft_strlcat(ptr, s2, len);
	free((char *)s1);
	return (ptr);
}
