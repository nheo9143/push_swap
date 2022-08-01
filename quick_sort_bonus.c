/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:07:36 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:08:36 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *nums, int start, int end, int pivot)
{
	int	i;
	int	j;

	while (1)
	{
		i = start;
		j = end - 1;
		while (i < end - 1 && nums[i] <= nums[pivot])
			i++;
		while (j > start && nums[j] >= nums[pivot])
			j--;
		if (i < j)
			swap(&nums[i], &nums[j]);
		else
			break ;
	}
	swap(&nums[j], &nums[pivot]);
	return (j);
}

void	quick_sort(int *nums, int start, int end)
{
	int	key;

	if (start >= end)
		return ;
	key = partition(nums, start, end, start);
	quick_sort(nums, start, key);
	quick_sort(nums, key + 1, end);
}
