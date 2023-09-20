#include "push_swap.h"

int	get_error(t_ls **n, int i)
{
	if (i)
		free_list(n);
	write(1, "Error\n", 6);
	return (0);
}
