
#include <stddef.h>
#include "list.h"

t_lst			*ft_lstdup(t_lst *lst)
{
	t_lst		*cpy;
	t_lst		*iter;

	cpy = NULL;
	iter = NULL;
	while (lst != NULL)
	{
		if (!(ft_lstpushiter(&cpy, &iter, lst->data)))
			return (NULL);
		lst = lst->next;
	}
	return (cpy);
}
