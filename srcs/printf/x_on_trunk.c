/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/04 15:58:23 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	x_math(long long *nb, t_body *body)
{
	body->len = ft_nbrlen_base(*nb, 16);
	if (*nb == 0 && body->minus == 0)
		body->sharp = 0;
	if (body->point)
		body->fill = body->precis - body->len;
	body->left = (body->width - body->len - (body->sharp * 2)) * (body->dash ? 0 : 1);
	body->right = (body->width - body->len - body->sharp * 2) * body->dash;
}

static int	x_casted(long long nb, t_total *total, t_body *body)
{
	char *s;
	x_math(&nb, body);
	s = ft_itoa_base(nb, (total->format[-1] == 'X' ? "0123456789ABCDEF" : "0123456789abcdef"));
	trunk_x(s, total, body);
	return (1);
}

int		x_on_trunk(t_total *total, t_body *body)
{
	if (total->format[-1] == 'p')
	{
		body->minus = 1;
		body->sharp = 1;
		return (x_casted((unsigned long)va_arg(*total->ap,unsigned long) , total, body));
	}
	else if (total->format[-1] == 'X' && body->h == 2)
		return (x_casted((unsigned char)va_arg(*total->ap, long) , total, body));
	else if (total->format[-1] == 'X')
		return (x_casted((unsigned long)va_arg(*total->ap, long) , total, body));
	else if (body->h == 1)
		return (x_casted((unsigned short)va_arg(*total->ap, int), total, body));
	else if (body->z == 1)
		return (x_casted((size_t)va_arg(*total->ap, size_t), total, body));
	else if (body->h == 2)
		return (x_casted((unsigned char)va_arg(*total->ap, int), total, body));
	else if (body->l == 1)
		return (x_casted((unsigned long long)va_arg(*total->ap, long) , total, body));
	else if (body->l == 2)
		return (x_casted((unsigned long long)va_arg(*total->ap, long long) , total, body));
	else if (body->j == 1)
		return (x_casted((uintmax_t)va_arg(*total->ap, long long) , total, body));
	else
		return (x_casted((unsigned int)va_arg(*total->ap, unsigned int) , total, body));
}
