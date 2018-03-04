#include "ft_printf.h"

void	trunk(char *s, t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while (i < body->left)
	{
		charcat(' ', total);
		i++;
	}
	i = 0;
	while (i < body->len)
	{
		charcat(s[i], total);
		i++;
	}
	i = 0;
	while (i < body->right)
	{
		charcat(' ', total);
		i++;
	}
}
