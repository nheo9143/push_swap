/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:58:51 by nheo              #+#    #+#             */
/*   Updated: 2022/07/21 16:26:11 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_data
{
	t_stack			*stack_a;
	t_stack			*stack_b;
}	t_data;

int		ft_atoi(const char *str);
void	ft_error(void);
void	operation_sa(t_data *data);
void	operation_sb(t_data *data);
void	operation_ss(t_data *data);
void	operation_pa(t_data *data);
void	operation_pb(t_data *data);
void	operation_ra(t_data *data);
void	operation_rb(t_data *data);
void	operation_rr(t_data *data);
void	operation_rra(t_data *data);
void	operation_rrb(t_data *data);
void	operation_rrr(t_data *data);
void	get_data(int ac, char **av, t_data *data);
void	init_data(char *av, t_data *data);
void	init_node(t_stack *stack, int value);


#endif
