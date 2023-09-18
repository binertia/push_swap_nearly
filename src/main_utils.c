#include "push_swap.h"

int lst_len(t_ls *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
