/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 08:46:48 by abbenham          #+#    #+#             */
/*   Updated: 2017/08/08 18:34:34 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d;
	unsigned int	len_max;
	unsigned int	i;

	i = 0;
	d = ft_strlen(dest);
	len_max = ft_strlen(dest) + ft_strlen(src);
	while (src[i] && i + d < size)
	{
		dest[d] = src[i];
		i++;
		d++;
	}
	return (len_max);
}
