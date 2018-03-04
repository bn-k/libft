/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/04 15:18:16 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utf8.h"

static void	wc_math(t_body *body)
{
	body->left = (body->width - body->len) * (body->dash ? 0 : 1);
	body->right = (body->width - 1) * body->dash;
}

int		wc_casted(wchar_t wc, t_total *total, t_body *body)
{
	int	i;
	char *s;
 
	i = 0;
	s = (char *)malloc(sizeof(char) * 5);
	body->len = conv_utf8(s, wc, 4);
	wc_math(body);
	trunk_unicode(&wc, total, body);
	free(s);
	return (1);
}

int		wc_on_trunk(t_total *total, t_body *body)
{
	wchar_t wc;
	wc = va_arg(*total->ap, wint_t);
	return (wc_casted(wc, total, body));
}
