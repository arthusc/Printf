/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 23:29:04 by achambon          #+#    #+#             */
/*   Updated: 2017/08/04 15:43:35 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(int ac, char **av)
{
	if (ac)

	ft_printf("abcd%s\n", " 1");
	ft_printf("efg%-15s\n", " 1");
	ft_printf("->%-10c\n", 'a');
	ft_printf("->%s\n", "test_s");
	ft_printf("->%.2d\n", 42);
	ft_printf("->%-10s\n", "Salut");
	ft_printf("->%ls\n", L"ひらがな");
	ft_printf("->%lc\n", L'ひ');
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