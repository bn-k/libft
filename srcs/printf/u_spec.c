/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/22 19:04:51 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_mark	u_spec(va_list ap, const char **format, t_mark mk)
{
	if (**format == 'U')
		return (u_display((unsigned long)va_arg(ap,unsigned long), mk));
	if (mk.h == 1)
		return (u_display((unsigned short)va_arg(ap,unsigned int), mk));
	if (mk.h == 2)
		return (u_display((unsigned char)va_arg(ap,unsigned int), mk));
	if (mk.l == 1)
		return (u_display((unsigned long long)va_arg(ap,long), mk));
	if (mk.l == 2)
		return (u_display((unsigned long long)va_arg(ap,long long), mk));
	if (mk.j == 1)
		return (u_display((uintmax_t)va_arg(ap, uintmax_t), mk));
	if (mk.z == 1)
		return (u_display((uintmax_t)va_arg(ap,unsigned long long), mk));
	else
	return (u_display((unsigned int)va_arg(ap, unsigned int), mk));
}
