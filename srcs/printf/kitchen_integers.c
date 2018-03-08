#include "ft_printf.h"

void	trunk_integers_left_distance(t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while ((!body->zero || body->point) && i < body->left)
	{
		charcat(' ', total);
		i++;
	}
	if (body->minus)
		charcat('-', total);
	else if (body->plus)
		charcat('+', total);
	else if (body->space)
		charcat(' ', total);
}

void	trunk_integers_left_zero(t_total *total, t_body *body)
{
	int	i;
	i = 0;
	while (!body->dash && !body->point && body->zero && i < body->left)
	{
		charcat('0', total);
		i++;
	}
	while (i < body->fill)
	{
		charcat('0', total);
		i++;
	}
}

void	trunk_integers_value(char *s, t_total *total, t_body *body)
{
	int	i;

	i = 0;

	if (!(!body->precis && body->point && *s == '0'))
	{
		while (i < body->len)
		{
		//printf("len %d \n", total->quanta);
			charcat(s[i], total);
			i++;
		}
	}
}

void	trunk_integers_right_distance(t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while (i < body->right)
	{
		charcat(' ', total);
		i++;
	}
}

void	trunk_integers(char *s, t_total *total, t_body *body)
{
	trunk_integers_left_distance(total, body);
	trunk_integers_left_zero(total, body);
	trunk_integers_value(s, total, body);
	trunk_integers_right_distance(total, body);
}
