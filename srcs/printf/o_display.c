/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/22 15:56:14 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# define ZERO (((mk.hash && d) || (mk.zero && !mk.width)))

static size_t		put_padding(unsigned long long d, t_mark mk)
{
	int print;
	int i;


	i = 0;
	print = 0;
	while ((!mk.zero || (mk.zero && mk.point))  &&  \
			(print < rel_sous(mk.width, rel_sous(mk.precis, mk.len) + mk.len) - (mk.space || mk.hash)))
		print += ft_putchar(' ');
	if (ZERO)
		ft_putchar('0');
	//printf("\nlmk.len : %d \n" , mk.len);
	while (mk.point  && (i < mk.precis - mk.len - (mk.zero  || mk.hash)))
		i += ft_putchar('0');
	while (mk.width && mk.zero && !mk.point && (i < mk.width - (mk.len) - (d && mk.hash) ))
		i += ft_putchar('0');
	if (d == 0 && mk.point && !mk.precis)
		return ((size_t)i + print - 1);
	ft_putnbr_base(d, "01234567");
	return ((size_t)i + print + ZERO);
}

static size_t		put_spaces(unsigned long long d, t_mark mk)
{
	int	print;

	print = 0;
	ft_putnbr_base(d, "01234567");
	while ((print < mk.width - mk.len))
		print += ft_putchar(' ');
	return ((size_t)print);
}

size_t	o_display(unsigned long long d, t_mark mk)
{
	//mk.zero = (mk.precis ? 0 : mk.zero);
	mk.len = ft_nbrlen_base(d, 8);
	//printf("\nlen : %d\n", mk.len);
	if (mk.space && mk.neg)
		ft_putchar(' ');
	if (!mk.minus)
		mk.len += put_padding(d, mk);
	else
		mk.len += put_spaces(d, mk);
	return (mk.len);
}
