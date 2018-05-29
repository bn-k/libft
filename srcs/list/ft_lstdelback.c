#include <stdlib.h>
#include "list.h"

void			ft_lstdelback(t_lst **alst, void (*del)(void *data))
{
	t_lst		*node;

	if ((node = ft_lstremback(alst)))
	{
		if (del)
			(*del)(node->data);
		free(node);
	}
}
