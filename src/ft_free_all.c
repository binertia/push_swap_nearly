#include "push_swap.h"

int ft_free_all(t_ls **f, char **s, int i, int is_error)
{
	if (f && *f)
		ft_free_list(f);
	if (s && *s)
	{
		while (s[i])
			i++;
		while (i >= 0)
		{
			free(s[i]);
			i--;
		}
		free(s);
	}
	if (is_error == 1)
		printf("Error");
	return (0);
}

void	ft_free_list(t_ls **lst)
{
	t_ls	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)-> next;
		temp -> value = 0;
		free(temp);
	}
	*lst = NULL;
}
