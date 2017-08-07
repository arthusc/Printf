/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 23:29:04 by achambon          #+#    #+#             */
/*   Updated: 2017/08/07 23:05:22 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(int ac, char **av)
{
	// // size_t a = 123456;
	// // uintmax_t max = 789456123;
	// // unsigned char uchar = 65; 
	if (ac)
	// {
	// 	 ac = ac;
	// }
	// int c = 10;
	// int *d = &c;
	ft_printf("abcd%s\n", " 1");
	ft_printf("efg%-15s\n", " 1");
	ft_printf("->%-10c\n", 'a');
	ft_printf("->%s\n", "test_s");
	ft_printf("->%.2d\n", 42);
	ft_printf("->%-10s\n", "Salut");
	ft_printf("->%06S\n", L"ひらがな");
	ft_printf("->%C\n", L'ひ');
//	ft_printf("m :%lo\n", 30);
//	ft_printf("m :% 15zo\n", a);
//	ft_printf("m :%jo\n", max);
//	ft_printf("m :%010o\n", 60);
//	ft_printf("m :%hho\n", uchar);
	// ft_printf("m :%p\n", 50);
	// printf("t :%p\n", 50);
	// ft_printf("m :%10p\n", d);
	// printf("t :%10p\n", d);
	// ft_printf("m :%10p\n", d);
	// printf("t :%10p\n", d);
	// ft_printf("m :%010p\n", d);
	// printf("t :%010p\n", d);
	// ft_printf("m :%p\n", d);
	// printf("t :%p\n", d);
	// ft_printf("m :%0.5p\n", d);
	// printf("t :%0.5p\n", d);
	// ft_printf("m :%-10.5p\n", d);
	// printf("t :%-10.5p\n", d);
	// ft_printf("m :%-010.5p\n", d);
	// printf("t :%-010.5p\n", d);

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