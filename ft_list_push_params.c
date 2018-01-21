/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 06:53:37 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 06:53:44 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_push_params(int ac, char **av)
{
	int	i = 1;
	t_list	*list;

	list = NULL;
	if (ac == 1)
		return (NULL);
	while (av[i])
		ft_list_push_front(&list,av[i++]);
	return (list);
}
