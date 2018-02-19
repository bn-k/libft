/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/15 17:54:45 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	d_spec(va_list ap, const char *format, t_mark mk)
{
	int d;
	(void)format;
	(void)mk;
	
	printf("test-> %d- \n", mk.l);
	d = va_arg(ap, int);
	return (d_display((int long long)d, mk));
}
