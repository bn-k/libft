
#include "ft_printf.h"

static void	padding_len(t_mark *mk)
{
	mk->pad = POS(mk->width - mk->len);
}

static void	precision_len(int long long i, t_mark *mk)
{
	mk->len = ft_nbrlen_base(i, 8);
	if (mk->point)
		mk->fill = (mk->precis < mk->len ? 0 : mk->precis - mk->len);
}

void	o_math(unsigned long long i, t_mark *mk)
{
	precision_len(i, mk);
	padding_len(mk);
}
