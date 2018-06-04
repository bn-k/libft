#include "list.h"
#include <stdio.h>

t_lst		*ft_lstlast(t_lst *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
