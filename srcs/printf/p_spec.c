/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/15 19:32:13 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	p_spec(va_list ap, const char *format, t_mark mk)
{
	long unsigned int d;
	(void)format;
	(void)mk;
	
	d = va_arg(ap, long unsigned int);
	if (d == 0)
	{
		printf("d = %lu\n",d);
		return (-1);
	}
	return (ft_print_adress(d));
}
