/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:35:35 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/07 22:53:56 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	option(int n, char c, int before, char *s)
{
	int		i;
	char	tab[n + 1];

	if (before && s)
		ft_putstr(s);
	i = 0;
	tab[n] = '\0';
	while (i < n)
		tab[i++] = c;
	write(1, tab, n);
	if (before == 0 && s)
		ft_putstr(s);
	return (n - i);
}
