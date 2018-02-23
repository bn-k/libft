/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/23 15:50:30 by abbenham         ###   ########.fr       */
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

static size_t		put_padding(int len, t_mark mk)
{
	int i;

	i = 0;
	if (len <= 0)
		return (0);
	while (i < len)
	{
		ft_putchar(mk.zero ? '0' : ' ');
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
		len += put_padding(pad,mk);
	ft_putchar(c);
	if (mk.minus)
		len += put_spaces(mk);
	return (len + 1);
}

size_t	cc_display(wchar_t c, t_mark mk)
{
	size_t len;
	int pad;

	if (c >= 0x10ffff  || c > WINT_MAX || MB_CUR_MAX == 1 || (c >= 0xd800 && c <= 0xdfff) \
			|| (MB_CUR_MAX == 1 && c >= 127 && c <= 256))
		return (-1);
	mk.len = ft_charlen_utf8(c);
	pad = (mk.width - ( mk.point ? mk.precis : mk.len));
	len = 0;
	if (!mk.minus)
		len += put_padding(pad, mk);
	len += ft_putchar_utf8(c);
	if (mk.minus)
		len += put_spaces(mk);
	return (len);
}
