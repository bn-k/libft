/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/04 15:20:43 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	o_math(long long *nb, t_body *body)
{
	body->len = ft_nbrlen_base(*nb, 8);
	if (body->point)
		body->fill = body->precis - body->len;
	body->left = (body->width - body->len - HASH) * (body->dash ? 0 : 1);
	body->right = (body->width - body->len - (body->plus || body->minus)) * body->dash;
	//printf("left %d, right %d , dash %d\n", body->left, body->right, body->dash);
}

static int		o_casted(long long nb, t_total *total, t_body *body)
{
	char *s;
	o_math(&nb, body);
	s = ft_itoa_base(nb, "01234567");
	trunk_o(s, total, body);
	return (1);
}

int	o_on_trunk(t_total *total, t_body *body)
{
	if (total->format[-1] == 'O')
		return (o_casted((unsigned long long)va_arg(*total->ap, long long) , total, body));
	else if (body->h == 1)
		return (o_casted((unsigned short)va_arg(*total->ap, int), total, body));
	else if (body->z == 1)
		return (o_casted((size_t)va_arg(*total->ap, size_t), total, body));
	else if (body->h == 2)
		return (o_casted((unsigned char)va_arg(*total->ap, int), total, body));
	else if (body->l == 1)
		return (o_casted((unsigned long long)va_arg(*total->ap, long) , total, body));
	else if (body->l == 2)
		return (o_casted((unsigned long long)va_arg(*total->ap, long long) , total, body));
	else if (body->j == 1)
		return (o_casted((uintmax_t)va_arg(*total->ap, long long) , total, body));
	else
		return (o_casted((unsigned int)va_arg(*total->ap, unsigned int) , total, body));
}
