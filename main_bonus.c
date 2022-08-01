/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:00:17 by nheo              #+#    #+#             */
/*   Updated: 2022/07/29 14:11:00 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "includes/push_swap_bonus.h"

void	check_operations(t_list **cmds, char *new)
{
	t_list	*tmp;
	char	*content;

	if (ft_strcmp(new, "sa\n") != 0 && ft_strcmp(new, "sb\n") != 0
		&& ft_strcmp(new, "ss\n") != 0 && ft_strcmp(new, "pa\n") != 0
		&& ft_strcmp(new, "pb\n") != 0 && ft_strcmp(new, "ra\n") != 0
		&& ft_strcmp(new, "rb\n") != 0 && ft_strcmp(new, "rr\n") != 0
		&& ft_strcmp(new, "rra\n") != 0 && ft_strcmp(new, "rrb\n") != 0
		&& ft_strcmp(new, "rrr\n") != 0)
		ft_error();
	content = ft_strdup(new);
	if (!content)
		ft_error();
	tmp = ft_lstnew(content);
	ft_lstadd_back(cmds, tmp);
}

void	apply_by_operation(t_data *data, t_list *cmds)
{
	if (ft_strcmp(cmds->content, "sa\n") == 0)
		operation_sa(data);
	else if (ft_strcmp(cmds->content, "sb\n") == 0)
		operation_sb(data);
	else if (ft_strcmp(cmds->content, "ss\n") == 0)
		operation_ss(data);
	else if (ft_strcmp(cmds->content, "pa\n") == 0)
		operation_pa(data);
	else if (ft_strcmp(cmds->content, "pb\n") == 0)
		operation_pb(data);
	else if (ft_strcmp(cmds->content, "ra\n") == 0)
		operation_ra(data);
	else if (ft_strcmp(cmds->content, "rb\n") == 0)
		operation_rb(data);
	else if (ft_strcmp(cmds->content, "rr\n") == 0)
		operation_rr(data);
	else if (ft_strcmp(cmds->content, "rra\n") == 0)
		operation_rra(data);
	else if (ft_strcmp(cmds->content, "rrb\n") == 0)
		operation_rrb(data);
	else if (ft_strcmp(cmds->content, "rrr\n") == 0)
		operation_rrr(data);
}

void	apply_operations(t_data *data, t_list *cmds)
{
	while (cmds)
	{
		apply_by_operation(data, cmds);
		cmds = cmds->next;
	}
}

void	read_operations(t_list **cmds)
{
	char	*buf;

	while (1)
	{
		buf = get_next_line(0);
		if (buf == NULL)
			break ;
		check_operations(cmds, buf);
		free(buf);
	}
}

int	main(int ac, char *av[])
{
	t_data	data;
	t_list	*cmds;

	if (ac == 1)
		return (0);
	cmds = NULL;
	get_data(ac, &av[1], &data);
	read_operations(&cmds);
	apply_operations(&data, cmds);
	check_result(data);
	exit (0);
}
