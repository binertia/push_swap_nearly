#include "push_swap.h"


/*
void ft_new_addback_int(t_ls **head, int value)
{
	t_ls	*new;

	new = ft_lstnew(value);
	ft_lstadd_back(head, new);
}
*/

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

int	ft_lstlen(t_ls *n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n -> next;
		i++;
	}
	return (i);
}

////
/*

t_ls	*ft_lstlast(t_ls *n)
{
	while (n -> next != NULL)
		n = n -> next;
	return (n);
}
*/

int	ft_lstnew_addback(t_ls **n, int num)
{
	t_ls	*new;

	new = ft_lstnew(num);
	ft_lstadd_back(n, new);
	return (1);
}

int	split_size(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_list(t_ls **n, char *str)
{
	char **chunk;
	int		i;

	i = 0;
	chunk = ft_split(str ,' ');

	while (chunk[i])
	{
		write(1, "bfor_atoi\n", 11);
		if (!ft_atoi_cb(n, chunk[i], ft_lstnew_addback))
		{
			write(1, "__is_free__", 11);
			return (free_all(n, NULL, chunk, split_size(chunk)));
		}
		write(1, "after_atoi\n", 11);
		i++;
	}
	return (free_str(chunk, split_size(chunk)) + 1);
}
