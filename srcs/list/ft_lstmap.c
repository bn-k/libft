
#include <stddef.h>
#include "list.h"

t_lst			*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *node))
{
	t_lst		*new;
	t_lst		*iter;

	new = NULL;
	iter = NULL;
	while (lst != NULL)
	{
		ft_lstadditer(&new, &iter, (*f)(lst));
		lst = lst->next;
	}
	return (new);
}
