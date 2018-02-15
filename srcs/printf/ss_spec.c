/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:18 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/15 16:59:51 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	ss_spec(va_list ap, const char *format, t_mark mk)
{
	size_t len;
	(void)format;
	(void)ap;
	(void)mk;
	wchar_t *s;

	if (!(s = va_arg(ap, wchar_t *)))
		return (-1);
	len = ss_display(s, mk);
	return (len);
}
