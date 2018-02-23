/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/22 23:10:29 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static size_t		put_padding(unsigned long long d, t_mark mk, char *base)
{
	int print;
	int i;


	i = 0;
	print = 0;
	while ((!mk.zero || (mk.zero && mk.point))  && (print < rel_sous(mk.width, rel_sous(mk.precis, mk.len) + mk.len) -  mk.space - 2))
		print += ft_putchar(' ');
	ft_putstr(base[10] == 'A' ? "0X" : "0x");
	while (mk.precis  && (i < mk.precis - mk.len ))
		i += ft_putchar('0');
	while (mk.width && mk.zero && !mk.point && (print < mk.width - mk.len - 2))
		print += ft_putchar('0');
	if (d == 0 && mk.point && !mk.precis)
		return ((size_t)i + print - 1);
	ft_putnbr_base(d,base);
	return ((size_t)i + print + 2);
}

static size_t		put_spaces(unsigned long long d, t_mark mk, char *base)
{
	int	print;

	print = 0;
	ft_putstr(base[10] == 'A' ? "0X" : "0x");
	ft_putnbr_base(d, base);
	while ((print < mk.width - mk.len - 2))
		print += ft_putchar(' ');
	return ((size_t)print + 2);
}

size_t	p_display(unsigned long long d, t_mark mk, char *base)
{
	mk.zero = (mk.precis ? 0 : mk.zero);
	mk.len = ft_nbrlen_base(d, 16);
	if (mk.space && mk.neg)
		ft_putchar(' ');
	if (!mk.minus || mk.point)
		mk.len += put_padding(d, mk, base);
	else
		mk.len += put_spaces(d, mk, base);
	return (mk.len + (d ? mk.hash : 0));
}


size_t	p_spec(va_list ap, const char *format, t_mark mk)
{
	long unsigned int d;
	(void)format;
	(void)mk;

	d = va_arg(ap, long unsigned int);
	return (p_display(d, mk, "0123456789abcdef"));
}
