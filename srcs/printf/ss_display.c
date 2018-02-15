/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/15 16:58:01 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static size_t		put_precision(wchar_t *s, int len)
{
	size_t ret;

	if (len == -1)
		return (ft_putstr_utf8(s));
	else
		ret = 0;
	while (*s && len)
	{
		ft_putchar_utf8(*s);
		len--;
		ret++;
		s++;
	}
	return (ret);
}

size_t	ss_display(wchar_t *s, t_mark mk)
{
	size_t len;

	len = 0;
	if (mk.width)
		len = put_padding(mk.width);
	len += put_precision(s, mk.precis);
	return (len);
}
