/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:21:31 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/21 20:20:09 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test(void)
{
	int ft;
	int i;
	printf("___________ 0 ______________\n");
	ft = ft_printf("%hho\n", -1);
	i = printf("%hho\n", -1);
	printf("%d - %d\n", ft, i);

	i = printf("%hd-\n", (short)(SHRT_MAX + 5));
	ft = ft_printf("%hd-\n", (SHRT_MAX + 5));
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
