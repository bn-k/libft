/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 06:23:23 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 06:51:28 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	while (lst)
	{
		lst = f(lst);
		lst = lst->next;
	}
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	return (new);
}
