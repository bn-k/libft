/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/19 11:10:36 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		put_padding(int long long d, t_mark mk)
{
	int len;
	int	print;

	print= 0;
	len = ft_nbrlen(d < 0 ? -d : d);
	while ((print + len < mk.width - (d <0)) || (print + len < mk.precis + (d < 0)))
		print += ft_putchar(' ');
	if (d < 0)
		print += ft_putchar('-');
	if (d >= 0 && mk.plus)
		print += ft_putchar('+');
	ft_putnbr_ill((d < 0 ? -d : d));
	return ((size_t)print + len);
}


static size_t		put_zero(int long long d, t_mark mk)
{
	int len;
	int	print;

	print= 0;
	len = ft_nbrlen(d < 0 ? -d : d);
	while (!mk.zero && ((print < mk.width - ((len > mk.precis ? len : mk.precis) + ((d < 0) || mk.plus)))))
				print += ft_putchar(' ');
	if (d < 0)
		print += ft_putchar('-');
	if (d >= 0 && mk.plus)
		print += ft_putchar('+');
	while ((print + len < mk.width) || (print + len < mk.precis + (d < 0)))
		print += ft_putchar('0');
	ft_putnbr_ill((d < 0 ? -d : d));
	return ((size_t)print + len);
}

static size_t		put_spaces(int long long d, t_mark mk)
{
	int len;
	int	print;

	print= 0;
	len = ft_nbrlen(d);
	ft_putnbr_ill(d);
	while ((print + len < mk.width))
		print += ft_putchar(' ');
	return ((size_t)print + len);
}

size_t	d_display(int long long d, t_mark mk)
{
	size_t len = 0;

	if ((mk.space) && d >= 0)
		len += ft_putchar(' ');
	if (!mk.minus)
	{
		if ((-1 < mk.precis) || mk.zero)
			len += put_zero(d, mk);
		else 
			len += put_padding(d, mk);
	}
	else
		len = put_spaces(d, mk);
	return (len);
}
