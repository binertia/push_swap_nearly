#include "push_swap.h"
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	check_chr(char *s)
{
	int	i;

	int j = 0;
	while (s[j])
	{
		write(1, &s[j], 1);
		j++;
	}
		//
	i = 0;
	if (!ft_strlen(s))
		return (0);
	while(s[i])
	{
		write(1, &s[i], 1);
		if ((s[i] >= '0' && s[i] <= '9'))
			i++;
		else if ((s[i] >= '\t' && s[i] <= '\r')|| s[i] == ' ')
			i++;
		else if (s[i] == '+' || s[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}
