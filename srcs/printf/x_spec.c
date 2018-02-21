/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/21 22:22:35 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	x_spec(va_list ap, const char *format, t_mark mk)
{
	(void)format;
	

	if (*format == 'X')
		return (x_display((uintmax_t)va_arg(ap, long long) , mk, "0123456789ABCDEF"));
	if (mk.h == 1)
		return (x_display((unsigned short)va_arg(ap, int), mk, "0123456789abcdef"));
	if (mk.z == 1)
		return (x_display((size_t)va_arg(ap, size_t), mk, "0123456789abcdef"));
	if (mk.h == 2)
		return (x_display((unsigned char)va_arg(ap, int), mk, "0123456789abcdef"));
	if (mk.l == 1)
		return (x_display((unsigned long long)va_arg(ap, long) , mk, "0123456789abcdef"));
	if (mk.l == 2)
		return (x_display((unsigned long long)va_arg(ap, long long) , mk, "0123456789abcdef"));
	if (mk.j == 1)
		return (x_display((uintmax_t)va_arg(ap, long long) , mk, "0123456789abcdef"));
	return (x_display((unsigned long)va_arg(ap,unsigned long) , mk, "0123456789abcdef"));
}
