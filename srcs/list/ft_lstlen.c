
#include <stddef.h>
#include "list.h"

int				ft_lstlen(t_lst *lst)
{
	int			len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
