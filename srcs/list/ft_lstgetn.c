
#include <stddef.h>
#include "list.h"

t_lst			*ft_lstgetn(t_lst *lst, int index)
{
	while (lst != NULL && index > 0)
	{
		lst = lst->next;
		index--;
	}
	return (lst);
}
