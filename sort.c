/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:07:36 by nheo              #+#    #+#             */
/*   Updated: 2022/07/26 14:08:01 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	make_heap(int *list, int n)
{
	int	i;
	int	j;
	int	root;

	j = 1;
	while (j < n)
	{
		i = j;
		while (i)
		{
			root = (i - 1) / 2;
			if (list[root] < list[i])
			{
				if (i + 1 < n && list[i] < list[i + 1])
					swap(&list[i + 1], &list[root]);
				else
					swap(&list[i], &list[root]);
			}
			i = root;
		}
		j++;
	}
}

void	update_heap(int *list, int n)
{
	int	i;
	int	c;

	i = 0;
	while (1)
	{
		c = i * 2 + 1;
		if (c >= n)
			break ;
		if (c + 1 < n && list[c] < list[c + 1])
			c++;
		if (list[i] < list[c])
			swap(&list[i], &list[c]);
		i = c;
	}
}

void	heap_sort(int *list, int n)
{
	int	i;

	i = -1;
	make_heap(list, n);
	while (++i < n)
	{
		swap(&list[0], &list[n - 1 - i]);
		update_heap(list, n - 1 - i);
	}
}
