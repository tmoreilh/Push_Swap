#include "push_swap.h"

void	push_min_lst(t_list **stack1, t_list **stack2)
{
	while (count_lst(stack1) > 3)
	{
		if ((check_pos(stack1, find_min_lst(stack1))) == 0)
			pb(stack1, stack2);
		else if ((check_pos(stack1, find_min_lst(stack1)))
			< (count_lst(stack1) / 2 + 1))
			ra(stack1);
		else
			rra(stack1);
	}
}

void	check_identical(t_list **stack1)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	tmp1 = *stack1;
	i = count_lst(stack1);
	while (i > 0)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->num == tmp2->num)
			{
				ft_putstr_fd("Error\n", 2);
				exit(-1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		i--;
	}
}

int	find_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

t_list	*find_elem(t_list **stack1, int pos)
{
	t_list	*tmp;

	tmp = *stack1;
	while (pos > 0)
	{
		pos--;
		tmp = tmp->next;
	}
	return (tmp);
}

int	find_position(t_list **stack1, int flag, int *pos_return)
{
	t_list	*tmp;
	int		min;
	int		max;
	int		pos;

	min = INT32_MAX;
	max = INT32_MIN;
	tmp = *stack1;
	while (tmp)
	{
		if (tmp->flag == flag)
		{
			pos = check_pos(stack1, tmp);
			if (pos < min)
				min = check_pos(stack1, tmp);
			if (pos > max)
				max = check_pos(stack1, tmp);
		}
		tmp = tmp->next;
	}
	if (min == INT32_MAX && max == INT32_MIN)
		return (0);
	*pos_return = choose_path_in_start_a_without_rotate(stack1, min, max);
	return (1);
}