
#include "list.h"

void			ft_lstaddfront(t_lst **alst, t_lst *node)
{
	node->next = *alst;
	*alst = node;
}
