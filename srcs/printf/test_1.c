/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:31 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/15 19:37:17 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test(void)
{
	int i = 0;
	printf("___________ 0 ______________\n");
	i = ft_printf("Test de %s: -%%-\n", "%%");
	ft_putnbrl(i);
	i = printf("Test de %s: -%%-\n", "%%");
	ft_putnbrl(i);
	i = ft_printf("d -%d- et -%d-\n", 1,42);
	ft_putnbrl(i);
	i = printf("d -%d- et -%d-\n", 1,42);
	ft_putnbrl(i);
	i = ft_printf("s -%6.4s- et -%s-\n", "bien","fait");
	ft_putnbrl(i);
	i = printf("s -%6.4s- et -%s-\n", "bien","fait");
	ft_putnbrl(i);
}

void	test_1(void)
{
	printf("___________ 1 ______________\n");
	printf("%S", L"米");
	ft_printf("%S", L"米");
	printf("\n");
}

void	test_2(void)
{
	printf("___________ 2 ______________\n");
	void *s = malloc(2);
	int i = 0;
	i = printf("%p\n", s);
	ft_putnbrl(i);
	i = ft_printf("%\n", 0);
	ft_putnbrl(i);
}


void	test_3(char *s, char *s2)
{
	printf("___________ 3 ______________\n");
	(void)s;
	(void)s2;
	//int i;
	//i = ft_printf("{%S}\n", NULL);
	//i = printf("pp{%S}", NULL);
	//ft_putnbrl(ft_nbrlen(ft_atoi(s2)));
}
