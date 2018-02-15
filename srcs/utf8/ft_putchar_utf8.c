#include "utf8.h"

static size_t	two_byte_utf8(wchar_t wc)
{
	ft_putchar((wc >> 6) | M_110XXXXX);
	ft_putchar((wc & SIX_BYTE) + M_10XXXXXX);
	return (2);
}

static size_t	three_byte_utf8(wchar_t wc)
{
	ft_putchar((wc >> 12) | M_1110XXXX);
	ft_putchar(((wc >> 6) & SIX_BYTE) | M_10XXXXXX);
	ft_putchar((wc & SIX_BYTE) + M_10XXXXXX);
	return (3);
}

static size_t	four_byte_utf8(wchar_t wc)
{
	ft_putchar((wc >> 18) | M_1110XXXX);
	ft_putchar(((wc >> 12) & SIX_BYTE) | M_10XXXXXX);
	ft_putchar(((wc >> 6) & SIX_BYTE) | M_10XXXXXX);
	ft_putchar((wc & SIX_BYTE) + M_10XXXXXX);
	return (4);
}

size_t	ft_putchar_utf8(wchar_t wc)
{
	if (wc < 0x80)
	{
		ft_putchar(wc);
		return (1);
	}
	if (wc <= 0x7ff)
		return (two_byte_utf8(wc));
	if (wc <= 0xffff)
		return (three_byte_utf8(wc));
	if (wc <= 0x1fffff)
		return (four_byte_utf8(wc));
	return (0);
}
