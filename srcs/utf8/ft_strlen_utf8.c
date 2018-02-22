#include "utf8.h"

size_t	ft_strlen_utf8(wchar_t *s)
{
	size_t size;

	size = 0;
	while (*s)
	{
		size += ft_charlen_utf8(*s);
		s++;
	}
	return (size);
}

size_t	ft_charlen_utf8(wchar_t wc)
{
	if (wc < 0x80)
		return (1);
	if (wc <= 0x7ff)
		return (2);
	if (wc <= 0xffff)
		return (3);
	if (wc <= 0x1fffff)
		return (4);
	return (0);
}
