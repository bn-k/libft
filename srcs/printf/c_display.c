/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/22 11:03:07 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utf8.h"

static size_t		put_spaces(t_mark mk)
{
	int i;

	i = 0;
	while (i < (mk.width -  (mk.point ?    ( mk.precis > mk.len ? mk.len : mk.precis ): mk.len   )    ))
		i += ft_putchar(' ');
	return ((size_t)i);
}

static size_t		put_padding(int len)
{
	int i;

	i = 0;
	if (len <= 0)
		return (0);
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	return ((size_t)len);
}

size_t	c_display(char c, t_mark mk)
{
	size_t len;
	int pad;

	//printf("precis: %d \n", mk.precis);
	mk.len = 1;
	pad = (mk.width - ( mk.point ? mk.precis : mk.len));

	len = 0;
	if (!mk.minus)
		len += put_padding(pad);
	ft_putchar(c);
	if (mk.minus)
		len += put_spaces(mk);
	return (len + 1);
}

size_t	cc_display(wchar_t c, t_mark mk)
{
	size_t len;
	int pad;

	//printf("precis: %d \n", mk.precis);
	mk.len = ft_charlen_utf8(c);
	pad = (mk.width - ( mk.point ? mk.precis : mk.len));

	len = 0;
	if (!mk.minus)
		len += put_padding(pad);
	len += ft_putchar_utf8(c);
	if (mk.minus)
		len += put_spaces(mk);
	return (len);
}
