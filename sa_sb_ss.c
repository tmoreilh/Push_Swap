#include "push_swap.h"

static void	ft_s(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_list **stack1)
{
	ft_s(stack1);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack2)
{
	ft_s(stack2);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack1, t_list **stack2)
{
	ft_s(stack1);
	ft_s(stack2);
	write(1, "ss\n", 3);
}