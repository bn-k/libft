/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:58:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/15 19:22:36 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_print_adress(long unsigned int nbr)
{
	int				i;
	int				nbr_tab[13];
	char 			base [] = "0123456789abcdef";
	int				len;
	ft_putstr("0x");

	len = 2;
	i = 0;
	if (nbr == 0)
		ft_putchar(base[0]);
	while (nbr > 0)
	{
		nbr_tab[i++] = nbr % 16;
		nbr = nbr / 16;
		len++;
	}
	while (i > 0)
		ft_putchar(base[nbr_tab[i-- - 1]]);
	return (len);
}
