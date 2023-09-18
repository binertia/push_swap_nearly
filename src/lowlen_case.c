#include "push_swap.h"

// free after use
int lowlen_case(t_ls **head, int nth_case, int is_free)
{
	if (nth_case == 2)
		case_two(head);
	else if (nth_case == 3)
		case_three(head);
	else if (nth_case == 4)
		case_four(head);
	else if (nth_case == 5)
		case_five(head);
	if (is_free)
		ft_free_list(head);
	return (0);
}

void case_two(t_ls **head)
{
	t_ls	*tail;

	tail = (*head) -> next;
	if ((*head)->value > (*head)->next->value)
		ft_si_out(head, &tail,'a', ft_swap);
}

void case_three(t_ls **head)
{
	t_ls	*tail;

	tail = (*head) -> next -> next;
	if ((*head)->value > (*head)->next->value)
	{
		if ((*head)->value > (*head)->next->next->value)
		{
			if ((*head)->next->value < (*head)->next->next->value)
			{
				ft_si_out(head, &tail, 'a', ft_rev);
				return;
			}
		ft_si_out(head, &tail, 'a', ft_swap);
		ft_si_out(head, &tail, 'a', ft_rrev);
		}
		else
		ft_si_out(head, &tail, 'a', ft_swap);
	}
	else
	{
		if ((*head) -> value > (*head) -> next -> next -> value)
			ft_si_out(head, &tail, 'a', ft_rrev);
		else
		{
			ft_si_out(head, &tail, 'a', ft_swap);
			ft_si_out(head, &tail, 'a', ft_rev);
		}
	}
}

void case_four(t_ls **ls)
{
	t_ls *n_ls;
	t_ls	*ls_tail;
	int pivot;

	n_ls = NULL;
	ls_tail = ft_lstlast(*ls);
	pivot = small_select(*ls);

	init_push_case_4(ls, &n_ls, pivot);
	if ((*ls)->value > (*ls)->next->value && n_ls->value < n_ls->next->value)
		ft_mainout(ls, &n_ls, 0, ft_swap);
	else if ((*ls)->value > (*ls)->next->value)
		ft_si_out(ls, &ls_tail, 'a', ft_swap);
	else if (n_ls->value < n_ls->next->value)
		ft_si_out(ls, &ls_tail, 'b', ft_swap);
	p_back(&n_ls , ls);
}

void	init_push_case_4(t_ls **src ,t_ls **dst, int pivot)
{
	int	i;
	t_ls	*tail;

	tail = ft_lstlast(*src);
	i = 2;
	while (i)
	{
		if ((*src) -> value >= pivot)
			ft_si_out(src, &tail, 'a', ft_rev);
		else
		{
			ft_push(src, dst, &tail);
			printf("\npa\n");
			i--;
		}
	}
}
