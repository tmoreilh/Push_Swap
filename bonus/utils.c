#include "get_next_line.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			n;
	long int	resultat;

	i = 0;
	n = 1;
	resultat = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		resultat = 10 * resultat + str[i++] - '0';
	if (str[i] != 0 && ft_isdigit(str[i]) == 0)
		return (0);
	resultat = resultat * n;
	if (resultat < INT_MIN || resultat > INT_MAX)
		return (0);
	return (resultat);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	if (n == 0)
// 		return (0);
// 	i = 0;
// 	while (((unsigned char)s1[i] != '\0')
// 		&& ((unsigned char)s2[i] != '\0')
// 		&& (i < n - 1))
// 	{
// 		if ((unsigned char)s1[i] == (unsigned char)s2[i])
// 		{
// 			i++;
// 		}
// 		else
// 		{
// 			break ;
// 		}
// 	}
// 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// }