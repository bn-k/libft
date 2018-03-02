#include "ft_printf.h"

void	materialize(t_total total)
{
		write(1, g_trunk, total.i);
		ft_bzero((void *)g_trunk, total.i);
		total.i = 0;
}

t_total		charcat(char c, t_total *total)
{
	if (total->i == BID)
		materialize(*total);
	g_trunk[total->i] = c;
	total->i++;
	total->quanta++;
	return (*total);
}

void	init_total(t_total *total, const char *format, va_list *ap)
{
	total->quanta = 0;
	total->i = 0;
	total->format = format;
	total->ap = ap;
}


void	body_parser(t_total *total, t_body *body)
{
	ft_bzero(body, sizeof(t_body));
	flags(total, body);
	width_and_precision(total, body);
	modifier(total, body);
}
