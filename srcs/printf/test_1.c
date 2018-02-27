/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:31 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/27 17:06:03 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void	assert(char *s, char *s2)
{
	int ft;
	int i;

	printf("--------- assert _________\n");
	ft = ft_printf(s, s2);
	i= printf(s, s2);
	printf("(%d)  (%d)\n", ft, i);
}

void	assertI(char *s, long long s2)
{
	int ft;
	int i;

	printf("--------- assert _________\n");
	ft = ft_printf(s, s2);
	i= printf(s, s2);
	printf("(%d)  (%d)\n", ft, i);
}

void	assertS(char *s, wchar_t *s2)
{
	int ft;
	int i;

	printf("--------- assert _________\n");
	ft = ft_printf(s, s2);
	i= printf(s, s2);
	printf("(%d)  (%d)\n", ft, i);
}

void	test(void)
{
	//printf("___________ 0 ______________\n");
}

void	test_1(void)
{
	int ft;
	int i;
	printf("___________ 1 ______________\n");


	assertI("%010o\n", 34513);
	assertI("%lo\n", LONG_MAX);
	assertI("%o\n", -4);
	assertI("%o\n", INT_MIN);
	assertI("%o\n", LONG_MAX);
	assertI("%+.0o\n", 333);
	assertI("%+.0o\n", 3);
	assertI("%.5o\n", 1);
	assertI("%+8.5o\n", 2);
	assertI("%+08.5o\n", 22);
	assertI("%+05.8o\n", 3);
	assertI("%+08o\n", 4);
	assertI("%+-010o-\n", -482);
	assertI("%+ 04o\n", 40);
	assertI("%+42llo-\n", LLONG_MAX);
	assertI("% o\n", 0);
	assertI("%+ 04o\n", 40);

	printf("___________ itoa base______________\n");
	/*
	assertI();
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
