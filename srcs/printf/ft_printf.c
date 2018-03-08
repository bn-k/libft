#include "../includes/ft_printf.h"

char g_trunk[BID];

static const t_on_trunk on_trunk_tab[] = {
	{'%', mod_on_trunk},
	{'s', s_on_trunk},
	{'S', ws_on_trunk},
	{'c', c_on_trunk},
	{'C', wc_on_trunk},
	{'d', d_on_trunk},
	{'i', d_on_trunk},
	{'D', d_on_trunk},
	{'p', x_on_trunk},
	{'u', u_on_trunk},
	{'U', u_on_trunk},
	{'o', o_on_trunk},
	{'x', x_on_trunk},
	{'O', o_on_trunk},
	{'X', x_on_trunk},
	{'0', no_on_trunk},
};

static int body_born(t_total *total)
{
	int	i;
	t_body body;

	total->format++;
	body_parser(total, &body);
	i = 0;
	while (i < 15)
	{
		if (*total->format == on_trunk_tab[i].code)
		{
			total->format++;
			return (on_trunk_tab[i].t_on_trunk(total, &body));
		}
		i++;
	}
	return (on_trunk_tab[15].t_on_trunk(total, &body));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_total total;

	init_total(&total, format, &ap);
	va_start(ap, format);
	while (*total.format)
	{
		if (*total.format == '%')
		{
			if (-1 == body_born(&total))
				return (-1);
		}
		else
		{
			charcat(*total.format, &total);
			total.format++;
		}
	}
	va_end(ap);
	if (total.i != 0)
		write(1, g_trunk, total.i);
	return (total.quanta);
}
