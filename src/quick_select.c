#include "push_swap.h"

static void quick_swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static t_ls *get_parti(t_ls *low, t_ls *high)
{
	int pivot;
	t_ls	*i;
	t_ls	*j;

	pivot = low->value;
	i = low;
	j = low->next;
	while (j != high)
	{
		if (j->value < pivot)
		{
			i = i->next;
			quick_swap_int(&(i->value), &(j->value));
		}
		j = j->next;
	}
	quick_swap_int(&(i -> value), &(low -> value));
	return (i);
}

int	quick_select_n(t_ls *head, int n)
{
	t_ls *t_piv;
	t_ls *current;
	int pos_piv;

	if (!head)
		return (0);
	t_piv = get_parti(head, NULL);
	pos_piv = 0;
	current = head;
	while (current != t_piv)
	{
		pos_piv++;
		current = current->next;
	}
	if (pos_piv == n)
		return (t_piv -> value);
	else if (pos_piv < n)
		return (quick_select_n(t_piv->next, (n - pos_piv - 1)));
	else
		return (quick_select_n(head, n));
}
