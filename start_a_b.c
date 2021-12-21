#include "push_swap.h"

static void	s_else(t_list **stack1, t_list **stack2, int pos_a, int pos_b)
{
	choose_path_in_start_a(stack1, pos_a);
	choose_path_in_start_b(stack2, pos_b);
}

static void	raznica(t_list **stack1, t_list **stack2, int *raz_a, int *raz_b)
{
	while (*raz_a && *raz_b)
	{
		rrr(stack1, stack2);
		(*raz_a)--;
		(*raz_b)--;
	}
	while (*raz_a)
	{
		rra(stack1);
		(*raz_a)--;
	}
	while (*raz_b)
	{
		rrb(stack2);
		(*raz_b)--;
	}
}

static void	pos(t_list **stack1, t_list **stack2, int *pos_a, int *pos_b)
{
	while (*pos_a && *pos_b)
	{
		rr(stack1, stack2);
		(*pos_a)--;
		(*pos_b)--;
	}
	while (*pos_a)
	{
		ra(stack1);
		(*pos_a)--;
	}
	while (*pos_b)
	{
		rb(stack2);
		(*pos_b)--;
	}
}

void	start_a_b(t_list **stack1, t_list **stack2, int pos_a, int pos_b)
{
	int	raznica_a;
	int	raznica_b;
	int	one;
	int	two;
	int	three;

	raznica_a = count_lst(stack1) - pos_a;
	raznica_b = count_lst(stack2) - pos_b;
	one = pos_a + pos_b - find_min(pos_a, pos_b);
	two = raznica_a + raznica_b - find_min(raznica_a, raznica_b);
	three = find_min(pos_a + raznica_b, pos_b + raznica_a);
	if (one < two && one < three)
		pos(stack1, stack2, &pos_a, &pos_b);
	else if (two <= one && two <= three)
		raznica(stack1, stack2, &raznica_a, &raznica_b);
	else
		s_else(stack1, stack2, pos_a, pos_b);
}