/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:38:39 by abbenham          #+#    #+#             */
/*   Updated: 2018/01/08 15:05:31 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#include "libft.h"
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000

typedef struct	s_x
{
	char		*s;
	char		*buf;
    	int		size;
	int		fd;
	struct s_x	*next;
}   t_x;

int get_next_line(const int fd, char **line);
#endif
