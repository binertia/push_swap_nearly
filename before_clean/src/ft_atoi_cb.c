#include "push_swap.h"
char *skip_space(char *s)
{
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	return (s);
}

int	is_positive(char c)
{
	if (c == '+' || (c >= '0' && c <= '9'))
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}

int	ft_atoi_cb(t_ls **n, char *s, int (*fn)(t_ls **, int))
{
	long	sign;
	long	res;

	res = 0;
	if (!check_chr(s))
		return (0);
	s = skip_space(s);
	sign = is_positive(*s);
	if (!sign)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
		res = (res * 10) + *s++ - '0';
	if (*s)
		return (0);
	res = res * sign;
	if (res < -2147483648 || res > 2147483647)
		return (0);
	fn(n, res);
	return (1);
}
