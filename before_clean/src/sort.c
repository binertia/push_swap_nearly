#include "push_swap.h"
int	get_maxbit(t_ls *n)
{
	int	bit;
	int	max;

	bit = 0;
	max= n -> index;
	while (n)
	{
		if (n -> index > max)
			max = n -> index;
		n = n -> next;
	}
	while ((max >> bit) != 0)
		bit++;
	return (bit);
}

void	radix(t_ls **n, t_ls **s)
{
	int	bit;
	int	max_bit;
	int	i;
	int	len;
	t_ls	*temp;

	bit = 0;
	len = ft_lstlen(*n);
	max_bit = get_maxbit(*n);
	while (bit < max_bit)
	{
		i = 0;
		while (i++ < len)
		{
			temp = *n;
			if (((temp -> index >> bit) & 1) == 1)
				ft_single_out(n, 'a', ft_rev);
			else
				ft_push(n, s, 'b');
		}
		while (ft_lstlen(*s) != 0)
			ft_push(s, n, 'a');
		bit++;
	}
}

void	sort(t_ls **head)
{
	t_ls	*stack;

	stack = NULL;
	radix(head, &stack);
	//
	t_ls *temp = *head;
	while (temp)
	{
		write(1, ft_itoa(temp -> index), 2);
		write(1, "\n", 1);
		temp = temp -> next;
	}
	//
	free_list(head);
	head = NULL;
}

/*

if (tail && head -> next  != target)
tail prev find_target;
head -> next   next find_target;
*/
