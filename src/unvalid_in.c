#include "push_swap.h"
// int will be different || exit();

int unvalid_in(t_ls *head)
{
	t_ls *temp;

		printf("check unvalid");
	if (!head)
	{
		return (1);
	}
	while (head)
	{
		while (temp)
		{
			if (head->value == temp->value)
				return (1);
			temp = temp->next;
		}
		head = head->next;
		temp = head->next;
		printf("check unvalid");
	}
	printf("check unvalid");
	return (0);
}
