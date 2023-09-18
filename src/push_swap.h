#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct		s_ls
{
	int			value;
	int			order;
	int			gas;
	struct s_ls	*next;
}					t_ls;

///for test
char	*ft_itoa(int n);

///for test

long	ft_atol(const char *str);
void	sorting(t_ls **a, t_ls **b);
void	get_order(t_ls *head);
void	ft_lstadd_back(t_ls **lst, t_ls *new);
t_ls	*ft_lstnew(int value);
t_ls	*ft_lstlast(t_ls *lst);

void case_five(t_ls **a_head);
void ccase_1(t_ls **a_head, t_ls **b_head, t_ls **b_tail);
void	ccase_1_push(t_ls **a_head, t_ls **b_head);
void ccase_1_piv(t_ls **a_head, t_ls **b_head);
void ccase_2(t_ls **a, t_ls **b);
void ccase_2_push(t_ls **a, t_ls **b);
void ccase_3(t_ls **a_head, t_ls **b_head);
void	ccase_3_extend_else(t_ls **a_head, t_ls **b_head, t_ls **a_tail);
void	p_back(t_ls **b_head, t_ls **a_head);

int	check_ascen(t_ls **head);
int ft_atoi_callback(t_ls **h, const char *s, void (*fn)(t_ls **, int));

void	ft_free_list(t_ls **lst);
int ft_free_all(t_ls **f, char **s, int i, int is_error);
void ft_mainout(t_ls **a_l, t_ls **b_l, int num, void (*fn)(t_ls **, t_ls **));
int b_swap(t_ls **head, int incre);
int	 swap_incre(t_ls **head);
int	swap_decre(t_ls **head);
void	ft_si_out(t_ls **f, t_ls **t, char c, void (*fn)(t_ls **, t_ls **));
char	**ft_split(char const *s, char c);
void full_sort(t_ls **a_head, t_ls **b_head, int a_pivot, int b_pivot);
void	full_sort_dowork(t_ls **a_work, t_ls **b_work, int fin);
void	full_sort_fin(t_ls **head, t_ls **work, int pivot, char *s);
int	check_fin(t_ls *a_work, t_ls *b_work, int fin);
int get_len(t_ls *a_head, t_ls *b_head);
int get_input(t_ls **head, char *str);
int check_chr(const char *s);
int	check_a_fin(t_ls *a, t_ls **work);
int	check_b_fin(t_ls *b,t_ls **work);
void	add_work(t_ls **h, t_ls **tail, t_ls **work, void (*f)(t_ls **, t_ls **));
void	get_work_a(t_ls **a, t_ls **work, int a_pivot);
void	get_work_b(t_ls **b, t_ls **work, int pivot);
void	do_work(t_ls **work, char *s);
void	do_work_both(t_ls **a_work, t_ls **b_work);
void	ft_pop(t_ls **head);
void ft_new_addback_int(t_ls **head, int value);
t_ls	*ft_lstdup(t_ls *src);
int lowlen_case(t_ls **head, int nth_case, int is_free);
void case_two(t_ls **head);
void case_three(t_ls **head);
void case_four(t_ls **ls);
void	init_push_case_4(t_ls **src ,t_ls **dst, int pivot);
int eq_pivot(t_ls *head, int pivot);
int small_select(t_ls *head);
int lst_len(t_ls *head);
int	quick_select_n(t_ls *head, int n);
void manda_sort(t_ls **head, int a_pivot, t_ls **to_free);
t_ls	*init_sort(t_ls **a_head, int b_pivot);
void	init_sort_swap(t_ls **a, t_ls **a_tail, t_ls **b, t_ls **b_tail);
void	init_sort_rev(t_ls **a, t_ls **a_tail, t_ls **b, t_ls **b_tail);
void	ft_swap(t_ls **head, t_ls **tail);
void ft_rev(t_ls **head, t_ls **tail);
void ft_rrev(t_ls **head, t_ls **tail);
void	ft_push(t_ls **src, t_ls **dst, t_ls **dst_tail);
int unvalid_in(t_ls *head);
#endif
