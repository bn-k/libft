/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 06:56:12 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 06:56:32 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_back(t_list **begin_list, void *content)
{
	t_list *tmp;

	tmp = *begin_list;
	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
	}
}
