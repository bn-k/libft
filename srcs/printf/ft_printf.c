#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	char	c;
	char	trunk[TRUNK_SIZE];
	int	quanta;
	va_list	ap;
	t_total ret;

	va_start(ap, format);
	c = va_arg(ap, int);
	va_end(ap);
	return (quanta);
}
