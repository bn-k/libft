/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:33:41 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/14 12:10:14 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_mark		init(void)
{
	t_mark mk;

	mk.minus = 0;
	mk.plus = 0;
	mk.zero = 0;
	mk.hash = 0;
	mk.width = 0;
	mk.precis = -1;
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
		(*format)++;
		mk->precis = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;

	}
}

void	format_parsing(const char **format, t_mark *mk)
{
	*mk = init();
	field_width(format, mk);
	precision(format, mk);
}
