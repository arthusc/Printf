/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/11 00:44:29 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_wint(wint_t wint)
{
	char	str[4];

	if (wint <= 0x7F)
		write(1, (unsigned*)&wint, 1);
	else if (wint <= 0x7FF)
	{
		str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = ((wint & 0x003F) + 0x80);
		write(1, str, 2);
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wint & 0x003F) + 0x80);
		write(1, str, 3);
	}
	else if (wint <= 0x10FFFF)
	{
		str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wint & 0x003F) + 0x80);
		write(1, str, 4);
	}
}

void	conv_c(t_printf *pf, t_conv *conv)
{
	(conv->flag & ZERO && !(conv->flag & MINUS)) ?
	(conv->min_width = option(conv->min_width, '0', conv, 0)) : 0;
	conv->flag & SPACE ?
	(conv->min_width = option(conv->min_width, ' ', conv, 0)) : 0;
	conv->modif == 'l' ? print_wint(va_arg(pf->ap, wint_t)) :
	ft_putchar(va_arg(pf->ap, unsigned));
	conv->flag & MINUS ?
	(conv->min_width = option(conv->min_width, ' ', conv, 0)) : 0;
	return ;
}
