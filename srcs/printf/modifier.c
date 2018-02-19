#include "ft_printf.h"

const t_mod mod_tab [] = {

	{'h', 0, "h"}, 
	{'l', 0, "l"}
};

void	modifier(const char **format, t_mark *mk)
{
	int i;

	(void)mk;
	i = 0;
	while (i < 2)
	{
		printf("modifier --> %c\n", **format);
		if (*(format)[0] == mod_tab[i].mod)
		{
			(*format)++;
		}
		i++;
	}
}
