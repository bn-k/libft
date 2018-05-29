#include <stddef.h>
#include "list.h"

void			ft_lstadditer(t_lst **begin, t_lst **iterator, t_lst *node)
{
	if (*begin == NULL)
		*begin = node;
	else
		(*iterator)->next = node;
	*iterator = node;
}
