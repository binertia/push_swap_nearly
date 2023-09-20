#include "push_swap.h"

void init_push_case_4(t_ls **src, t_ls **dst, int pivot)
{
	int i;

	i = 2;
	while (i)
	{
		if ((*src)->index >= pivot)
			ft_single_out(src, 'a', ft_rev);
		else
		{
			ft_push(src, dst, 'b');
			i--;
		}
	}
}

void case_four(t_ls **ls) //2134
{
	t_ls *n_ls;
	int pivot;

	n_ls = NULL;
	pivot = small_select(*ls);

	init_push_case_4(ls, &n_ls, pivot);
	if ((*ls)->index > (*ls)->next->index && n_ls->index < n_ls->next->index)
		ft_mainout(ls, &n_ls, 0, ft_swap);
	else if ((*ls)->index > (*ls)->next->index)
		ft_single_out(ls, 'a', ft_swap);
	else if (n_ls->index < n_ls->next->index)
		ft_single_out(&n_ls, 'b', ft_swap);
	p_back(&n_ls, ls);
}
