
#include <stdlib.h>
#include "list.h"

void			ft_lstdel(t_lst **alst, void (*del)(void *data))
{
	t_lst		*lst;
	t_lst		*next;

	lst = *alst;
	while (lst != NULL)
	{
		next = lst->next;
		if (del)
			(*del)(lst->data);
		free(lst);
		lst = next;
	}
	*alst = NULL;
}
