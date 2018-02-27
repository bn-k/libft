/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/27 12:32:07 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	left_pad(t_mark *mk)
{
	int i;

	i = 0;
	while (i < mk->pad)
	{
		mk->slice[mk->slice_len] = ' ';
		mk->slice_len++;
		i++;
	}
}

static void	string(wchar_t *s, t_mark *mk)
{
	int i;
	int tmp;
	int len;

	i = 0;
	len = 0;
	while (len < mk->len && s[i])
	{
		if (!(tmp = conv_utf8(&mk->slice[mk->slice_len], s[i], mk->len - len)))
			break;
		mk->slice_len += tmp;
		len += tmp;
		i++;
	}
}

static void	right_pad(t_mark *mk)
{
	int i;

	i = 0;
	while (i < mk->pad)
	{
		mk->slice[mk->slice_len] = ' ';
		mk->slice_len++;
		i++;
	}
}

static t_mark	stringify_format(wchar_t *s, t_mark mk)
{
	math_utf8(s, &mk);
	if (!mk.minus)
		left_pad(&mk);
	string(s, &mk);
	if (mk.minus)
		right_pad(&mk);
	return (mk);
}

t_mark	ss_display(wchar_t *s, t_mark mk)
{
	mk = stringify_format(s, mk);
	return (mk);
}
