#include "push_swap.h"

void	sorting_two(t_list **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
	else
		return ;
}

void	sorting_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->num;
	b = (*stack)->next->num;
	c = (*stack)->next->next->num;
	if ((b > c) && (c > a))
	{
		sa(stack);
		ra(stack);
	}
	else if ((b > a) && (a > c))
		rra(stack);
	else if ((c > a) && (a > b))
		sa(stack);
	else if ((a > c) && (c > b))
		ra(stack);
	else if ((a > b) && (b > c))
	{
		sa(stack);
		rra(stack);
	}
}

void	sorting_five(t_list **stack1, t_list **stack2)
{
	push_min_lst(stack1, stack2);
	sorting_three(stack1);
	while (count_lst(stack2) > 0)
		pa(stack1, stack2);
}

void	set_index(t_list **stack1)
{
	t_list			*tmp;
	t_list			*min_list;
	long long int	min;
	int				i;
	int				j;

	i = count_lst(stack1);
	j = 0;
	while (j < i)
	{
		min = LLONG_MAX;
		tmp = *stack1;
		while (tmp)
		{
			if ((tmp->num < min) && (tmp->index == -1))
			{
				min = tmp->num;
				min_list = tmp;
			}
			tmp = tmp->next;
		}
		min_list->index = j;
		j++;
	}
}

void	set_flag(t_list **stack1, int num)
{
	int		n;
	int		i;
	t_list	*tmp;

	i = 0;
	n = count_lst(stack1);
	while (i < (num))
	{
		tmp = *stack1;
		while (tmp)
		{
			if ((tmp->index >= ((n / num) * i))
				&& (tmp->index < ((n / num) * (i + 1))) && tmp->flag == -1)
				tmp->flag = i + 1;
			tmp = tmp->next;
		}
		i++;
	}
	tmp = *stack1;
	while (tmp)
	{
		if (tmp->flag == -1)
			tmp->flag = i + 1;
		tmp = tmp->next;
	}
}