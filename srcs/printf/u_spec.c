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

size_t	u_spec(va_list ap, const char *format, t_mark mk)
{
	(void)format;
	if (mk.l == 2)
		return (u_display((unsigned long long)va_arg(ap,unsigned long long), mk));
	return (u_display((unsigned long long)va_arg(ap,unsigned long long), mk));
}
