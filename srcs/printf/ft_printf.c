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
		{
			if (*format == '%' && !format[1])
				return (count);
			if (-1 == (count += new_format(ap, &format)))
				return (-1);
		}
			else
				count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
