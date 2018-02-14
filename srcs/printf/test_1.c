/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:31 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/14 15:32:17 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test_1(void)
{
	char *str = ft_strdup("autre");
	ft_printf("Test de %s: -%%-\n", "%%");
	ft_printf("Voici un -%d- test pour -%d-\n", 1,42);
	ft_printf("Voici un -%6.4s- test pour -%s-\n", str,"finir");
}

void	test_3(char *s, char *s2)
{
			printf(s, s2);
}

void	test_2(void)
{
	printf("------Test 2-------\nreal printf...\n");
	int number = 2;
	char *pointer = ft_strdup("WORD");
	printf("---%*d----\n", 6, number);
	printf("--->%c<----\n", '\0');
	ft_memdel((void **)&pointer);
}


