/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:21:25 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 03:01:39 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nblen(int n)
{
	if (n < 0)
		return (1 + ft_nblen(-n));
	if (n < 10)
		return (1);
	return (1 + ft_nblen(n / 10));
}

char			*ft_itoa(int n)
{
	char	*s;
	int		nblen;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = n < 0 ? -1 : 1;
	nblen = ft_nblen(n);
	n = n < 0 ? -n : n;
	if (!(s = (char *)malloc(sizeof(char) * nblen + 1)))
		return (NULL);
	s[nblen] = 0;
	while (--nblen >= 0)
	{
		s[nblen] = n % 10 + 48;
		n /= 10;
	}
	s[0] = sign < 0 ? '-' : s[0];
	return (s);
}
