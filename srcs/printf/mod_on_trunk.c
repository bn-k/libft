/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/04 15:17:02 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	mod_math(char *s, t_body *body)
{
	body->len = ft_strlen(s);
	if (body->point && body->len > body->precis)
			body->len = body->precis;
	body->left = (body->width - body->len) * (body->dash ? 0 : 1);
	body->right = (body->width - body->len) * body->dash;
	//printf("left %d, right %d , dash %d\n", body->left, body->right, body->dash);
}

int		mod_on_trunk(t_total *total, t_body *body)
{
	mod_math("%", body);
	trunk("%", total, body);
	return (1);
}
