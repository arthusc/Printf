/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 23:29:04 by achambon          #+#    #+#             */
/*   Updated: 2017/08/07 11:15:54 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(int ac, char **av)
{
	size_t a = 123456;
	uintmax_t max = 789456123;
	unsigned char uchar = 65; 
	if (ac)

	// ft_printf("abcd%s\n", " 1");
	// ft_printf("efg%-15s\n", " 1");
	// ft_printf("->%-10c\n", 'a');
	// ft_printf("->%s\n", "test_s");
	// ft_printf("->%.2d\n", 42);
	// ft_printf("->%-10s\n", "Salut");
	// ft_printf("->%ls\n", L"ひらがな");
	// ft_printf("->%llc\n", L'ひ');
	ft_printf("m :%lo\n", 30);
	ft_printf("m :% 15zo\n", a);
	ft_printf("m :%jo\n", max);
	ft_printf("m :%010o\n", 60);
	ft_printf("m :%hho\n", uchar);
	return (0);
}

// int		main(int ac, char **av)
// {
// 	if (ac)

// 	ft_printf("abcd%s\n", " 1");
// 	ft_printf("efg%-15s\n", " 1");
// 	ft_printf("efg%#15s\n", " 1");
// 	ft_printf("efg%+15s\n", " 1");
// 	ft_printf("efg% 15s\n", " 1");
// 	ft_printf("efg%015s\n", " 1");
// 	ft_printf("->%c\n", 'a');
// 	ft_printf("->%s\n", "test_s");
// 	ft_printf("->%d\n", 42);
// 	ft_printf("->%-10s\n", "Salut");
// 	return (0);
// }