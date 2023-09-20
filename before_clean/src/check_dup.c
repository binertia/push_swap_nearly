#include "push_swap.h"
int	check_dup(t_ls *n)
{
	t_ls	*temp;

	while (n -> next)
	{
		temp = n -> next;
		while (temp)
		{
			if (n -> value == temp -> value)
				return (0);
			temp = temp -> next;
		}
		n = n -> next;
	}
	return (1);
}
