/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/23 14:20:19 by abbenham         ###   ########.fr       */
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
			(print < rel_sous(mk.width, rel_sous(mk.precis, mk.len) + mk.len) - ZERO))
		print += ft_putchar(' ');
	if (ZERO)
		ft_putchar('0');
	//printf("\nlmk.len : %d \n" , mk.len);
	while (mk.point  && (i < mk.precis - mk.len - ZERO))
		i += ft_putchar('0');
	while (mk.width && mk.zero && !mk.point && (i < mk.width - (mk.len) - ZERO))
		i += ft_putchar('0');
	if (!(mk.point && !mk.precis && !d && !mk.hash))
	{
		ft_putnbr_base(d, "01234567");
		return ((size_t)i + print + ZERO);
	}
	return ((size_t)i + print + ZERO - mk.len);
}

static size_t		put_spaces(unsigned long long d, t_mark mk)
{
	int	print;
	int	i;

	print = 0;
	i = 0;
	if (ZERO)
		ft_putchar('0');
	while (mk.point  && (i < mk.precis - mk.len - ZERO))
		i += ft_putchar('0');
	ft_putnbr_base(d, "01234567");
	while ((print < mk.width - mk.len - ZERO - i))
		print += ft_putchar(' ');
	return ((size_t)print + ZERO + i);
}

size_t	o_display(unsigned long long d, t_mark mk)
{
	//mk.zero = (mk.precis ? 0 : mk.zero);


	mk.len = ft_nbrlen_base(d, 8);
	//printf("\nlen : %d\n", mk.len);
	if (!mk.minus)
		mk.len += put_padding(d, mk);
	else
		mk.len += put_spaces(d, mk);

	return (mk.len);
}
