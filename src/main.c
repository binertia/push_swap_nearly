#include "push_swap.h"

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int		a_pivot;
	t_ls *head;
	t_ls *tmp;

	if (ac < 2)
		return (0);
	head = NULL;
	i = 1;
	while (i < ac)
	{
		if (!get_input(&head, av[i]))
			return (0);
		i++;
	}
	i = lst_len(head);
	if (i == 0 || check_ascen(&head))
		return (0);
	if (i < 6)
		return (lowlen_case(&head, i, 1));
	tmp = ft_lstdup(head);
	if (i % 2 == 1)
		a_pivot = quick_select_n(tmp, (i / 2) + 1);
	else
		a_pivot = quick_select_n(tmp, (i / 2));
	manda_sort(&head, a_pivot, &tmp);
	return (0);
}
