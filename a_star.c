#include "includes/push_swap.h"

int	get_viyong(t_data data)
{
	int	vi;

	vi = 0;
	while (data.stack_a->size > 0)
	{
		vi += data.stack_a->top->to - data.stack_a->top->cur;
		data.stack_a->top = data.stack_a->top->prev;
		data.stack_a->size--;
	}
	return (vi);
}

void	a_star_algorithm(t_data *data)
{
	int		viyong;
	char	cmds[20];

	viyong = get_viyong(*data);
	
}