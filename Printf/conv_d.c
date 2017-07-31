/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/07/31 22:03:01 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"
/*
 *gere conv_i aussi
 */

void	conv_d(t_printf *pf)
{
	// int value;

//value = 0;
//	//if((value = option(format)) != 0)
// {
//		write(1, "okey\n", 5);
//		ft_putstr(pf_str_option(ft_itoa(va_arg(ap, int)), ' ', value));
//	}
	//else
	printf("%d\n", va_arg(pf->ap, int));
}
