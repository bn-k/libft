#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int	count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += new_format(ap, &format);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
