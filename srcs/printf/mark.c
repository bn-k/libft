/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:33:41 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/21 17:38:57 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_mark		init(void)
{
	t_mark mk;

	mk.hash = 0;
	mk.zero = 0;
	mk.minus = 0;
	mk.space = 0;
	mk.plus = 0;
	mk.apos = 0;
	mk.width = 0;
	mk.precis = 0;
	mk.point = 0;
	mk.len = 0;
	mk.l = 0;
	mk.h = 0;
	mk.j = 0;
	mk.z = 0;
	mk.q = 0;
	mk.neg = 0;
	return (mk);
}

void	field_width(const char **format, t_mark *mk)
{
	if (ft_isdigit(**format))
	{
		mk->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	precision(const char **format, t_mark *mk)
{
	if (**format == '.')
	{
		mk->point = 1;
		(*format)++;
		if (ft_isdigit(**format))
		{
			mk->precis = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
			mk->precis = 0;
	}
}

void	format_parsing(const char **format, t_mark *mk)
{
	*mk = init();
	flags(format, mk);
	field_width(format, mk);
	precision(format, mk);
	modifier(format, mk);
	mk->space = mk->plus ? 0 : mk->space;
}
