
#include <stddef.h>
#include "list.h"

t_lst			*ft_lstpushfront(t_lst **alst, void *data)
{
	t_lst		*node;

	if (!(node = ft_lstnew(data)))
		return (NULL);
	ft_lstaddfront(alst, node);
	return (node);
}
