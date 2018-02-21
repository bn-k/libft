/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/21 20:18:11 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		put_padding(unsigned long long d, t_mark mk)
{
	int print;
	int i;


	i = 0;
	print = 0;
	while ((!mk.zero || (mk.zero && mk.point))  && (print < rel_sous(mk.width, rel_sous(mk.precis, mk.len) + mk.len) - (mk.neg || mk.plus || mk.space)))
		print += ft_putchar(' ');
	if (mk.plus)
		ft_putchar('+');
	while (mk.precis  && (i < mk.precis - mk.len))
		i += ft_putchar('0');
	while (mk.width && mk.zero && !mk.point && (print < mk.width - mk.len - (mk.neg || mk.space || mk.plus)))
		print += ft_putchar('0');
	if (d == 0 && mk.point && !mk.precis)
		return ((size_t)i + print - 1);
	ft_putnbr_base(d, "01234567");
	return ((size_t)i + print);
}

static size_t		put_spaces(unsigned long long d, t_mark mk)
{
	int	print;

	print= 0;
	if (mk.neg)
		ft_putchar('-');
	print += ft_putnbr_base(d, "01234567");
	while ((print + mk.len < mk.width - mk.neg))
		print += ft_putchar(' ');
	return ((size_t)print);
}

size_t	o_display(unsigned long long d, t_mark mk)
{
	mk.zero = (mk.precis ? 0 : mk.zero);
	mk.len = ft_nbrlen_base(d, 2);
	if (mk.space && mk.neg)
		ft_putchar(' ');
	if (!mk.minus)
		mk.len += put_padding(d, mk);
	else
		mk.len += put_spaces(d, mk);
	return (mk.len + SIGN);
}
