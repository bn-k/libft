/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:07:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/15 17:59:04 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int nb)
{
	if (nb == INT_MIN)
		return (11);
	if (nb == 0)
		return (0);
	if (nb < 10 && nb > 0)
		return (1);
	if (nb < 0)
		return (1 + ft_nbrlen(nb * -1));
	if (nb > 9)
		return (1 + ft_nbrlen(nb / 10));
	return (0);
}
