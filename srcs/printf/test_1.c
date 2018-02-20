/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:31 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/20 17:10:20 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test(void)
{
	int ft;
	int i;
	printf("___________ 0 ______________\n");
	ft = ft_printf("|toto%0.d et %+.i et  %   .0D !!!\n", 0, 0, 0);
	i = printf("|toto%0.d et %+.i et  %   .0D !!!\n", 0, 0, 0);
	printf("%d - %d\n", ft, i);

	ft = ft_printf("|%9d-\n", -666);
	i = printf("|%9d-\n", -666);
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
