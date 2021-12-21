#include "push_swap.h"

static void	check_flag(int flag)
{
	if (flag == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

static int	check_sign(char **str, int i, int *m)
{
	while (*str[i] == 32 || (*str[i] >= 9 && *str[i] <= 13))
		i++;
	if (*str[i] == '+' || *str[i] == '-')
	{
		if (*str[i] == '-')
			*m = -1;
		i++;
	}
	return (i);
}

static void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	m;
	int	n;
	int	flag;

	flag = 0;
	i = 0;
	m = 1;
	n = 0;
	i = check_sign(&str, i, &m);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		flag = 1;
		n = n * 10 + m * (str[i] - 48);
		i++;
		if ((m == 1 && n < 0) || (m == -1 && n > 0))
			error();
	}
	if (str[i])
		error();
	check_flag(flag);
	return (n);
}