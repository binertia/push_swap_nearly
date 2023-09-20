#include "push_swap.h"
int	get_index(t_ls *n, int num)
{
	int	i;

	i = 1;
	while (n)
	{
		if (n -> value < num)
			i++;
		n = n -> next;
	}
	return (i);
}

void	add_index(t_ls *n)
{
	t_ls	*temp;
	int	num;

	temp = n;
	while (temp)
	{
		num = temp -> value;
		write(1, "\n==", 3);
		write(1, ft_itoa(num), 1);
		write(1, "==\n", 3);
		num = get_index(n, num);
		temp -> index = num;
		temp = temp -> next;
	}
}
