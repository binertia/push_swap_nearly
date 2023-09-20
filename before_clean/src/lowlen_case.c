#include "push_swap.h"
void case_two(t_ls **head)
{
	write(1, "hihi\n", 5);
	if ((*head)->index > (*head)->next->index)
		ft_single_out(head, 'a', ft_swap);
	write(1, "hh0-\n", 5);
}

void case_three(t_ls **head)
{
	write(1, "inln3\n", 5);
	if ((*head)->index > (*head)->next->index) //21 31 32
	{
		if ((*head)->index > (*head)->next->next->index) //312 321
		{
			if ((*head)->next->index < (*head)->next->next->index) //312
			{
				write(1, "+++++++++\n", 10);
				ft_single_out(head, 'a', ft_rev);
				return;
			}
			ft_single_out(head, 'a', ft_swap);
			ft_single_out(head, 'a', ft_rrev);
		}
		else
			ft_single_out(head, 'a', ft_swap);
	}
	else
	{
		if ((*head) -> index > (*head) -> next -> next -> index) //231
			ft_single_out(head, 'a', ft_rrev);
		else
		{
			ft_single_out(head, 'a', ft_swap);
			ft_single_out(head, 'a', ft_rev);
		}
	}
}

int lowlen_case(t_ls **head, int nth_case)
{
	write(1, "in_lwln\n", 7);
	if (nth_case == 2)
	//write(1, "get 2\n", 7);
		case_two(head);
	else if (nth_case == 3)
		case_three(head);
	else if (nth_case == 4)
		case_four(head);
	else if (nth_case == 5)
		case_five(head);
	write(1, "_finishh_\n",9);
	t_ls *god = *head;
	while (god)
	{
		write(1, ft_itoa(god -> index),9);
		write(1, "((()))\n", 7);
		god= god -> next;
	}
	write(1, "lst pass\n",9);
	free_list(head);
	return (0);
}
