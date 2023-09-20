#include "push_swap.h"

int	free_str(char **s, int end_line)
{
	int	line;

	line = 0;
	while (line < end_line && line++ != 0)
		free(s[line]);
	free(s);
	return (0);
}

int	free_list(t_ls **n)
{
	t_ls	*temp;

	while(*n)
	{
		temp = *n;
		*n = (*n) -> next;
		free(temp);
	}
	n = NULL;
	return (0);
}

int	free_all(t_ls **head, t_ls **other, char **s, int num)
{
	if (head)
	{
		if (*head)
			return (free_list(head));
	}
	if (other)
	{
		if (*other)
			return (free_list(other));
	}
	if (s)
	{
		if (*s)
			return (free_str(s, num));
	}
	return (0);
}
