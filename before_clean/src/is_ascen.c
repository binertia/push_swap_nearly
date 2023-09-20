#include "push_swap.h"

int	is_ascen(t_ls *n)
{
	while (n -> next)
	{
		if (n -> index > n -> next -> index)
			return (0);
		n = n -> next;
	}
	return (1);
}
