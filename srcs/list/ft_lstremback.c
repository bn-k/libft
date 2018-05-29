
#include <stddef.h>
#include "list.h"

t_lst			*ft_lstremback(t_lst **alst)
{
	t_lst		*node;
	t_lst		*prev;

	if ((prev = *alst) == NULL)
		return (NULL);
	if ((node = prev->next) == NULL)
	{
		*alst = NULL;
		return (prev);
	}
	while (node->next != NULL)
	{
		prev = node;
		node = node->next;
	}
	prev->next = NULL;
	return (node);
}
