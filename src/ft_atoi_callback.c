#include "push_swap.h"

static int is_space(char s)
{
	if ((s >= '\t' && s <= '\r') || s == ' ')
		return (1);
	return (0);
}

int ft_atoi_callback(t_ls **h, const char *s, void (*f)(t_ls **, int))
{
	int is_pos;
	int result;
	long	check;

	check = ft_atol(s);
	is_pos = 1;
	result = 0;
	while (is_space(*s))
		s++;
	if (*s == '-')
		is_pos = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		result = (result * 10) + *s++ - '0';
	}
	if (result != check)
		return (0);
	f(h, result * is_pos);
	return (1);
}
