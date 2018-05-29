
#include <stddef.h>
#include "list.h"

t_lst			*ft_lstpushiter(t_lst **begin, t_lst **iterator, void *data)
{
	t_lst		*node;

	if (!(node = ft_lstnew(data)))
		return (NULL);
	if (*begin == NULL)
		*begin = node;
	else
		(*iterator)->next = node;
	*iterator = node;
	return (node);
}
