/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:35:35 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/07 12:58:53 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "includes/ft_printf.h"

void print_conv_o(char *str, t_conv *conv)
{
	int len ;
	
	len = ft_strlen(str);
	if (conv->flags->zero == 1 && conv->flags->minus == 0)
		while (conv->min_width-- > 0 + len)
			ft_putchar('0');
	else if (conv->flags->space == 1 || conv->min_width > 0)
		while ( conv->min_width-- > 0 + len)
			ft_putchar(' ');
	ft_putstr(str);
} 

void		conv_o(t_printf *pf, t_conv *conv)
{
	unsigned int ptr;

	ptr = 0;
	conv->modif == 'l' ? ptr = (unsigned long int)ptr : 0 ;
	conv->modif == 'L' ? ptr = (unsigned long long int)ptr : 0;
	conv->modif == 'h' ? ptr = (uint16_t)ptr : 0;
	conv->modif == 'H' ? ptr = (uint8_t)ptr : 0;
	conv->modif == 'z' ? ptr = (size_t)ptr : 0;
	conv->modif == 'j' ? ptr = (uintmax_t)ptr : 0;
	ptr = va_arg(pf->ap, uintmax_t);
	print_conv_o(ft_itoa_base((long long)ptr, 8), conv);
	return;
}