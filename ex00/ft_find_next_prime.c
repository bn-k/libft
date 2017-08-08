/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 12:27:06 by abbenham          #+#    #+#             */
/*   Updated: 2017/08/08 13:52:01 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime2(int nb)
{
	int		divisor;

	divisor = 2;
	if (nb <= 1)
		return (0);
	while (divisor < nb - 1)
	{
		if (nb % divisor == 0)
			return (0);
		divisor++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (1 != ft_is_prime2(nb))
	{
		nb++;
	}
	return (nb);
}
