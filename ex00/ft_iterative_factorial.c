/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 07:00:54 by abbenham          #+#    #+#             */
/*   Updated: 2017/08/05 18:21:04 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		facto;

	facto = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (nb != 0)
	{
		facto = facto * nb;
		nb--;
	}
	return (facto);
}
