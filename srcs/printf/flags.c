#include "ft_printf.h"
static int	isflag(int c)
{
	int	i;
	char	flag [7] = "#0- +'"; 

	i = -1;
	while (++i < 6)
		if (flag[i] == c)
			return (i + 1);
	return (0);
}

void	flags(const char **format, t_mark *mk)
{
	int	i;
	
	i = 0;
	while ((i = isflag(**format)))
	{
		mk->hash= (i == 1 ? 1 : mk->hash);
		mk->zero= (i == 2 ? 1 : mk->zero);
		mk->minus = (i == 3 ? 1 : mk->minus);
		mk->space = (i == 4 ? 1 : mk->space);
		mk->plus= (i == 5 ? 1 : mk->plus);
		mk->apos= (i == 6 ? 1 : mk->apos);
		(*format)++;
	}
}

