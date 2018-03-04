#include "ft_printf.h"

static void	trunk_integers_left_distance(t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while (PAD_SPACE && i < body->left)
	{
		charcat(' ', total);
		i++;
	}
}

static void	trunk_integers_left_zero(t_total *total, t_body *body)
{
	int	i;
	i = 0;
	while (PAD_ZERO && i < body->left)
	{
		charcat('0', total);
		i++;
	}

	while (FILL && i < body->fill)
	{
		charcat('0', total);
		i++;
	}
}

static void	trunk_integers_value(char *s, t_total *total, t_body *body)
{
	int	i;

	i = 0;

	if (!(!body->precis && body->point && *s == '0'))
	{
		if (HASH)
			charcat('0', total);
		while (i < body->len)
		{
			charcat(s[i], total);
			i++;
		}
	}
}

static void	trunk_integers_right_distance(t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while (i < body->right)
	{
		charcat(' ', total);
		i++;
	}
}

void	trunk_o(char *s, t_total *total, t_body *body)
{
	trunk_integers_left_distance(total, body);
	trunk_integers_left_zero(total, body);
	trunk_integers_value(s, total, body);
	trunk_integers_right_distance(total, body);
}
