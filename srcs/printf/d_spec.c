/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/20 16:59:25 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	d_spec(va_list ap, const char *format, t_mark mk)
{
	(void)format;
	
	if (mk.h == 2)
		return (d_display((long long)va_arg(ap, int), mk));
	if (mk.l == 1)
		return (d_display((long long)va_arg(ap, long) , mk));
	if (mk.l == 2)
		return (d_display((long long)va_arg(ap, long long) , mk));
	return (d_display((long long)va_arg(ap, int) , mk));
}
