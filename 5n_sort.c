#include "push_swap.h"

void	five_numbers_sort(t_list **stack)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (stack[0]->target < 4)
			stack[0] = rotate(stack[0], 0);
		else
		{
			push(stack, 'b');
			i++;
		}
	}
	stack[0] = three_numbers_sort(stack[0]);
}