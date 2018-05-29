
#include <stddef.h>
#include "list.h"
#include "libft.h"


void			ft_lstaddback(t_lst **alst, t_lst *node)
{
	t_lst		*lst;

	lst = *alst;
	if (lst == NULL)
		*alst = node;
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = node;
	}
}
