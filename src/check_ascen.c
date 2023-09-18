#include "push_swap.h"

int	check_ascen(t_ls **head)
{
	t_ls	*temp;

	temp = *head;
	if (!(temp -> next))
		return (0);
	while (temp -> next && temp -> value < temp -> next -> value)
	{
		temp = temp -> next;
	}
	if (!(temp -> next))
	{
		ft_free_list(head);
		return (1);
	}
	return (0);
}
