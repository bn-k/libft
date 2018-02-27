/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/27 09:06:37 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utf8.h"

t_mark	c_display(char c, t_mark mk)
{
	(void)c;
	return (mk);
}

t_mark	cc_display(wchar_t c, t_mark mk)
{
	(void)c;
	if (c >= 0x10ffff  || c > WINT_MAX || MB_CUR_MAX == 1 || (c >= 0xd800 && c <= 0xdfff) \
			|| (MB_CUR_MAX == 1 && c >= 127 && c <= 256))
		return (mk);
	return (mk);
}
