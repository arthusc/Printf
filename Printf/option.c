/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:35:35 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/10 12:35:16 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	option(int n, char c, t_conv *conv, char *s)
{
	int		i;
	char	tab[n + 1];

	if (conv->before && s)
	{
		if(conv->ox == 1)
			ft_putstr("0x");
		ft_putstr(s);
	}
		i = 0;
	tab[n] = '\0';
	if (conv->precision_set == 2)
	{
		ft_putstr("0x");
		conv->ox = 0;
	}
		while (i < n)
		tab[i++] = c;
	write(1, tab, n);
	
	if (conv->before == 0 && s)
	{
		if(conv->ox == 1)
			ft_putstr("0x");
		ft_putstr(s);
	}
		return (n - i);
}
