
#include <stddef.h>
#include "list.h"

t_lst			*ft_lstpushafter(t_lst *lst, void *data)
{
	t_lst		*node;

	if (lst == NULL || !(node = ft_lstnew(data)))
		return (NULL);
	node->next = lst->next;
	lst->next = node;
	return (node);
}
