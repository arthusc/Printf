/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/03 02:16:41 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

static void	print_wint(wint_t wint)
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
	if (conv->flags->zero == 1 && conv->flags->minus == 0)
		while(conv->min_width-- > 1)
			ft_putchar('0');
	if (conv->flags->space == 1)
		while(conv->min_width-- > 1)
			ft_putchar(' ');
	if (conv->flags->minus == 1)
	{
		if (conv->modif == 'l')
			print_wint(va_arg(pf->ap, wint_t));	
		else
			ft_putchar(va_arg(pf->ap, unsigned));
		while(conv->min_width-- > 1)
				ft_putchar(' ');
		return;
	}
	if (conv->modif == 'l')
		print_wint(va_arg(pf->ap, wint_t));
	else
		ft_putchar(va_arg(pf->ap, unsigned));
}
