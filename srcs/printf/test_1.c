/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:31 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/19 11:07:55 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test(void)
{
	int ft;
	int i;
	printf("___________ 0 ______________\n");
	//i = ft_printf("Test de %d: -%' #d-\n",55, 23);
	//ft_putnbrl(i);
	ft = ft_printf("TEST : %ld\n", 0x44ff551100);
	i = printf("TEST : %ld\n", 0x44ff551100);
	printf("%d - %d\n", ft, i);

	ft = ft_printf("%5d<\n",-42) ;
	i = printf("%5d<\n", -42);
	printf("%d - %d\n", ft, i);

	ft = ft_printf("%+12.5d<\n", 140) ;
	i = printf("%+12.5d<\n", 140) ;
	printf("%d - %d\n", ft, i);
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
