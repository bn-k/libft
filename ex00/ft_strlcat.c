/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 08:46:48 by abbenham          #+#    #+#             */
/*   Updated: 2017/08/09 03:53:39 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strnlen(char *str, int limit)
{
	unsigned int	i;

	i = 0;
	while (str[i] && limit > 0)
	{
		i++;
		limit--;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d;
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;

	i = 0;
	len_src = 0;
	len_dest = ft_strnlen(dest,size);
	d = len_dest;
	while (src[len_src])
		len_src++;
	while (src[i] && d < size - 1)
	{
		dest[d] = src[i];
		i++;
		d++;
	}
	return (len_dest + len_src);
}
