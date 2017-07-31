/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 23:29:04 by achambon          #+#    #+#             */
/*   Updated: 2017/07/31 23:43:54 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

int		main(int ac, char **av)
{
	if (ac)

	ft_printf("abcd%s\n", " 1");
	ft_printf("abcd%-15s\n", " 1");
	ft_printf("->%c\n", 'a');
	printf("->%s\n", "test_s");
	ft_printf("->%d\n", 42);
	ft_printf("->%-10s\n", "Salut");
	return (0);
}
