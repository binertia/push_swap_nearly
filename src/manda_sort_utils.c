#include "push_swap.h"

void	ft_swap(t_ls **head, t_ls **tail)
{
//	int		temp;

	t_ls *temp;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	*tail = ft_lstlast(*head);
//	temp = (*head) -> value;
//	(*head) -> value = (*head) -> next -> value;
//	(*head) -> next -> value = temp;
	temp = (*head) -> next;
	(*head) -> next = temp -> next;
	temp -> next = *head;
	*head = temp;
}

void ft_rev(t_ls **head, t_ls **tail)
{
	t_ls	*temp;

	*tail = ft_lstlast(*head);
	temp = *head;
	*head = (*head) -> next;
	temp -> next = NULL;
	(*tail) -> next = temp;
	*tail = temp;
}

void ft_rrev(t_ls **head, t_ls **tail)
{
	t_ls *temp_a;

	*tail = ft_lstlast(*head);
	temp_a = *head;
	while (temp_a->next->next != NULL)
		temp_a = temp_a->next;
	*tail = temp_a;
	temp_a = temp_a->next;
	(*tail) ->next = NULL;
	temp_a -> next = *head;
	*head = temp_a;
	//
	
	//tmp = *head;
	//*head = *tail;
	//(*head) -> next = tmp;
}

void	ft_push(t_ls **src, t_ls **dst, t_ls **dst_tail)
{
	t_ls	*temp;
	t_ls	*new;

	new = *dst;
	temp = *src;
	*src = (*src) -> next;
	if (!new)
	{
		new = temp;
		temp -> next = NULL;
		*dst = temp;
	}
	else
	{
		temp -> next = *dst;
		*dst = temp;
	}
	*dst_tail = ft_lstlast(*dst);
}
