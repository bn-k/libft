/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/27 11:07:51 by abbenham         ###   ########.fr       */
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

static void	string(char *s, t_mark *mk)
{
	int i;

	i = 0;
	while (i < mk->len)
	{
		mk->slice[mk->slice_len] = s[i];
		mk->slice_len++;
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

static t_mark	stringify_format(char *s, t_mark mk)
{
	math(s, &mk);
	if (!mk.minus)
		left_pad(&mk);
	string(s, &mk);
	if (mk.minus)
		right_pad(&mk);
	return (mk);
}

t_mark	s_display(char *s, t_mark mk)
{
	mk = stringify_format(s, mk);
	return (mk);
}
