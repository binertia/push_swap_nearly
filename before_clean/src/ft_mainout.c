#include "push_swap.h"

int	swap_decre(t_ls **head)
{
	if ((*head)->value < (*head)->next->value)
	{
		ft_swap(head);
		return (1);
	}
	return (0);
}

int	 swap_incre(t_ls **head)
{
	if ((*head)->value > (*head)->next->value)
	{
		ft_swap(head);
		return (1);
	}
	return (0);
}

int b_swap(t_ls **head, int incre)
{
	if (incre)
		return (swap_incre(head));
	else
		return (swap_decre(head));
}

void ft_mainout(t_ls **a_l, t_ls **b_l, int num, void (*fn)(t_ls **))
{
	void	(*swap)(t_ls **) = ft_swap;
	void	(*rev)(t_ls **) = ft_rev;
	void	(*rrev)(t_ls **) = ft_rrev;
	int is_swap;

	fn(a_l);
	is_swap = b_swap(b_l, num);
	if (fn == swap)
		write(1,"s",1);
	else if (fn == rev)
		write(1,"r",1);
	else if (fn == rrev)
		write(1,"rr",2);
	if (is_swap)
		write(1,"s\n",2);
	else
		write(1,"a\n",2);
}
