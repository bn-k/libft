/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/21 21:28:37 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	o_spec(va_list ap, const char *format, t_mark mk)
{
	(void)format;
	

	if (*format == 'O')
		return (o_display((uintmax_t)va_arg(ap,unsigned long) , mk));
	if (mk.h == 1)
		return (o_display((unsigned short)va_arg(ap, int), mk));
	if (mk.z == 1)
		return (o_display((size_t)va_arg(ap, size_t), mk));
	if (mk.h == 2)
		return (o_display((unsigned char)va_arg(ap, int), mk));
	if (mk.l == 1)
		return (o_display((unsigned long long)va_arg(ap, long) , mk));
	if (mk.l == 2)
		return (o_display((unsigned long long)va_arg(ap, long long) , mk));
	if (mk.j == 1)
		return (o_display((uintmax_t)va_arg(ap, long long) , mk));
	return (o_display((unsigned int)va_arg(ap,unsigned int) , mk));
}