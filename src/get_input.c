#include "push_swap.h"
#include <unistd.h>

int get_input(t_ls **head, char *str)
{
	char **tmp;
	int	i;

	i = 0;
	tmp = ft_split(str, ' ');
	if (!tmp)
		return (0);
	while (tmp[i])
	{
		if (i == 2)
		if (!check_chr(tmp[i]))
			return (ft_free_all(head, tmp, i, 1));
		if (!ft_atoi_callback(head, tmp[i], ft_new_addback_int))
			return (ft_free_all(head, tmp, i, 1));
		i++;
	}
	i = ft_free_all(NULL, tmp, i - 1, 0);
	return (1);
}

int check_chr(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}
