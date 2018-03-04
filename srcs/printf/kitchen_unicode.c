#include "ft_printf.h"

static void	trunk_unicode_left_distance(t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while (i < body->left)
	{
		charcat(' ', total);
		i++;
	}
}

static void	trunk_unicode_left_zero(t_total *total, t_body *body)
{
	(void)body;
	(void)total;
}

static void	trunk_unicode_value(wchar_t *ws, t_total *total, t_body *body)
{
	(void)body;
	(void)total;
	(void)ws;
	int	s_i;
	int	ws_i;
	char s[body->len];

	ws_i = 0;
	s_i = 0;
	while (s_i < body->len)
	{
		s_i += conv_utf8(&s[s_i], ws[ws_i], 4);
		ws_i++;
	}
	s_i = 0;
	while (s_i < body->len)
	{
		charcat(s[s_i], total);
		s_i++;
	}
}

static void	trunk_unicode_right_distance(t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while (i < body->right)
	{
		charcat(' ', total);
		i++;
	}
}

void	trunk_unicode(wchar_t *ws, t_total *total, t_body *body)
{
	trunk_unicode_left_distance(total, body);
	trunk_unicode_left_zero(total, body);
	trunk_unicode_value(ws, total, body);
	trunk_unicode_right_distance(total, body);
}
