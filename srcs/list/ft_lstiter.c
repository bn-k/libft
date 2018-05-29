
#include <stddef.h>
#include "list.h"

void			ft_lstiter(t_lst *lst, void (*f)(t_lst *node))
{
	while (lst != NULL)
	{
		(*f)(lst);
		lst = lst->next;
	}
}
