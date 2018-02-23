/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/22 19:24:56 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		put_padding(unsigned long long d, t_mark mk, char *base)
{
	int print;
	int i;


	i = 0;
	print = 0;
	while ((!mk.zero || (mk.zero && mk.point))  && (print < rel_sous(mk.width, rel_sous(mk.precis, mk.len) + mk.len) -  mk.space -  mk.hash))
		print += ft_putchar(' ');
	if (mk.hash && d)
		ft_putstr(base[10] == 'A' ? "0X" : "0x");
	while (mk.precis  && (i < mk.precis - mk.len))
		i += ft_putchar('0');
	while (mk.width && mk.zero && !mk.point && (print < mk.width - (mk.len + (d ? mk.hash :0))))
		print += ft_putchar('0');
	if (d == 0 && mk.point && !mk.precis)
		return ((size_t)i + print - 1);
	ft_putnbr_base(d,base);
	return ((size_t)i + print);
}

static size_t		put_spaces(unsigned long long d, t_mark mk, char *base)
{
	int	print;
	int	i;

	print = 0;
	i = 0;
	while (mk.point  && (i < mk.precis - mk.len))
		i += ft_putchar('0');
	ft_putnbr_base(d, base);
	while ((print < mk.width - mk.len - i))
		print += ft_putchar(' ');
	return ((size_t)print + i);

}

size_t	x_display(unsigned long long d, t_mark mk, char *base)
{
	mk.zero = (mk.precis ? 0 : mk.zero);
	mk.len = ft_nbrlen_base(d, 16);
	if (!mk.minus)
		mk.len += put_padding(d, mk, base);
	else
		mk.len += put_spaces(d, mk, base);
	return (mk.len +  (d ? mk.hash: 0));
}
