/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:31 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/21 21:39:31 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test(void)
{
	int ft;
	int i;
	printf("___________ 0 ______________\n");

	unsigned long long f = 555;
	unsigned long long base = 8;

	//printf("f : %llo len : %zu\n",f, ft_nbrlen_base(f, base));

	ft = ft_printf("%-42hhO<\n", LONG_MAX);
	i = printf("%-42hhO<\n", LONG_MAX);
	printf("%d - %d\n", ft, i);

	ft = ft_printf("%+42O\n", -15);
	i = printf("%+42O\n", -15);
	printf("%d - %d\n", ft, i);
}

void	test_1(void)
{
	printf("___________ 1 ______________\n");
}

void	test_2(void)
{
	printf("___________ 2 ______________\n");
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
