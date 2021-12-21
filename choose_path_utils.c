#include "push_swap.h"

int	choose_path_in_start_a_without_rotate(t_list **stack1, int min, int max)
{
	int	count;

	count = count_lst(stack1);
	if (min < (count - max))
		return (min);
	else
		return (max);
}

void	choose_path_in_start_a(t_list **stack1, int num)
{
	int	i;
	int	count;

	i = 0;
	count = count_lst(stack1);
	if (num < (count - num))
	{
		while (i < num)
		{
			ra(stack1);
			i++;
		}
	}
	else
	{
		while (i < (count - num))
		{
			rra(stack1);
			i++;
		}
	}
}

void	choose_path_in_start_b(t_list **stack2, int num)
{
	int	i;
	int	count;

	i = 0;
	count = count_lst(stack2);
	if (num < (count - num))
	{
		while (i < num)
		{
			rb(stack2);
			i++;
		}
	}
	else
	{
		while (i < (count - num))
		{
			rrb(stack2);
			i++;
		}
	}
}