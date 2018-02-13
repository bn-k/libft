#include "utf8.h"

void	ft_putstr_utf8(wchar_t *ws)
{
	if (ws)
		while (*ws)
		{
			ft_putchar_utf8(*ws);
			ws++;
		}
}
