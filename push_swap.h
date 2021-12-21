#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list	*next;
	int				num;
	int				index;
	int				flag;
}	t_list;

void	ft_lstprint(t_list *lst);

void	sorting_two(t_list **stack);
void	sorting_three(t_list **stack);
void	sorting_five(t_list **stack1, t_list **stack2);
void	set_index(t_list **stack1);
void	set_flag(t_list **stack1, int num);
void	choose_path_in_start_a(t_list **stack1, int num);
void	choose_path_in_start_b(t_list **stack2, int num);
int		choose_path_in_start_a_without_rotate(t_list **stack1,
			int min, int max);
void	start_a_b(t_list **stack1, t_list **stack2,
			int pos_a, int pos_b);
int		find_min(int a, int b);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstlast(t_list *lst);
int		ft_atoi(char *str);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_putstr_fd(char *s, int fd);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack1, t_list **stack2);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack1, t_list **stack2);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack1, t_list **stack2);
void	pa(t_list **stack1, t_list **stack2);
void	pb(t_list **stack1, t_list **stack2);
t_list	*find_elem(t_list **stack1, int pos);
int		find_position(t_list **stack1, int flag, int *pos_return);
t_list	*find_min_lst(t_list **stack);
t_list	*find_max_lst(t_list **stack);
int		check_pos(t_list **stack, t_list *min);
int		count_lst(t_list **stack);
void	push_min_lst(t_list **stack1, t_list **stack2);
void	check_identical(t_list **stack1);
int		check_sorting(t_list **stack1);
void	sorting(t_list **stack1, int count);

#endif