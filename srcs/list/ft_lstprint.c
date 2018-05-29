
#include "libft.h"
#include "list.h"

int	deref(int *nb)
{
	return (*nb);
}

int	ft_lstprintnb(t_lst *lst)
{
	int	i;
	int	nb;

	i = 0;
	while (lst)
	{
		nb = deref((int*)lst->data);
		ft_putnbrl(nb);
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_lstprintstr(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		ft_putendl((char *)lst->data);
		lst = lst->next;
		i++;
	}
	return (i);
}
