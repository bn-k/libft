/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/20 17:09:29 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# define PRECIS (mk.zero ? mk.width : mk.precis )
# define PAD (mk.zero ? 0 : POS(mk.width - (d < 0)))
# define SIGN (((mk.plus || mk.space) && (d >= 0)) || (d < 0))

static int			rel_sous(int i, int d)
{
	if (i - d >= 0)
		return (i - d);
	else
		return (0);
}

static size_t		put_padding(int long long d, t_mark mk)
{
	int print;
	int i;

	i = 0;
	print = 0;
	while (!mk.zero && (print < rel_sous(mk.width, rel_sous(mk.precis, mk.len) + mk.len) - ((d < 0) || mk.plus || mk.space)))
		print += ft_putchar(' ');
	if (d < 0)
		ft_putchar('-');
	else if (mk.plus)
		ft_putchar('+');
	while (mk.precis  && (i < mk.precis - mk.len))
		i += ft_putchar('0');
	while (mk.width && mk.zero && !mk.precis && (print < mk.width - mk.len - ((d < 0) || mk.space)))
		print += ft_putchar('0');
	if (!(d == 0 && mk.point && !mk.precis))
	ft_putnbr_ill((d < 0 ? -d : d));
	return ((size_t)i + print);
}

static size_t		put_spaces(int long long d, t_mark mk)
{
	int	print;

	print= 0;
	ft_putnbr_ill(d);
	while ((print + mk.len < mk.width - (d <0)))
		print += ft_putchar(' ');
	return ((size_t)print + (d < 0));
}

size_t	d_display(int long long d, t_mark mk)
{
	mk.zero = (mk.precis ? 0 : mk.zero);
	mk.len = ft_nbrlen(d < 0 ? -d : d);
	if (mk.space && d >= 0)
		ft_putchar(' ');
	if (!mk.minus)
		mk.len += put_padding(d, mk);
	else
		mk.len += put_spaces(d, mk);
	return (mk.len + SIGN);
}
