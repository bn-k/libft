/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:33:50 by abbenham          #+#    #+#             */
/*   Updated: 2017/08/06 14:53:44 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_atoi_move(char *str, int *i, int *sign)
{
	while (str[*i] == ' ' || str[*i] == '\n' ||
			str[*i] == '\t' || str[*i] == '\v')
		*i += 1;
	if (str[*i] == '-' && str[*i + 1] != '+')
	{
		*sign = -1;
		*i += 1;
	}
	if (str[*i] == '+' && str[*i + 1] != '-')
		*i += 1;
}

int		ft_atoi(char *str)
{
	int		result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	ft_atoi_move(str, &i, &sign);
	while (str[i] > 47 && str[i] < 58)
		result = result * 10 + str[i++] - 48;
	result = result * sign;
	return (result);
}
