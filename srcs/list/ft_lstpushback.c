
#include <stddef.h>
#include "list.h"
#include "libft.h"

t_lst			*ft_lstpushback(t_lst **alst, void *data)
{
	t_lst		*node;

	if (!*alst)
	{
		*alst = ft_lstnew(data);
		return (*alst);
	}
	if (!(node = ft_lstnew(data)))
		return (NULL);
	ft_lstaddback(alst, node);
	return (node);
}
