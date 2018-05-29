
#include <stdlib.h>
#include "list.h"

t_lst			*ft_lstnew__(size_t size)
{
	t_lst		*node;

	if (!(node = (t_lst *)malloc(size)))
		return (NULL);
	node->next = NULL;
	return (node);
}
