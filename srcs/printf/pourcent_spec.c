/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/22 12:11:34 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static size_t		put_padding(t_mark mk)
{
	int print;
	int i;


	i = 0;
	print = 0;
	while ((!mk.zero || (mk.zero && mk.point))  && (print < rel_sous(mk.width, rel_sous(mk.precis, mk.len) + mk.len) - mk.space  ))
		print += ft_putchar(' ');
	if (mk.hash && !mk.width)
		ft_putchar('0');
	while (mk.precis  && (i < mk.precis - mk.len - mk.hash))
		i += ft_putchar('0');
	while (mk.width && mk.zero && !mk.point && (print < mk.width - mk.len))
		print += ft_putchar('0');
	ft_putchar('%');
	if (mk.point && !mk.precis)
		return ((size_t)i + print - 1);
	return ((size_t)i + print);
}

static size_t		put_spaces(t_mark mk)
{
	int	print;

	ft_putchar('%');
	print = 0;
	while ((print < mk.width - mk.len))
		print += ft_putchar(' ');
	return ((size_t)print);
}

size_t	pourcent_display(t_mark mk)
{
	mk.len = 1;
	mk.zero = (mk.precis ? 0 : mk.zero);
	if (mk.space && mk.neg)
		ft_putchar(' ');
	if (!mk.minus)
		mk.len += put_padding(mk);
	else
		mk.len += put_spaces(mk);
	return (mk.len);
}


size_t 	pourcent_spec(va_list ap, const char *format, t_mark mk)
{
	(void)ap;
	(void)format;
	return (pourcent_display(mk));
}
