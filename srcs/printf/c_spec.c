/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:18 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/22 10:55:22 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	c_spec(va_list ap, const char *format, t_mark mk)
{
	(void)format;

	if (mk.l || *format == 'C')
		return (cc_display((wchar_t)va_arg(ap, wint_t), mk));
	else
		return (c_display((char)va_arg(ap, int), mk));
}
