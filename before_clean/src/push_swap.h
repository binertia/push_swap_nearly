#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

typedef struct node
{
	int			value;
	int			index;
	struct node	*next;
}				t_ls;

char	*ft_itoa(int n);

void	sort(t_ls **head);
int	get_error(t_ls **n, int i);

int small_select(t_ls *head);
int eq_pivot(t_ls *head, int pivot);

void	add_index(t_ls *n);
void	case_four(t_ls **ls);
void case_five(t_ls **a_head);
void p_back(t_ls **b_head, t_ls **a_head);
int	check_chr(char *str);
int	check_dup(t_ls *n);
int	ft_atoi_cb(t_ls **n, char *s, int (*fn)(t_ls **, int));

int	free_str(char **s, int end_line);
int	free_list(t_ls **n);
int	free_all(t_ls **head, t_ls **other, char **s, int num);

int	ft_lstlen(t_ls *n);
t_ls	*ft_lstlast(t_ls *n);
int	ft_lstnew_addback(t_ls **n, int num);
int	get_list(t_ls **n, char *str);
void ft_mainout(t_ls **a_l, t_ls **b_l, int num, void (*fn)(t_ls **));
char	**ft_split(char const *s, char c);
int lowlen_case(t_ls **head, int nth_case);

void	ft_single_out(t_ls **n, char c, void (*f)(t_ls **));
void	ft_push(t_ls **s, t_ls **d, char c);
void	ft_swap(t_ls **head);
void	ft_rev(t_ls **head);
void	ft_rrev(t_ls **head);

int	is_ascen(t_ls *n);
void	radix(t_ls **n, t_ls **s);
#endif
