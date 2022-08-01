/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:12:53 by nheo              #+#    #+#             */
/*   Updated: 2022/07/27 19:18:25 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	value;

	i = 0;
	value = (char)c;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == value)
			return ((char *)&str[i]);
		i++;
	}
	if (!value && !str[i])
		return ((char *)&str[i]);
	return (0);
}
