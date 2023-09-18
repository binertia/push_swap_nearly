#include "push_swap.h"

static int	get_max_bit(t_ls *ls)
{
	int	bit;
	int	num;

	num = ls -> order;
	bit = 0;
	while (ls)
	{
		if (ls -> order > num)
			num = ls -> order;
		ls = ls -> next;
	}
	while ((num >> bit) != 0)
		bit++;
	return (bit);
}

static int	gas_station(t_ls **a, int bit, int is_ascen)
{
	int	count;
	t_ls *temp;

	count = 0;
	temp = *a;
	while (temp)
	{
		if (((temp -> order >> bit)  & 1 ) == is_ascen)
			temp -> gas = 0;
		else
		{
			temp -> gas = 1;
			count++;
		}
		temp = temp -> next;
	}
	return (count);
}

static int	god_of_loop(t_ls **s, t_ls **d, char c)
{
	t_ls	*d_tail;
	t_ls	*s_tail;

	d_tail = ft_lstlast(*d);
	s_tail = ft_lstlast(*s);
	if ((*s) -> gas == 1)
	{
		(*s) -> gas = 0;
		ft_push(s, d, &d_tail);
		write(1, "p--", 3);
		write(1, &c, 1);
		write(1, "\n", 1);
	//
	t_ls *temp = *s;
	write(1, "\n\npush_b\n",9);
	while (temp)
	{
		write(1,"----", 4);
		write(1, ft_itoa(temp -> value), 2);
		write(1,"----\n", 5);
		temp = temp -> next;
	}
	//
		return (1);
	}
	else
		ft_si_out(s, &s_tail, c, ft_rev);
	return (0);
}


static void	god_of_sorting(t_ls **s, t_ls **d, int is_ascen, char c)
{
	int	bit;
	int	count_p;
	int	max_bit;
	int	i;
	t_ls	*tail;

	tail = ft_lstlast(*s);
	bit = 0;
	max_bit = get_max_bit(*s);
	while (bit < max_bit)
	{
		count_p = gas_station(s, bit, is_ascen);
		//
	write(1, "\ngas : ",7);
	write(1,ft_itoa(count_p), 1);
	write(1, "\n", 1);
		//
		i = count_p;
		while (i)
			i -= god_of_loop(s, d, c);
		while (count_p)
		{
				write(1,"p\n",2);
			ft_push(d, s, &tail);
			count_p--;
		}
	//
	t_ls *temp = *s;
	write(1, "\n\naftr_b\n",9);
	while (temp)
	{
		write(1,"----", 4);
		write(1, ft_itoa(temp -> value), 2);
		write(1,"----\n", 5);
		temp = temp -> next;
	}
	//
		bit++;
	}
}

int	is_finish(t_ls *s, int ascen)
{
	if (ascen)
	{
		while (s && s -> next && s -> value < s -> next -> value)
			s = s -> next;
	}
	else
	{
		while (s && s -> next && s -> value > s -> next -> value)
			s = s -> next;
	}
	if ((s -> next) == NULL)
		return (1);
	return (0);
}

static int	get_min_order(t_ls *s)
{
	int	i;

	i = s -> order;
	while (s)
	{
		if (s -> order < i)
			i = s -> order;
		s = s -> next;
	}
	return (i);
}

static int	get_max_order(t_ls *s)
{
	int	i;

	i = s -> order;
	while (s)
	{
		if (s -> order > i)
			i = s -> order;
		s = s -> next;
	}
	return (i);
}

static void	last_sort_a(t_ls **a, t_ls **b)
{
	int	i = get_min_order(*a);
	int	j = 0;
	t_ls	*temp;

	while((*a) -> next)
	{
		if ((*a) -> order == i)
		{
			ft_push(a, b, &temp);
			j++;
			i++;
		}
		else if ((ft_lstlast(*a)) -> order == i)
			ft_si_out(a, &temp, 'a', ft_rrev);
		else
			ft_si_out(a, &temp, 'a', ft_rev);
	}
	while (j--)
		ft_push(b, a, &temp);
}

static void	last_sort_b(t_ls **a, t_ls **b)
{
	int	i = get_max_order(*b);

	t_ls	*temp;

	temp = ft_lstlast(*b);
	while(*b)
	{
		if ((*b) -> order == i)
		{
			ft_push(b, a, &temp);
			i--;
		}
		else if ((ft_lstlast(*a)) -> order == i)
			ft_si_out(b, &temp, 'b', ft_rrev);
		else
			ft_si_out(b, &temp, 'b', ft_rev);
	}
}
void	sorting(t_ls **a, t_ls **b)
{
	t_ls	*test;

	god_of_sorting(a, b, 1, 'a');
	//
	t_ls *temp;
	temp = *a;
	write(1, "\n\nfin__a\n",9);
	while (temp)
	{
		write(1,"----", 4);
		write(1, ft_itoa(temp -> value), 2);
		write(1,"----\n", 5);
		temp = temp -> next;
	}
	temp = *b;
	write(1, "\n\nsort_b=====----====\n",26);
	while (temp)
	{
		write(1,"----", 4);
		write(1, ft_itoa(temp -> value), 2);
		write(1,"----\n", 5);
		temp = temp -> next;
	}
	//
	if (!is_finish(*a, 1))
		last_sort_a(a, b);
	temp = *b;
	write(1, "\n\naftr==lasrt_a---====\n",26);
	while (temp)
	{
		write(1,"----", 4);
		write(1, ft_itoa(temp -> value), 2);
		write(1,"----\n", 5);
		temp = temp -> next;
	}
	god_of_sorting(b, a, 0, 'b');
	//
	//
	temp = *a;
	write(1, "\n\nsort_a\n",9);
	while (temp)
	{
		write(1,"----", 4);
		write(1, ft_itoa(temp -> value), 2);
		write(1,"----\n", 5);
		temp = temp -> next;
	}
	temp = *b;
	write(1, "\n\nsort_b\n",9);
	while (temp)
	{
		write(1,"----", 4);
		write(1, ft_itoa(temp -> value), 2);
		write(1,"----\n", 5);
		temp = temp -> next;
	}
	//
	//
	if (!is_finish(*b, 0))
		last_sort_b(a, b);
	else
		p_back(b, a);
//god_of_sorting(b, a, 0, 'b');
//p_back(b, a);
//	if (!is_finish(*a, 0))
//	{
//ft_rev(a, &tail);
//ft_rev(a, &tail);
//		radix(a, b);
//radix(a, b, *a, lst_len(*a));
//	}
	test = *a;
	while (test)
	{
		write(1, "\n==",3);
		write(1, ft_itoa(test -> value), 2);
		write(1, "==\n",3);
		test = test -> next;
	}
}
