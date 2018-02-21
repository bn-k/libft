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

static size_t		put_padding(unsigned long long d, t_mark mk)
{
	int print;
	int i;

	i = 0;
	print = 0;
	while (!mk.zero && (print < rel_sous(mk.width, rel_sous(mk.precis, mk.len) + mk.len) - ( mk.plus || mk.space)))
		print += ft_putchar(' ');
	if (mk.plus)
		ft_putchar('+');
	while (mk.precis  && (i < mk.precis - mk.len))
		i += ft_putchar('0');
	while (mk.width && mk.zero && !mk.precis && (print < mk.width - mk.len - mk.space))
		print += ft_putchar('0');
	if (d == 0 && mk.point && !mk.precis)
		return ((size_t)i + print - 1);
	ft_putnbr_iull(d);
	return ((size_t)i + print);
}

static size_t		put_spaces(unsigned long long d, t_mark mk)
{
	int	print;
	int	i;

	print= 0;
	i = 0;
	while (mk.precis  && (i < mk.precis - mk.len))
		i += ft_putchar('0');
	ft_putnbr_iull(d);
	while ((i + print + mk.len < mk.width ))
		print += ft_putchar(' ');
	return ((size_t)print + i);
}

size_t	u_display(unsigned long long d, t_mark mk)
{
	mk.len = ft_nbrlen_iull(d);
	mk.zero = (mk.precis ? 0 : mk.zero);
	if (mk.space)
		ft_putchar(' ');
	if (!mk.minus)
		mk.len += put_padding(d, mk);
	else
		mk.len += put_spaces(d, mk);
	return (mk.len + SIGN);
}
