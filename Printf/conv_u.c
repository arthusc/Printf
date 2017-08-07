/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:05:40 by achambon          #+#    #+#             */
/*   Updated: 2017/08/07 20:17:15 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

void	printf_conv_u_minus(char *str, t_conv *conv, int len)
{
	if (conv->min_width > conv->precision)
	{
		option(conv->precision - len, '0', 0, str);
		conv->min_width = conv->min_width - conv->precision;
		while(conv->min_width-- > 0)
			ft_putchar(' ');
		return;
	}
	if(conv->min_width < conv->precision || conv->min_width == conv->precision)
		if(conv->min_width && conv->precision)
			option(conv->precision - len, '0', 0, str);
//	if(conv->flags->minus == 1 && !conv->precision && conv->min_width)
//		option(conv->min_width - len, ' ', 0, str);
//	if(conv->flags->minus == 1 && !conv->min_width && conv->precision)
//		option(conv->precision, '0', 0, str);
}

void	print_conv_u(char *str, t_conv *conv)
{
	int len ;

	len = ft_strlen(str);
	if (conv->flags->minus == 1)
	{
		printf_conv_u_minus(str, conv, len);
		return;
	}
		if (conv->precision && conv->min_width)
	{
		if(conv->precision > conv->min_width)
			option(conv->precision - len, '0', 0, str);
		if(conv->precision < conv->min_width)
		{
			while(conv->min_width - conv->precision > 0)
			{
				ft_putchar(' ');
				conv->min_width--;
			}
			option(conv->precision - len, '0', 0, str);
		}
	}
	if(!conv->precision && conv->min_width)
	{
		while(conv->min_width-- - len - conv->precision > 0)
			ft_putchar(' ');
		ft_putstr(str);
	}
	if(!conv->min_width && conv->precision)
	{
		option(conv->precision - len, '0', 0, str);
	}


}
void	conv_u(t_printf *pf, t_conv *conv)
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
	print_conv_u(ft_itoa_base((long long)ptr, 10), conv);
	return;
}
