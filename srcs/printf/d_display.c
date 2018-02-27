/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/27 15:44:34 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void	left_pad(t_mark *mk)
{
	int i;

	i = 0;
	while ((!mk->zero || mk->point) && i < POS(mk->pad - mk->fill - (mk->plus || mk->neg || mk->space)))
	{
		mk->slice[mk->slice_len] = ' ';
		mk->slice_len++;
		i++;
	}
	if (mk->neg)
	{
		mk->slice[mk->slice_len] = '-';
		mk->slice_len++;
	}
	if ((mk->plus || mk->space)  && !mk->neg)
	{
		mk->slice[mk->slice_len] = (mk->plus ? '+' : ' ');
		mk->slice_len++;
	}
	while (mk->zero && !mk->point && i < POS(mk->pad - (mk->plus || mk->neg || mk->space)))
	{
		mk->slice[mk->slice_len] = '0';
		mk->slice_len++;
		i++;
	}
}

static void	string(long long nb, t_mark *mk)
{
	int i;

	//printf("fill: %d\n", mk->fill);
	i = 0;
	if (mk->neg && mk->minus)
	{
		mk->slice[mk->slice_len] = '-';
		mk->slice_len++;
	}
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
		ft_strcat(&mk->slice[mk->slice_len], ft_itoa_iull(nb)); 
		mk->slice_len += mk->len;
	}
}

static void	right_pad(t_mark *mk)
{
	int i;

	i = 0;
	while (i < mk->pad - POS(mk->fill - (mk->plus || mk->neg)))
	{
		mk->slice[mk->slice_len] = ' ';
		mk->slice_len++;
		i++;
	}
}

static t_mark	stringify_format(long long i, t_mark mk)
{
	mk.neg = (i < 0 ? 1 : 0);
	i = (i < 0 ? -i : i);
	d_math(i, &mk);
	if (!mk.minus)
		left_pad(&mk);
	string(i, &mk);
	if (mk.minus)
		right_pad(&mk);
	return (mk);
}

t_mark	d_display(int long long i, t_mark mk)
{
	mk = stringify_format(i, mk);
	return (mk);
}
