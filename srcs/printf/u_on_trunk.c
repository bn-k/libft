/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/04 15:47:22 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	u_math(long long *nb, t_body *body)
{
	body->len = ft_nbrlen_iull(*nb);
	body->plus = body->plus * !body->minus;
	if (body->point)
		body->fill = body->precis - body->len;
	body->left = (body->width - body->len - (body->plus || body->minus)) * (body->dash ? 0 : 1);
	body->right = (body->width - body->len - (body->plus || body->minus)) * body->dash;
	//printf("left %d, right %d , dash %d\n", body->left, body->right, body->dash);
}

static int	u_casted(long long nb, t_total *total, t_body *body)
{
	char *s;
	u_math(&nb, body);
	s = ft_itoa_iull(nb);
	trunk_integers(s, total, body);
	return (1);
}

int	u_on_trunk(t_total *total, t_body *body)
{
	if (total->format[-1] == 'p')
	{
		body->sharp = 1;
		return (u_casted((uintmax_t)va_arg(*total->ap,  unsigned long) , total, body));
	}
	else if (total->format[-1] == 'U')
		return (u_casted((unsigned long long)va_arg(*total->ap, unsigned long long) , total, body));
	else if (body->h == 1)
		return (u_casted(( unsigned short)va_arg(*total->ap,  unsigned int), total, body));
	else if (body->z == 1)
		return (u_casted((size_t)va_arg(*total->ap, size_t), total, body));
	else if (body->h == 2)
		return (u_casted((unsigned char)va_arg(*total->ap,  unsigned int), total, body));
	else if (body->l == 1)
		return (u_casted(( unsigned long long)va_arg(*total->ap,  unsigned long) , total, body));
	else if (body->l == 2)
		return (u_casted(( unsigned long long)va_arg(*total->ap,  unsigned long long) , total, body));
	else if (body->j == 1)
		return (u_casted((uintmax_t)va_arg(*total->ap,  unsigned long long) , total, body));
	else 
		return (u_casted(( unsigned int)va_arg(*total->ap,  unsigned int) , total, body));
}
