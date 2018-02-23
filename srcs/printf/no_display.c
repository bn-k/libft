/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/23 11:42:25 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	no_display(t_mark mk)
{
	int len;

	len = 0;
	if (!mk.minus)
	{
		while (mk.width > 1)
		{
			len += ft_putchar(' ');
			mk.width--;
		}
		len++;
		ft_putchar(mk.h);
		return ((size_t)len);
	}
	else if (mk.minus)
	{
		len++;
		ft_putchar(mk.h);
		while (mk.width > 1)
		{
			len += ft_putchar(' ');
			mk.width--;
		}
		return ((size_t)len);
	}
	return (0);
}
