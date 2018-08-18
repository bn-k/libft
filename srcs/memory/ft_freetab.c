/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:54:34 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/17 16:11:09 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tablen(void **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

void	ft_freetab(void **tab, int size)
{
	int		i;

	if (tab)
	{
		i = 0;
		while (i < size)
		{
			ft_memdel((void**)&tab[i]);
			i++;
		}
	}
}
