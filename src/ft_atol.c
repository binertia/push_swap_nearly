#include "push_swap.h"

static int	is_space(const char *s)
{
	if ((*s >= '\t' && *s <= '\r') || *s == ' ')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	int	n_or_p;
	long	result;

	n_or_p = 1;
	result = 0;
	while (is_space(str))
		str++;
	if (*str == '-')
		n_or_p = -1;
	if(*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + *str++ - '0';
	return (result * n_or_p);
}
