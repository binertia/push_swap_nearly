#include "push_swap.h"

static int	findintlen(long n)
{
	int	i;
	
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	while (n )
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int	j;
	int	k;
	long	num;
	char	*p_r;
	
	num = n;
	k = findintlen(num);
	j = 0;
	p_r = (char *)malloc(sizeof(char) * (k + 1));
	if (!p_r)
		return (0);
	if (num < 0)
	{
		j = 1;
		num *= -1;
		p_r[0] = '-';
		p_r[k] = '\0';
	}
	while (k != j )
	{
		p_r[--k] = (num % 10) + '0';
		num /= 10;
	}
	return (p_r);
}

