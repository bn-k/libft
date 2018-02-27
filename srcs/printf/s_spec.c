/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:18 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/27 12:41:09 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_mark 	s_spec(va_list ap, const char **format, t_mark mk)
{
	char *s;
	(void)format;
	char null[7] = "(null)\0";

	if (mk.l == 1)
		return (ss_spec(ap, format, mk));
	s = va_arg(ap, char *);
	s = (s ? s : null);
	(*format)++;
	return (s_display(s, mk));
}
