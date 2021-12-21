#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**str;
	t_list	*stack1;
	int		i;

	i = 0;
	stack1 = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		while (str[i])
		{
			ft_lstadd_back(&stack1, ft_lstnew(ft_atoi(str[i])));
			i++;
		}
	}
	else
	{
		while (++i < argc)
			ft_lstadd_back(&stack1, ft_lstnew(ft_atoi(argv[i])));
	}
	check_identical(&stack1);
	sorting(&stack1, count_lst(&stack1));
}