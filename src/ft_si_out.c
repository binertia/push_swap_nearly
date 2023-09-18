#include "push_swap.h"

void	ft_si_out(t_ls **f, t_ls **t, char c, void (*fn)(t_ls **, t_ls **))
{
	void	(*swap)(t_ls **, t_ls **);
	void	(*rev)(t_ls **, t_ls **);
	void	(*rrev)(t_ls **, t_ls **);

	swap = ft_swap;
	rev = ft_rev;
	rrev = ft_rrev;
	if (fn == swap)
		write(1,"s",1);
	else if (fn == rev)
		write(1,"r",1);
	else if (fn == rrev)
		write(1,"rr",2);
	if (c == 'a')
		write(1,"a\n", 2);
	else
		write(1,"b\n",2);
	fn(f, t);
}
