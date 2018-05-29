
#include <stddef.h>
#include "list.h"

void			ft_lstaddafter(t_lst *lst, t_lst *node)
{
	if (lst == NULL)
		return ;
	node->next = lst->next;
	lst->next = node;
}
