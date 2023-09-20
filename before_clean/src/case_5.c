#include "push_swap.h"
static int lower_pivot(t_ls *head, int pivot)
{
	int i;

	i = 0;
	while (head)
	{
		if (head->index <= pivot)
			i++;
		head = head->next;
	}
	return (i);
}

void ccase_1_push(t_ls **a_head, t_ls **b_head)
{
	int i;
	t_ls *a_tail;

	i = 1;
	a_tail = ft_lstlast(*a_head);
	ft_push(b_head, a_head, 'a');
	if (a_tail->index < (*b_head)->index)
	{
		ft_push(b_head, a_head, 'a');
		i--;
	}
	if (i)
		ft_single_out(a_head, 'a', ft_rrev);
	p_back(b_head, a_head);
	if (a_tail->index < (*a_head)->index)
		ft_single_out(a_head, 'a', ft_rrev);
}

void ccase_1(t_ls **a_head, t_ls **b_head) // 145
{
	if ((*a_head)->index < (*a_head)->next->index)
	{
		if ((*a_head)->next->index < (*a_head)->next->next->index)
			ft_mainout(a_head, b_head, 0, ft_rev);
		else if ((*a_head)->index > (*a_head)->next->next->index)
		{
			if ((*b_head)->index < (*b_head)->next->index)
				ft_single_out(b_head, 'b', ft_rev);
		}
		else
		{
			ft_mainout(a_head, b_head, 0, ft_rev);
			ft_single_out(a_head, 'a', ft_swap);
		}
	}
	else
	{
		if ((*a_head)->next->index > (*a_head)->next->next->index)
			ft_mainout(a_head, b_head, 0, ft_swap);
		else
		{
			if ((*a_head)->index > (*a_head)->next->next->index)
				ft_mainout(a_head, b_head, 0, ft_rrev);
			else
			{
				ft_mainout(a_head, b_head, 0, ft_swap);
				ft_single_out(a_head, 'a', ft_rev);
			}
		}
	}
	ccase_1_push(a_head, b_head);
}


void ccase_1_piv(t_ls **a_head, t_ls **b_head)
{
	if ((*a_head)->index < (*a_head)->next->index)
	{
		if ((*a_head)->index < (*a_head)->next->next->index)
		{
			if ((*a_head)->next->index < (*a_head)->next->next->index)
			{
				if ((*b_head)->index < (*b_head)->next->index)
					ft_single_out(b_head, 'b', ft_swap);
			}
			else
			{
				ft_mainout(a_head, b_head, 0, ft_swap);
				ft_single_out(a_head, 'a', ft_rev);
			}
		}
		else
			ft_mainout(a_head, b_head, 0, ft_rrev);
	}
	else
	{
		if ((*a_head)->next->index > (*a_head)->next->next->index)
		{
			ft_mainout(a_head, b_head, 0, ft_swap);
			ft_single_out(a_head, 'a', ft_rrev);
		}
		else
		{
			if ((*a_head)->index > (*a_head)->next->next->index)
			{
				write(1,"____piv1____", 12);
				ft_mainout(a_head, b_head, 0, ft_rev);
			}
			else
				ft_mainout(a_head, b_head, 0, ft_swap);
		}
	}
	p_back(b_head, a_head);
}

