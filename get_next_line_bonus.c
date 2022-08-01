/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 00:23:55 by heonamjun         #+#    #+#             */
/*   Updated: 2022/07/29 14:11:03 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "includes/push_swap_bonus.h"

#define ERROR 0
#define TRUE 1

char	*free_file(t_file *file)
{
	if (file->saveline)
		free(file->saveline);
	file->saveline = 0;
	return (NULL);
}

char	*get_a_line(t_file *file)
{
	size_t	i;
	char	*line;
	char	*temp;

	i = 0;
	while (file->saveline[i] != '\n' && i < file->len)
		i++;
	if (file->saveline[i] == '\n')
		i++;
	file->len -= i;
	line = (char *)ft_calloc((i + 1), sizeof(char));
	temp = (char *)ft_calloc((file->len + 1), sizeof(char));
	if (!line || !temp)
		return (ERROR);
	ft_strlcpy(line, file->saveline, i + 1);
	ft_strlcpy(temp, file->saveline + i, file->len + 1);
	free(file->saveline);
	file->saveline = temp;
	return (line);
}

void	read_line(t_file *file)
{
	long	index;
	char	*buf;

	index = 1;
	buf = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
	{
		free_file(file);
		free(buf);
		return ;
	}
	while (index > 0 && !ft_strchr(file->saveline, '\n'))
	{
		index = read(file->fd, buf, BUFFER_SIZE);
		if (index > 0)
			file->len += index;
		buf[index] = 0;
		file->saveline = ft_strjoin(file->saveline, buf);
		if (!file->saveline)
			break ;
	}
	free(buf);
}

char	*get_next_line(int fd)
{
	static t_file	file;
	char			*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (ERROR);
	file.fd = fd;
	read_line(&file);
	result = get_a_line(&file);
	if (!result)
		return (free_file(&file));
	if (file.len <= 0)
	{
		if (!*result)
		{
			free(result);
			result = 0;
		}
		free_file(&file);
	}
	return (result);
}
