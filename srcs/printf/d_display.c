/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/15 16:44:25 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		put_padding(int long long d, t_mark mk)
{
	int i;
	int len;

	i = 0;
	len = ft_nbrlen((d < 0 ? -d : d));

	if (d < 0 && mk.zero)
		len += ft_putchar('-');
	while (i < (mk.width + mk.precis) - len)
	{
		ft_putchar(((mk.zero || mk.precis) ? '0' : ' '));
		i++;
	}
	if (d < 0 && !mk.zero)
		len += ft_putchar('-');
	if (d >= 0 && mk.plus)
		len += ft_putchar('+');
	ft_putnbr_ill((d < 0 ? -d : d));
	return ((size_t)i + len);
}

static size_t		put_spaces(int long long d, t_mark mk)
{
	int i;
	int len;

	(void)mk;
	i = 0;
	len = ft_nbrlen(d);
	ft_putnbr_ill(d);
	while (i < mk.width - len - mk.plus)
	{
		len += ft_putchar(' ');
		i++;
	}
	return ((size_t)len);
}


size_t	d_display(int long long d, t_mark mk)
{
	size_t len = 0;

	if ((mk.space) && d >= 0)
		len += ft_putchar(' ');
	if (!mk.minus)
		len += put_padding(d, mk);
	else
		len = put_spaces(d, mk);
	return (len);
}
