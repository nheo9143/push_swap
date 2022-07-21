#include "libft.h"
#include "./includes/push_swap.h"

void	init_node(t_stack *stack, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		ft_error();
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (stack->top == NULL)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->prev = stack->top;
		stack->top->next = new;
		stack->top = new;
	}
}

void	get_data(int ac, char **av, t_data *data)
{
	data->stack_a = (t_stack *)malloc(sizeof(t_stack));
	data->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!data->stack_a || !data->stack_b)
		ft_error();
	data->stack_a->size = 0;
	while (ac-- > 1)
		init_data(*av++, data);
	data->stack_b->size = 0;
	data->stack_b->top = NULL;
	data->stack_b->bottom = NULL;
}

void	check_dup(t_stack *stack, int val)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (val == tmp->value)
			ft_error();
		tmp = tmp->prev;
	}
}

void	init_data(char *av, t_data *data)
{
	int		val;
	size_t	i;
	char	**nums;

	nums = ft_split(av, " \t\v\r\f\n");
	i = 0;
	while (nums[i])
	{
		val = ft_atoi(nums[i]);
		check_dup(data->stack_a, val);
		init_node(data->stack_a, val);
		free(nums[i++]);
		data->stack_a->size++;
	}
	free(nums);
}