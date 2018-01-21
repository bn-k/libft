/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:49:56 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 06:19:33 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (*alst)
	{
		tmp = *alst;
		del((*alst)->content, (*alst)->content_size);
		*alst = tmp->next;
	}
	free(*alst);
	free(tmp);
	*alst = NULL;
	tmp = NULL;
}
