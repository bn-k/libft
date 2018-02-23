/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/23 14:35:41 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static size_t		put_precision(char *s, t_mark mk)
{
	size_t ret;

	ret = 0;
	if (!mk.point)
		return (ft_putstr(s));
	while (*s && mk.precis)
	{
		ft_putchar(*s);
		mk.precis--;
		ret++;
		s++;
	}
	return (ret);
}

size_t	s_display(char *s, t_mark mk)
{
	size_t len;
	int pad;

	mk.len = ft_strlen(s);
	//printf("precis: %d \n", mk.precis);
	pad = mk.len > mk.precis ? (mk.width - ( mk.point ? mk.precis : mk.len)) : (mk.width - mk.len);

	len = 0;
	if (!mk.minus)
		len += put_padding(pad, mk);
	len += put_precision(s, mk);
	if (mk.minus)
		len += put_spaces(mk);
	return (len);
}
