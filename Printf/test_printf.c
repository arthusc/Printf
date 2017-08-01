/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:43:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/01 15:49:06 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int 	main(int ac, char **av)
{
	if (ac)

	printf("abcd%s\n", " 1");
	printf("efg%-15s\n", " 1");
	printf("->%c\n", 'a');
	printf("->%s\n", "test_s");
	printf("->%d\n", 42);
	printf("->%-10s\n", "Salut");
	return (0);
}
