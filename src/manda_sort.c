#include "push_swap.h"

void manda_sort(t_ls **head, int a_pivot, t_ls **to_free)
{
	t_ls *b_head;

	ft_free_list(to_free);
	get_order(*head);
	b_head = init_sort(head, a_pivot);

	//
	t_ls *temp;	
	temp = *head;
	write(1, "__a_ls\n",7);
	while (temp)
	{
		write(1,"----", 4);
		write(1, ft_itoa(temp -> value), 2);
		write(1,"----\n", 5);
		temp = temp -> next;
	}
	temp = b_head;
	write(1, "\n\n__b_ls\n",9);
	while (temp)
	{
		write(1,"----", 4);
		write(1, ft_itoa(temp -> value), 2);
		write(1,"----\n", 5);
		temp = temp -> next;
	}
	//
	sorting(head, &b_head);
	ft_free_list(head);
	b_head = NULL;
}

t_ls	*init_sort(t_ls **a_head, int a_pivot)
{
	t_ls *a_tail;
	t_ls *b_head;
	t_ls *b_tail;
	int	count;

	if (a_pivot)
		;
	b_head = NULL;
	a_tail = ft_lstlast(*a_head);
	b_tail = NULL;
	count = lst_len(*a_head) / 2;
	if (lst_len(*a_head) % 2 == 1)
		count++;
	while (count)
	{
		if ((*a_head)-> value < a_pivot)
		{
			ft_push(a_head, &b_head, &b_tail);
			write(1,"pa\n", 3);
			count--;
		}
		else
			ft_si_out(a_head, &a_tail, 'a', ft_rev);
	}
	return (b_head);
}

