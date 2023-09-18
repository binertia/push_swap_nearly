#include "push_swap.h"

/*static void quick_sort_ref(t_ls **head)
{
    *head = quick_sort(*head, ft_lstlast(*head));
} */

t_ls	*getLastNode(t_ls* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

t_ls* partition(t_ls* head, t_ls* end, t_ls** newHead, t_ls** newEnd) {
    t_ls* pivot = end;
    t_ls* prev = NULL;
    t_ls* current = head;
    t_ls* tail = pivot;

    while (current != pivot) {
        if (current-> value < pivot->value) {
            if (*newHead == NULL) {
                *newHead = current;
            }
            prev = current;
            current = current->next;
        } else {
            if (prev) {
                prev->next = current->next;
            }
            t_ls* temp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if (*newHead == NULL) {
        *newHead = pivot;
    }

    *newEnd = tail;

    return pivot;
}

t_ls* quickSortRec(t_ls* head, t_ls* end) {
    if (head == NULL || head == end) {
        return head;
    }

    t_ls* newHead = NULL;
    t_ls* newEnd = NULL;

    t_ls* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        t_ls* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = NULL;
        newHead = quickSortRec(newHead, temp);
        temp = ft_lstlast(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRec(pivot->next, newEnd);

    if (newHead == NULL) {
        return pivot;
    }

    return newHead;
}

void quick_sort(t_ls** headRef) {
    *headRef = quickSortRec(*headRef, ft_lstlast(*headRef));
}

void	get_order(t_ls *head)
{
	t_ls	*current;
	t_ls	*temp;
	int		i;

	temp = ft_lstdup(head);
	quick_sort(&temp);
	while (head)
	{
		current = temp;
		i = 1;
		while (current)
		{
			if (current -> value == head -> value)
			{
				head -> order = i;
				break;
			}
			i++;
			current = current -> next;
		}
		head = head -> next;
	}
}

/*
static void	parti_if(t_ls **n_head, t_ls **current, t_ls **prev)
{
            if (*n_head == NULL)
                *n_head= *current;
            *prev = *current;
            *current = (*current) -> next;
}

static void	parti_else(t_ls **temp, t_ls **current, t_ls **tail, t_ls **prev)
{
            if (*prev)
                (*prev)->next = (*current)->next;
            *temp = (*current) -> next;
            (*current)->next = NULL;
            (*tail)->next = *current;
            *tail = *current;
            *current = *temp;
}

static t_ls *parti(t_ls *head, t_ls *end, t_ls **n_head, t_ls** n_end)
{
    t_ls	*pivot;
    t_ls	*prev;
    t_ls	*current;
    t_ls	*tail;
	t_ls	*temp;

	pivot = end;
	prev = NULL;
	current = head;
	tail = pivot;
    while (current != pivot) {
        if (current->value < pivot->value)
			parti_if(n_head, &current, &prev);
		else
			parti_else(&temp, &current, &tail, &prev);
    }
    if (*n_head == NULL)
        *n_head = pivot;
	if (*n_end != NULL)
        *n_end = tail;

    return pivot;
}

static t_ls	*quick_sort(t_ls *head, t_ls *end)
{
    t_ls	*n_head;
    t_ls	*n_end;
    t_ls	*pivot;
	t_ls	*temp;

    n_head = NULL;
    n_end = NULL;
	pivot = parti(head, end, &n_head, &n_end);

    if (head == NULL || head == end)
        return (head);
    if (n_head != pivot) {
        temp = n_head;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;
        n_head = quick_sort(n_head, temp);
        temp = n_head;
		while (temp -> next)
			temp = temp -> next;
        temp->next = pivot;
    }
    pivot->next = quick_sort(pivot->next, n_end);
    if (n_head == NULL)
        return pivot;
    return (n_head);
} */
