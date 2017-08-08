/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 17:34:55 by abbenham          #+#    #+#             */
/*   Updated: 2017/08/08 13:29:54 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_cmp(char *str1, char *str2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str1[i] == str2[j])
	{
		if (str2[j + 1] == '\0')
			return (1);
		i++;
		j++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == to_find[j])
		{
			if (1 == ft_cmp(str + i, to_find + j))
				return (&str[i]);
		}
		i++;
	}
	return ("(null)");
}
