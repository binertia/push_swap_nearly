#include "push_swap.h"

static int	lower_pivot(t_ls *head, int pivot)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head -> value <= pivot)
			i++;
		head = head -> next;
	}
	return (i);
}

void case_five(t_ls **a_head)
{
	t_ls *b_head;
	t_ls *b_tail;
	int low_pivot;
	int pivot;

	b_tail = NULL;
	b_head = NULL;
	pivot = small_select(*a_head);
	ft_push(a_head, &b_head, &b_tail);
	ft_push(a_head, &b_head, &b_tail);
	write(1,"pa\npa\n", 6);
	low_pivot = lower_pivot(*a_head, pivot);
	write(1,"\n___", 4);
	write(1,ft_itoa(low_pivot), 1);
	write(1,"___\n", 4);
	if (low_pivot == 1)
	{
		if (eq_pivot(*a_head, pivot))
			ccase_1_piv(a_head, &b_head);
		else
			ccase_1(a_head, &b_head, &b_tail);
	}
	else if (low_pivot == 2)
		ccase_2(a_head, &b_head);
	else
		ccase_3(a_head, &b_head);
	write(1,"____\n",5);
	int	i = 0;
	while(*a_head)
	{
		i++;
	    write(1,"\n_\n",3);
		write(1,ft_itoa((*a_head)->value),1);
		*a_head = (*a_head) -> next;
	    write(1,"\n_\n",3);
	}
	write(1,"____\n",5);
	write(1, ft_itoa(i), 1);
	write(1,"____\n",5);
}

void ccase_1(t_ls **a_head, t_ls **b_head, t_ls **b_tail)
{
	t_ls	*a_tail;

	a_tail = ft_lstlast(*a_head);
	if ((*a_head) -> value < (*a_head) -> next -> value)
	{
		if ((*a_head) -> next -> value < (*a_head) -> next -> next -> value)
			ft_mainout(a_head, b_head, 0, ft_rev);
		else if ((*a_head) -> value > (*a_head) -> next -> next -> value)
			ft_si_out(b_head, b_tail, 'b', ft_rev);
		else
		{
			ft_mainout(a_head, b_head, 0, ft_rev);
			ft_si_out(a_head, &a_tail, 'a', ft_swap);
		}
	}
	else
	{
		if ((*a_head)->next->value > (*a_head)->next->next->value)
			ft_mainout(a_head, b_head, 0, ft_swap);
		else
		{
			if ((*a_head) ->value > (*a_head)->next->next->value)
				ft_mainout(a_head, b_head, 0, ft_rrev);
			else
			{
				ft_mainout(a_head, b_head, 0, ft_swap);
				ft_si_out(a_head, &a_tail, 'a', ft_rrev);
			}
		}
	}
	ccase_1_push(a_head, b_head);
}

void	ccase_1_push(t_ls **a_head, t_ls **b_head)
{
	t_ls	*a_tail;
	int		i;

	i = 1;
	a_tail = ft_lstlast(*a_head);
	ft_push(b_head, a_head, &a_tail);
	write(1,"pb\n", 3);
	if (a_tail -> value < (*b_head) -> value)
	{
		ft_push(b_head, a_head, &a_tail);
		write(1,"pb\n", 3);
		i--;
	}
	if (i)
		ft_si_out(a_head, &a_tail, 'a', ft_rrev);
	p_back(b_head, a_head);
	if (a_tail -> value < (*a_head) -> value)
		ft_si_out(a_head, &a_tail, 'a', ft_rrev);
}

void ccase_1_piv(t_ls **a_head, t_ls **b_head)
{
	t_ls *a_tail;

	a_tail = ft_lstlast(*a_head);
	if ((*a_head) -> value < (*a_head) -> next -> value)
	{
		if ((*a_head) -> value < (*a_head) -> next -> next -> value)
		{
			if ((*a_head) -> next -> value < (*a_head) -> next -> next -> value)
			{
				if ((*b_head) -> value < (*b_head) -> next -> value)
					ft_si_out(b_head, &((*b_head) -> next), 'b', ft_swap);
			}
			else
			{
				ft_mainout(a_head, b_head, 0, ft_swap);
				ft_si_out(a_head, &a_tail, 'a', ft_rev);
			}
		}
		else
			ft_mainout(a_head, b_head, 0, ft_rrev);
	}
	else
	{
		if ((*a_head) -> next -> value > (*a_head) -> next ->next -> value)
		{
			ft_mainout(a_head, b_head, 0, ft_swap);
			ft_si_out(a_head, a_head, 'a', ft_rrev);
		}
		else
		{
			if ((*a_head) -> value > (*a_head) -> next -> next -> value)
				ft_mainout(a_head, b_head, 0, ft_rrev);
			else
				ft_mainout(a_head, b_head, 0, ft_swap);
		}
	}
	p_back(b_head, a_head);
}


