#include "push_swap.h"

t_list	*three_numbers_sort(t_list *stack)
{
	while ((stack->target != 1) || (stack->next->target != 2))
	{
		if ((stack->target == 1 && stack->next->target == 3) \
			|| (stack->target == 2 && stack->next->target == 1) \
			|| (stack->target == 3 && stack->next->target == 2))
		{
			stack = swap(stack);
			write(1, "sa\n", 3);
		}
		if ((stack->target == 3) && (stack->next->target == 1))
			stack = rotate(stack, 0);
		if ((stack->target == 2) && (stack->next->target == 3))
			stack = reverse_rotate(stack, 0);
	}
	return (stack);
}