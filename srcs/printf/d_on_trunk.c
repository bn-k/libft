/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/04 17:01:07 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	d_math(long long *nb, t_body *body)
{
	body->len = ft_nbrlen_iull(*nb);
	if (*nb < 0)
	{
		body->minus = 1;
		*nb = -*nb;
	}
	if (body->point && !body->dash)
	{
		body->fill = POS(body->precis - body->len);
	}
	//printf("len: %d, right %d , fill %d\n", body->len, body->right, body->fill);
	body->plus = body->plus * !body->minus;
	body->left = POS(body->width - body->len - SIGN - body->fill * (body->dash ? 0 : 1));
	body->right = (body->width - body->len - (body->plus || body->minus)) * body->dash;
	//printf("left %d, right %d , fill %d\n", body->left, body->right, body->fill);
}

static int d_casted(long long nb, t_total *total, t_body *body)
{
	char *s;
	d_math(&nb, body);
	s = ft_itoa_iull(nb);
	printf("itoa : %s len %d \n", s, ft_strlen(s));
	trunk_integers(s, total, body);
	return (1);
}

int		d_on_trunk(t_total *total, t_body *body)
{
	if (total->format[-1] == 'D')
		return (d_casted((long long)va_arg(*total->ap, long long) , total, body));
	else if (body->h == 1)
		return (d_casted((short)va_arg(*total->ap, int), total, body));
	else if (body->z == 1)
		return (d_casted((size_t)va_arg(*total->ap, size_t), total, body));
	else if (body->h == 2)
		return (d_casted((signed char)va_arg(*total->ap, void*), total, body));
	else if (body->l == 1)
		return (d_casted((long long)va_arg(*total->ap, long) , total, body));
	else if (body->l == 2)
		return (d_casted((long long)va_arg(*total->ap, long long) , total, body));
	else if (body->j == 1)
		return (d_casted((intmax_t)va_arg(*total->ap, long long) , total, body));
	else 
		return (d_casted((long long)va_arg(*total->ap, int) , total, body));
}
