/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/27 17:08:53 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void	left_pad(t_mark *mk)
{
	int i;

	i = 0;
	while ((!mk->zero || mk->point) && i < POS(mk->pad - mk->fill))
	{
		mk->slice[mk->slice_len] = ' ';
		mk->slice_len++;
		i++;
	}
	while (mk->zero && !mk->point && i < mk->pad)
	{
		mk->slice[mk->slice_len] = '0';
		mk->slice_len++;
		i++;
	}
}

static void	string(unsigned long long nb, t_mark *mk)
{
	int i;

	//printf("fill: %d\n", mk->fill);
	i = 0;
	if (nb == 0 && mk->point && mk->precis == 0)
		;
	else
	{
		while (mk->point && (i < mk->fill))
		{
			mk->slice[mk->slice_len] = '0';
			mk->slice_len++;
			i++;
		}
		ft_strcat(&mk->slice[mk->slice_len], ft_itoa_base(nb, "01234567")); 
		mk->slice_len += mk->len;
	}
}

static void	right_pad(t_mark *mk)
{
	int i;

	i = 0;
	while (i < POS(mk->pad - mk->fill))
	{
		mk->slice[mk->slice_len] = ' ';
		mk->slice_len++;
		i++;
	}
}

static t_mark	stringify_format(unsigned long long i, t_mark mk)
{
	o_math(i, &mk);
	if (!mk.minus)
		left_pad(&mk);
	string(i, &mk);
	if (mk.minus)
		right_pad(&mk);
	return (mk);
}

t_mark	o_display(unsigned long long i, t_mark mk)
{
	mk = stringify_format(i, mk);
	return (mk);
}
