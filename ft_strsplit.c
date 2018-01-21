/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:28:08 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 04:26:11 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#define I_WHITE (str[i] == c)
#define J_WHITE (str[j] == c)

static int	ft_strxlen(char const *str, char c)
{
	int		i;

	i = 0;
	while (I_WHITE)
		i++;
	while (str[i] && !(I_WHITE))
		i++;
	return (i);
}

char		*ft_dupli(char const *str, int len, char c)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * len + 1);
	while (I_WHITE)
		i++;
	while (j < len && !(I_WHITE))
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int			ft_ptrlen(char const *str, char c)
{
	int		nb;
	int		i;
	int		j;

	nb = 0;
	i = 0;
	j = -1;
	if (!I_WHITE)
		nb++;
	while (str[i])
	{
		if (str[i] && (!I_WHITE) && J_WHITE)
			nb++;
		i++;
		j++;
	}
	return (nb);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	int		tab_len;
	int		wd_len;
	char	**split;

	split = (NULL);
	if (s == NULL)
		return (NULL);
	i = 0;
	k = 0;
	wd_len = 0;
	tab_len = ft_ptrlen(s, c);
	if (!(split = malloc(sizeof(char*) * tab_len + 1)))
		return (NULL);
	!(*s) ? tab_len = 0 : 0;
	while (k < tab_len)
	{
		i = i + wd_len;
		wd_len = ft_strxlen(&s[i], c);
		split[k] = ft_dupli(&s[i], wd_len, c);
		k++;
	}
	split[k] = 0;
	return (split);
}