void ccase_2_push(t_ls **a, t_ls **b)
{
	t_ls *a_tail;
	int i;

	i = 2;
	if ((*a)->index < (*b)->index)
	{
		ft_push(b, a, 'a');
		ft_single_out(a, 'a', ft_swap);
	}
	while (*b)
	{
		a_tail = ft_lstlast(*a);
		if ((*b)->index < a_tail->index)
		{
			ft_single_out(a, 'a', ft_rrev);
			i--;
		}
		ft_push(b, a, 'a');
	}
	while (i > 0)
	{
		ft_single_out(a, 'a', ft_rrev);
		i--;
	}
}
void ccase_2(t_ls **a, t_ls **b)
{
	if ((*a)->index < (*a)->next->index)
	{
		if ((*a)->index < (*a)->next->next->index)
		{
			if ((*a)->next->index < (*a)->next->next->index)
				ft_mainout(a, b, 0, ft_rrev);
			else
				ft_mainout(a, b, 0, ft_swap);
		}
		else
			ft_mainout(a, b, 0, ft_rev);
	}
	else
	{
		if ((*a)->index > (*a)->next->next->index)
		{
			if ((*a)->next->index > (*a)->next->next->index)
			{
				ft_mainout(a, b, 0, ft_rrev);
				ft_single_out(a, 'a', ft_swap);
			}
			else
			{
				if ((*b)->index < (*b)->next->index)
					ft_single_out(b, 'b', ft_swap);
			}
		}
		else
		{
			ft_mainout(a, b, 0, ft_swap);
			ft_single_out(a, 'a', ft_rrev);
		}
	}
	ccase_2_push(a, b);
}

void ccase_3_extend_else(t_ls **a_head, t_ls **b_head)
{
	if ((*a_head)->index < (*a_head)->next->next->index)
	{
		if (!((*a_head)->next->index < (*a_head)->next->next->index))
		{
			ft_mainout(a_head, b_head, 1, ft_swap);
			ft_single_out(a_head, 'a', ft_rev);
		}
		else if ((*b_head)->index > (*b_head)->next->index)
			ft_single_out(b_head, 'b', ft_swap);
	}
	else
		ft_mainout(a_head, b_head, 1, ft_rrev);
}

void ccase_3(t_ls **a_head, t_ls **b_head)
{
	// case problem   4 5 3 1 2 (3 is missed in a)
	//,, 5 4 2 3 1 (2 3) is missed in a
	if ((*a_head)->index > (*a_head)->next->index)
	{
		if ((*a_head)->index > (*a_head)->next->next->index)
		{
			if ((*a_head)->next->index < (*a_head)->next->next->index)
			{
				ft_mainout(a_head, b_head, 1, ft_rev);
			}
			else
			{
				ft_mainout(a_head, b_head, 1, ft_swap);
				ft_single_out(a_head, 'a', ft_rrev);
			}
		}
		else
			ft_mainout(a_head, b_head, 1, ft_swap);
	}
	else
		ccase_3_extend_else(a_head, b_head);
	while (*b_head)
	{
		ft_push(b_head, a_head, 'a');
		ft_single_out(a_head, 'a', ft_rev);
	}
}

void p_back(t_ls **b_head, t_ls **a_head)
{
	while (*b_head)
		ft_push(b_head, a_head, 'a');
}

void case_five(t_ls **a_head)
{
	t_ls *b_head;
	int low_pivot;
	int pivot;

	b_head = NULL;
	pivot = small_select(*a_head);
	ft_push(a_head, &b_head, 'b');
	ft_push(a_head, &b_head, 'b');
	low_pivot = lower_pivot(*a_head, pivot);
	write(1, "\n___", 4);
	write(1, ft_itoa(low_pivot), 1);
	write(1, "___\n", 4);
	if (low_pivot == 1)
	{
		if (eq_pivot(*a_head, pivot))
			ccase_1_piv(a_head, &b_head);
		else
			ccase_1(a_head, &b_head);
	}
	else if (low_pivot == 2)
		ccase_2(a_head, &b_head);
	else
		ccase_3(a_head, &b_head);
	//
	write(1, "____\n", 5);
	int i = 0;
	while (*a_head)
	{
		i++;
		write(1, "\n_\n", 3);
		write(1, ft_itoa((*a_head)->index), 1);
		*a_head = (*a_head)->next;
		write(1, "\n_\n", 3);
	}
	write(1, "____\n", 5);
	write(1, ft_itoa(i), 1);
	write(1, "____\n", 5);
}
