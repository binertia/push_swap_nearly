#include "push_swap.h"

void full_sort(t_ls **a_head, t_ls **b_head, int a_pivot, int b_pivot)
{
	t_ls *a_work;
	t_ls *b_work;
	int fin;

	fin = 0;
	a_work = NULL;
	b_work = NULL;
	while (!fin)
	{
		get_work_a(a_head, &a_work, a_pivot);
		if (!fin && !(b_work && b_work->next))
		{
			get_work_b(b_head, &b_work, b_pivot);
			fin = check_fin(a_work, b_work, fin);
		}
		full_sort_dowork(&a_work, &b_work, fin);
	}
	fin = check_fin(a_work, b_work, fin);
	if (fin == 1)
		full_sort_fin(b_head, &b_work, b_pivot, "b");
	else if (fin == 2)
		full_sort_fin(a_head, &a_work, a_pivot, "a");
	while (*b_head)
		ft_push(b_head, a_head, NULL);
}

void	full_sort_dowork(t_ls **a_work, t_ls **b_work, int fin)
{
	while (!fin && *b_work && *a_work && (*b_work) -> next)
	{
		if ((*a_work) -> value != (*b_work) -> value)
		{
			if ((*a_work) -> value == (*b_work) -> next -> value)
				do_work(b_work, "b");
			else
				do_work(a_work, "a");
		}
		else
			do_work_both(a_work, b_work);
	}
}

void	full_sort_fin(t_ls **head, t_ls **work, int pivot, char *s)
{
	while (1)
	{
			while (!(*work && (*work) -> next))
				get_work_b(head, work, pivot);
			if ((*work) -> value == 5)
				return ;
			while (*work)
				do_work(work, s);
	}
}

int	check_fin(t_ls *a_work, t_ls *b_work, int fin)
{
	while (a_work && fin != 1)
	{
		if (a_work->value == 5)
		{
			if (fin == 2)
				return (3);
			return (1);
		}
		a_work = a_work->next;
	}
	while (b_work && fin != 2)
	{
		if (b_work->value == 5)
		{
			if (fin == 1)
				return (3);
			return (2);
		}
		b_work = b_work->next;
	}
	return (0);
}

int get_len(t_ls *a_head, t_ls *b_head)
{
	int i;

	i = 0;
	while (a_head)
	{
		a_head = a_head->next;
		i++;
	}
	while (b_head)
	{
		b_head = b_head->next;
		i++;
	}
	return (i);
}
