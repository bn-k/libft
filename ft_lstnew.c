/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:06:12 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 06:58:07 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(list->content = (void *)malloc(sizeof(void const *) *
					content_size)))
		return (NULL);
	if (!(content))
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
	}
	else
	{
		list->content = ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
		list->next = NULL;
	}
	return (list);
}
