#include "../includes/ft_printf.h"

t_mark	extend(va_list ap, const char **format, t_mark mk)
{
	mk.slice = (char *)malloc(sizeof(char) * SLICE_SIZE + 1);
	ft_bzero(mk.slice, SLICE_SIZE);
	mk.slice_len = 0;
	while (mk.slice_len < SLICE_SIZE && **format)
	{
		if (**format == '%')
			return (new_format(ap, format, mk));
		mk.slice[mk.slice_len] = **format;
		mk.slice_len++;
		mk.slice[mk.slice_len] = 0;
		(*format)++;
	}
	return (mk);
}


int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_mark	ret;
	int	size;
	int	i = 0;

	size = 0;
	va_start(ap, format);
	while (*format)
	{
		ret = extend(ap, &format, ret);
		size += ret.slice_len;
		ft_putstr(ret.slice);
		free(ret.slice);
		i++;
	}
	va_end(ap);
	return (size);
}
