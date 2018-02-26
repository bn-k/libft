/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:18 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/22 18:22:38 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_mark	ss_spec(va_list ap, const char **format, t_mark mk)
{
	(void)format;
	(void)ap;
	(void)mk;
	wchar_t *s;
	wchar_t null[7] = L"(null)\0";

	if (!(s = va_arg(ap, wchar_t *)))
		s = null;
	return (ss_display(s, mk));
}
