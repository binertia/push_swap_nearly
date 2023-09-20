#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_ls *head;
	int	i;

	head = NULL;
	if (ac < 2)
		return (0);
	//
	i = 1;
	while (av[i])
	{
		if (!get_list(&head, av[i]))
			return (get_error(NULL, 0));
		i++;
	}
	if(!check_dup(head))
		return (get_error(&head, 1));
	add_index(head);
	if (is_ascen(head))
		return (free_list(&head));
	if (ft_lstlen(head) < 6)
	{
		write(1, "\nlowlen\n", 8);
		write(1, ft_itoa(ft_lstlen(head)),9);
		return (lowlen_case(&head, ft_lstlen(head)));
	}
	t_ls *temp = head;
	write(1, "\n__",3);
	while (temp)
	{
		write(1, ft_itoa(temp -> index), 1);
		write(1, "\n__",3);
		temp = temp -> next;
	}
	write(1, "main\n", 5);
	sort(&head);
	write(1, "_finishh_\n",9);
	t_ls *god = head;
	while (god)
	{
		write(1, ft_itoa(god -> index),9);
		write(1, "((()))\n", 7);
		god= god -> next;
	}
	write(1, "lst pass\n",9);
	return (0);
}
