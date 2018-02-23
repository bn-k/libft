/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:31 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/23 15:50:39 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void	test_1(void)
{
	int ft;
	int i;
	printf("___________ 1 ______________\n");

	//ft = ft_printf("%C\n", (wint_t)-2);
	//i= printf("hello %C\n", (wint_t)-2);
	//printf("(%d)  (%d)\n", ft, i);
	ft = ft_printf("%###.0o%#.O et %#.1o !\n",0, 0, 0);
	i = printf("%###.0o%#.O et %#.1o !\n",0, 0, 0);
	printf("%d  %d\n", ft, i);

	ft = ft_printf("%.5S\n", L"Risitas¬");
	i = printf("%.5S\n", L"Risitas¬");
	printf("%d  %d\n", ft, i);

	ft = ft_printf("%.5S\n", L"†œø˙Unicode string");
	i = printf("%.5S\n", L"†œø˙Unicode string");
	printf("%d  %d\n", ft, i);

	ft = ft_printf("%.4S\n", L"我是一只猫。");
	i = printf("%.4S\n", L"我是一只猫。");
	printf("%d - %d\n", ft, i);

	ft = ft_printf("%15.5S\n", L"我是一只猫。");
	i = printf("%15.5S\n", L"我是一只猫。");
	printf("%d - %d\n", ft, i);

	ft = ft_printf("%.S\n", L"我是一只猫。");
	i = printf("%.S\n", L"我是一只猫。");
	printf("%d - %d\n", ft, i);

	/*
	ft = ft_printf("%U\n", ULONG_MAX);
	i = printf("%U\n", ULONG_MAX);
	printf("%d - %d\n", ft, i);

	ft = ft_printf("%U\n", ULONG_MAX / 2);
	i = printf("%U\n", ULONG_MAX / 2);
	printf("%d - %d\n", ft, i);

	ft = ft_printf("{%5p}\n", 0);
	i = printf("{%5p}\n", 0);
	printf("%d - %d\n", ft, i);

	ft = ft_printf("{%05p}\n", 0);
	i = printf("{%05p}\n", 0);
	printf("%d - %d\n", ft, i);


	ft = ft_printf("{%}\n");
	i = printf("{%}\n");
	printf("%d - %d\n", ft, i);

	ft = ft_printf("% Zoo\n");
	i = printf("% Zoo\n");
	printf("%d - %d\n", ft, i);
	*/

}

void	test(void)
{
	printf("___________ 0 ______________\n");
	printf("%lld\n", MB_CUR_MAX);
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
