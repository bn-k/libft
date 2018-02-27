
#include "ft_printf.h"

static void	padding_len(t_mark *mk)
{
	mk->pad = mk->width - mk->len;
}

static void	string_len(wchar_t *s, t_mark *mk)
{
	mk->len = ft_strlen_utf8(s);
	if (mk->point)
		mk->len = (mk->precis < mk->len ? mk->precis : mk->len);
}

void	math_utf8(wchar_t *s, t_mark *mk)
{
	string_len(s, mk);
	padding_len(mk);
//	printf("len %d\n", mk->len);
}
