#include "push_swap.h"

void	ft_single_out(t_ls **n, char c, void (*f)(t_ls **))
{
	void	(*swap)(t_ls **);
	void	(*rev)(t_ls **);
	void	(*rrev)(t_ls **);

	swap = ft_swap;
	rev = ft_rev;
	rrev = ft_rrev;

	f(n);
	if (f == swap)
		write(1, "s", 1);
	else if (f == rev)
		write(1, "r", 1);
	else if (f == rrev)
		write(1, "rr", 2);
	if (c == 'a')
		write(1, &c, 1);
	else if (c == 'b')
		write(1, &c, 1);
	write(1, "\n", 1);
}
