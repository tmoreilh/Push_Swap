#include "push_swap.h"

static void	check_elem(t_list **tmp, int *min, int *max)
{
	while (*tmp)
	{
		if ((*tmp)->num < *min)
			*min = (*tmp)->num;
		if ((*tmp)->num > *max)
			*max = (*tmp)->num;
		*tmp = (*tmp)->next;
	}
}

static int	check_b(t_list **elem, t_list **tmp, t_list **stack1, int pos)
{
	if (((*elem)->num > (*tmp)->num)
		&& ((*elem)->num < (ft_lstlast(*tmp))->num))
	{
		choose_path_in_start_a(stack1, pos);
		return (1);
	}
	return (0);
}

static void	sort_stack_b(t_list **stack1, t_list **stack2, int pos)
{
	t_list	*tmp;
	t_list	*elem;
	int		min;
	int		max;

	elem = find_elem(stack1, pos);
	min = elem->num;
	max = elem->num;
	tmp = *stack2;
	check_elem(&tmp, &min, &max);
	if (min == elem->num || max == elem->num)
		start_a_b(stack1, stack2, pos, check_pos(stack2, find_max_lst(stack2)));
	else
	{
		tmp = *stack2;
		if (check_b(&elem, &tmp, stack1, pos))
			return ;
		while (tmp)
		{
			if ((elem->num > tmp->next->num) && (elem->num < tmp->num))
				start_a_b(stack1, stack2, pos, check_pos(stack2, tmp->next));
			tmp = tmp->next;
		}
	}
}

static void	sorting_more(t_list **stack1, t_list **stack2, int num)
{
	int	flag;
	int	pos;

	flag = 1;
	set_index(stack1);
	set_flag(stack1, num);
	while (flag <= num + 1)
	{
		while (find_position(stack1, flag, &pos))
		{
			sort_stack_b(stack1, stack2, pos);
			pb(stack1, stack2);
		}
		flag++;
	}
	choose_path_in_start_b(stack2,
		check_pos(stack2, find_max_lst(stack2)));
	while ((count_lst(stack2)) > 0)
		pa(stack1, stack2);
}

void	sorting(t_list **stack1, int count)
{
	t_list	*stack2;

	stack2 = NULL;
	if (!check_sorting(stack1))
		return ;
	if (count == 2)
		sorting_two(stack1);
	else if (count == 3)
		sorting_three(stack1);
	else if (count == 4 || count == 5)
		sorting_five(stack1, &stack2);
	else if (count <= 100)
		sorting_more(stack1, &stack2, 6);
	else
		sorting_more(stack1, &stack2, 12);
}