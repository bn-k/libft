#include "ft_printf.h"

t_total 	c_on_trunk(t_total *total, t_body *body)
{
	char c;
	(void)body;

	c = va_arg(*total->ap, int);
	charcat(c, total);
	return (*total);
}

t_total 	s_on_trunk(t_total *total, t_body *body)
{
	(void)body;
	return (*total);
}

t_total 	p_on_trunk(t_total *total, t_body *body)
{
	(void)body;
	return (*total);
}

t_total		no_on_trunk(t_total *total, t_body *body)
{
	(void)body;
	return (*total);
}

t_total		mod_on_trunk(t_total *total, t_body *body)
{
	(void)body;
	return (*total);
}
