/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/04 15:19:59 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	c_math(t_body *body)
{
	body->len = 1;
	body->left = (body->width - 1) * (body->dash ? 0 : 1);
	body->right = (body->width - 1) * body->dash;
}

static int		c_casted(char c, t_total *total, t_body *body)
{
	(void)body;
	trunk(&c, total, body);
	return (1);
}

int	no_on_trunk(t_total *total, t_body *body)
{
	char c;
	c = *total->format;
	c_math(body);
	return (c_casted(c, total, body));
}

int		c_on_trunk(t_total *total, t_body *body)
{
	char c;

	if (body->l)
		return (wc_on_trunk(total, body));
	else 
	{
		c = va_arg(*total->ap, int);
		c_math(body);
		return (c_casted(c, total, body));
	}
	return (1);
}
