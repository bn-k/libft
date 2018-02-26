/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/22 23:10:29 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_mark	p_display(unsigned long long d, t_mark mk, char *base)
{
	return (mk);
}


t_mark	p_spec(va_list ap, const char **format, t_mark mk)
{
	long unsigned int d;
	(void)format;
	(void)mk;

	d = va_arg(ap, long unsigned int);
	return (p_display(d, mk, "0123456789abcdef"));
}
