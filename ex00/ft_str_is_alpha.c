/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 20:21:24 by abbenham          #+#    #+#             */
/*   Updated: 2017/08/06 20:49:01 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 65 ||
				(str[i] > 90 && str[i] < 97) ||
				str[i] > 122)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
