#include "ft_printf.h"

static int	ismod(int c)
{
	int		i;
	char	mod [6] = "hljzq"; 

	i = -1;
	while (++i < 5)
		if (mod[i] == c)
			return (i + 1);
	return (0);
}

void	modifier(const char **format, t_mark *mk )
{
	int	i;
	
	i = 0;

	while ((i = ismod(**format)))
	{
		mk->h= (i == 1 ? 1 + mk->h : mk->h);
		mk->l= (i == 2 ? 1 + mk->l : mk->l);
		mk->j= (i == 3 ? 1 : mk->j);
		mk->z= (i == 4 ? 1 : mk->z);
		mk->q= (i == 5 ? 1 : mk->q);
		(*format)++;
	}
}

