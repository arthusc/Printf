/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:43:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/07 16:15:36 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <stdint.h>
int 	main(int ac, char **av)
{

	size_t a = 123456;
	uintmax_t max = 789456123;
	unsigned char uchar = 65;
	if (ac)

	printf("t :%O\n", 30);
	printf("t :%15zo\n", a);
	printf("t :%jo\n", max);
	printf("t :%010o\n", 60);
	printf("t :%hho\n", uchar);
	// printf("abcd%s\n", " 2");
	// printf("efg%-15s\n", " 1");
	// printf("->%lc\n", 'a');
	// printf("->%s\n", "test_s");
	// printf("->%d\n", 42);
	// printf("->%-10s\n", "Salut");
	// printf("->%ls\n", L"ひらがな");
	// printf("->%lc\n", L'ひ');
	return (0);
}
