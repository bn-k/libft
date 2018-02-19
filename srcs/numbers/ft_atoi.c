/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:25:07 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/15 14:06:04 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SPACE *str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
#define SPACE2 *str == '\v' || *str == '\f'

int		ft_atoi(const char *str)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	while (SPACE || SPACE2)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
		res = (res * 10) + *str++ - 48;
	return (res * sign);
}