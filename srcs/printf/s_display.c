/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:01:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/23 14:35:41 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*left_pad(t_mark mk)
{
	char	*s;
	int	len;
	int	i;


	i = 0;
	len = mk.width - mk.len;
	if (len > 0)
	{
		s = (char *)malloc(sizeof(char) * len + 1);
		s[len] = '\0';
		while (i < len)
		{
			s[i] = ' ';
			mk.slice_len += 1;
			i++;
		}
	}
	else
		return ("");
	return (s);
}

t_mark	stringify_format(char *s, t_mark mk)
{
	int slen;
	mk.len = ft_strlen(s);
	slen = ft_strlen(s);
	ft_strcat(mk.slice, left_pad(mk));
	ft_strcat(mk.slice, s);
	mk.slice_len += slen;
	return (mk);
}

t_mark	s_display(char *s, t_mark mk)
{
	mk = stringify_format(s, mk);
	//printf("s_display: %s\n", mk.slice);
	return (mk);
}
