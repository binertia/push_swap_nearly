#include "push_swap.h"

t_ls	*ft_lstdup(t_ls *src)
{
	t_ls *head;
	t_ls *current;

	if (!src)
		return (0);
	head = NULL;
	current = src;
	while (current)
	{
		ft_new_addback_int(&head, current->value); // need handle malloc err
		current = current->next;
	}
	return (head);
}

void ft_new_addback_int(t_ls **head, int value)
{
	t_ls	*new;

	new = ft_lstnew(value);
	ft_lstadd_back(head, new);
}

void	ft_lstadd_back(t_ls **lst, t_ls *new)
{
	t_ls	*tmp;

	if (*lst != NULL)
	{
		tmp = ft_lstlast(*lst);
		tmp -> next = new;
	}
	else
		*lst = new;
}

t_ls	*ft_lstnew(int value)
{
	t_ls	*new;

	new = (t_ls *)malloc(sizeof(t_ls));
	if (new == NULL)
		return (NULL);
	new -> value = value;
	new -> next = NULL;
	return (new);
}

t_ls	*ft_lstlast(t_ls *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