void ccase_2(t_ls **a, t_ls **b)
{
	t_ls	*a_tail;
	
	a_tail = ft_lstlast(*a);
	if ((*a)->value < (*a)->next->value)
	{
		if ((*a) -> value < (*a) -> next -> next -> value)
		{
			if ((*a)-> next -> value < (*a) -> next -> next -> value)
				ft_mainout(a, b, 0, ft_rrev);
			else
				ft_mainout(a, b, 0, ft_swap);
		}
		else
			ft_mainout(a, b, 0, ft_rev);
	}
	else
	{
		if ((*a) -> value > (*a) -> next -> next -> value)
		{
			if ((*a) -> next -> value > a_tail -> value)
			{
				ft_mainout(a, b, 0, ft_rrev);
				ft_si_out(a, &a_tail, 'a', ft_swap);
			}
			else
			{
				if ((*b) -> value < (*b) -> next -> value)
					ft_si_out(b, &((*b) -> next), 'b', ft_swap);
			}
		}
		else
		{
			ft_mainout(a, b, 0, ft_swap);
			ft_si_out(a, &a_tail, 'a', ft_rrev);
		}
	}
	ccase_2_push(a, b);
}

void	ccase_2_push(t_ls **a, t_ls **b)
{
	t_ls	*a_tail;
	int		i;

	a_tail = ft_lstlast(*a);
	i = 2;
	if ((*a) -> value < (*b) -> value)
	{
		ft_push(b, a, &a_tail);
		write(1, "pb\n", 3);
		ft_si_out(a, &a_tail, 'a', ft_swap);
	}
	while (*b)
	{
		if ((*b) -> value < a_tail -> value)
		{
			ft_si_out(a, &a_tail, 'a', ft_rrev);
			i--;
		}
		ft_push(b , a, &a_tail);
		write(1, "pb\n", 3);
	}
	while (i > 0)
	{
		ft_si_out(a, &a_tail, 'a', ft_rrev);
		i--;
	}
}

void ccase_3(t_ls **a_head, t_ls **b_head)
{
	//case problem   4 5 3 1 2 (3 is missed in a)
	//,, 5 4 2 3 1 (2 3) is missed in a
	t_ls	*a_tail;

	a_tail = ft_lstlast(*a_head);
	if ((*a_head)->value > (*a_head)->next->value)
	{
		if ((*a_head)->value > (*a_head)->next->next->value)
		{
			if ((*a_head)->next->value < (*a_head)->next->next->value)
			{
//				ft_rev(a_head, &a_tail);
				ft_mainout(a_head, b_head, 1, ft_rev);
			}
				//ra, sa
			else
			{
				// ra sa
				ft_mainout(a_head, b_head, 1, ft_swap);
				ft_si_out(a_head, &a_tail, 'a', ft_rrev);
			}
		}
		else
			ft_mainout(a_head, b_head, 1, ft_swap);
	}
	else
		ccase_3_extend_else(a_head, b_head, &a_tail);
	while (*b_head)
	{
		ft_push(b_head, a_head, &a_tail);
		printf("pb\n");
		ft_si_out(a_head, &a_tail, 'a', ft_rev);
	}
}

void	ccase_3_extend_else(t_ls **a_head, t_ls **b_head, t_ls **a_tail)
{
	if ((*a_head)->value < (*a_head)->next->next->value)
	{
		if (!((*a_head) -> next ->value < (*a_head) -> next -> next -> value))
		{
			ft_mainout(a_head, b_head, 1, ft_swap);
			ft_si_out(a_head, a_tail, 'a', ft_rev);
		}
		else if ((*b_head)->value > (*b_head)->next->value)
			ft_si_out(b_head, a_tail, 'b', ft_swap);
	}
	else
		ft_mainout(a_head, b_head, 1, ft_rrev);
}

void	p_back(t_ls **b_head, t_ls **a_head)
{
	t_ls	*temp;

	temp = ft_lstlast(*a_head);
	while (*b_head)
	{
		ft_push(b_head, a_head, &temp);
		printf("pb\n");
	}
}
