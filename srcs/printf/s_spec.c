/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:18 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/15 16:57:54 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	s_spec(va_list ap, const char *format, t_mark mk)
{
	size_t len;
	char *s;
	(void)format;
	
	s = va_arg(ap, char *);
	s = (s ? s : ft_strdup("(null)"));
	len = s_display(s, mk);
	return (len);
}
