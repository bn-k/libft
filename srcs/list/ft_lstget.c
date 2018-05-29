
#include <stddef.h>
#include "list.h"

t_lst			*ft_lstget(t_lst *lst, t_bool (*f)(t_lst *node, void *data),
					void *data)
{
	while (lst != NULL)
	{
		if ((*f)(lst, data))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
