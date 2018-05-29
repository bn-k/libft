#include <stdlib.h>
#include "list.h"

t_lst			*ft_lstnew(void *data)
{
	t_lst		*node;

	if (!(node = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
