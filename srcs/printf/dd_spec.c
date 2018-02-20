/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/20 16:49:25 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	dd_spec(va_list ap, const char *format, t_mark mk)
{
	(void)format;
	(void)mk;

	return (d_display((long long)va_arg(ap, long long) , mk));
}
