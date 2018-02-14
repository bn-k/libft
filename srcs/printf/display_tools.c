/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:19:17 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/14 12:45:13 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		put_padding(int len)
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


size_t		put_precision(char *s, int len)
{
	size_t ret;

	if (len == -1)
		return (ft_putstr(s));
	else
	ret = 0;
	while (*s && len)
	{
		ft_putchar(*s);
		len--;
		ret++;
		s++;
	}
	return (ret);
}
