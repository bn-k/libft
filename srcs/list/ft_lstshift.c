
#include <stdlib.h>
#include "list.h"

void			ft_lstshift(t_lst **alst, void (*del)(void *data))
{
	t_lst		*lst;
	t_lst		*next;

	lst = *alst;
	if (lst == NULL)
		return ;
	next = lst->next;
	if (del)
		(*del)(lst->data);
	free(lst);
	*alst = next;
}
