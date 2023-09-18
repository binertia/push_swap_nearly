#include "push_swap.h"

// swap = 1;
// rev = 2;
// rrev = 3;

int	check_a_fin(t_ls *a, t_ls **work)
{
	while (a -> next && a -> value < a -> next -> value)
		a = a -> next;
	if (!(a -> next))
	{
		ft_new_addback_int(work, 5);
		return (1);
	}
	return (0);
}

int	check_b_fin(t_ls *b,t_ls **work)
{
	while (b -> next && b -> value > b -> next -> value)
		b = b -> next;
	if (!((b) -> next))
	{
		ft_new_addback_int(work, 5);
		return (1);
	}
	return (0);
}

void	add_work(t_ls **h, t_ls **tail, t_ls **work, void (*f)(t_ls **, t_ls **))
{
	void	(*swap)(t_ls **, t_ls **);
	void	(*rev)(t_ls **, t_ls **);
	void	(*rrev)(t_ls **, t_ls **);
	int		i;

	i = 0;
	f(h, tail);
	swap = ft_swap;
	rev = ft_rev;
	rrev = ft_rrev;
	if (f == swap)
		i = 1;
	else if (f == rev)
		i = 2;
	else if (f == rrev)
		i = 3;
	ft_new_addback_int(work, i);
}

void	get_work_a(t_ls **a, t_ls **work, int a_pivot)
{
	t_ls *tail;

	tail = ft_lstlast(*a);
	if ((*a) -> value == a_pivot && check_a_fin(*a, work))
			return ;
	if ((*a) -> value < (*a) -> next -> value)
	{
		if ((*a) -> value < tail -> value)
		{
			if((*a) -> next -> value < tail -> value)
			{
				add_work(a, &tail, work, ft_rrev);
				add_work(a, &tail, work, ft_swap);
				add_work(a, &tail, work, ft_rev);
				add_work(a, &tail, work, ft_swap);
			}
		}

	}
}
		// ------
//
//				}
//				else
//				{
//
//
//				}
//
//				else
//				add_work(a, &tail, work, ft_rrev);
//				add_work(a, &tail, work, ft_swap);
//			}
//			add_work(a, &tail, work, ft_rev);
//		}
//		else if ((*a) ->next->value < tail->value)
//			add_work(a, &tail, work, ft_rev);
//		else
//			add_work(a, &tail, work, ft_swap);

void	get_work_b(t_ls **b, t_ls **work, int pivot)
{
//	t_ls	*tail;

	if ((*b) -> value == pivot && check_b_fin(*b, work))
			return ;
//	tail = ft_lstlast(*b);
}


//	if ((*b)->value > (*b)->next->value)
//	{
//		if ((*b) -> value == pivot && check_b_fin(*b, work))
//			return ;
//		if ((*b)->value > tail->value && (*b)->next->value < tail->value)
//		{
//			add_work(b, &tail, work, ft_rrev);
//			add_work(b, &tail, work, ft_swap);
//		}
//		add_work(b, &tail, work, ft_rev);
//	}
//	else
//	{
//		if ((*b)->next->value > tail->value)
//			add_work(b, &tail, work, ft_rev);
//		else
//			add_work(b, &tail, work, ft_swap);
//	}

void	do_work(t_ls **work, char *s)
{
	char	*temp;

	temp = 0;
	if ((*work) -> value == 1)
		temp = "s";
	else if ((*work)-> value == 2)
		temp = "r";
	else if ((*work) -> value == 3)
		temp = "rr";
	ft_pop(work);
	printf("%s%s\n", temp, s);
}

void	do_work_both(t_ls **a_work, t_ls **b_work)
{
	char	*temp;

	temp = 0;
	if ((*a_work)-> value == 1)
		temp = "s";
	else if ((*a_work) -> value == 2)
		temp = "r";
	else if ((*a_work) -> value == 3)
		temp = "rr";
	ft_pop(a_work);
	ft_pop(b_work);
	printf("%s%s\n", temp, "s");
}

void	ft_pop(t_ls **head)
{
	t_ls	*temp;

	if (*head == NULL )
		return ;
	temp = *head;
	*head = (*head) -> next;
	temp -> next = NULL;
	free(temp);
}
