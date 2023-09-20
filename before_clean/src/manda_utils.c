#include "push_swap.h"

void	ft_push(t_ls **s, t_ls **d, char c)
{
	t_ls *temp;

	if (!ft_lstlen(*s))
		write(1, "Error while push. recheck\n", 26);
	temp = *s;
	*s = (*s) -> next;
	if (!*d)
	{
		*d = temp;
		(*d) -> next = NULL;
	}
	else
	{
		temp -> next = *d;
		*d = temp;
	}
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	ft_swap(t_ls **head)
{
	int		num;

	num = (*head) -> value;
	(*head) -> value = (*head) -> next -> value;
	(*head) -> next -> value = num;
	num = (*head) -> index;
	(*head) -> index = (*head) -> next -> index;
	(*head) -> next -> index = num;
}

void	ft_rev(t_ls **head)
{
	t_ls	*temp;
	t_ls	*tail;

	tail = ft_lstlast(*head);
	temp = *head;
	*head = (*head) -> next;
	temp -> next = NULL;
	tail -> next = temp;
}

void	ft_rrev(t_ls **head)
{
	t_ls	*temp;
	t_ls	*tail;

	tail = ft_lstlast(*head);
	temp = *head;
	while (temp -> next != tail)
		temp = temp -> next;
	temp -> next = NULL;
	tail -> next = *head;
	*head = tail;
}
