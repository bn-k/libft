/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:18 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/27 12:41:43 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_mark	ss_spec(va_list ap, const char **format, t_mark mk)
{
	(void)format;
	(void)ap;
	(void)mk;
	wchar_t *s;

	(*format)++;
	s = va_arg(ap, wchar_t *);
	if (s == NULL)
		return (ss_display(L"(null)\0", mk));
	return (ss_display(s, mk));
}
