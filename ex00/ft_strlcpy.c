/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 19:31:13 by abbenham          #+#    #+#             */
/*   Updated: 2017/08/08 22:50:55 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen2(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int all_len;
	unsigned int i;

	all_len = ft_strlen2(src);
	i = 0;
	if (*src == '\0')
		*dest = '\0';
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	return (all_len);
}
