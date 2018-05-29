
#include <stddef.h>
#include "list.h"

t_lst			*ft_lstpushback__(size_t size, t_lst **alst)
{
	t_lst		*node;

	if (!(node = ft_lstnew__(size)))
		return (NULL);
	ft_lstaddback(alst, node);
	return (node);
}
