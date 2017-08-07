/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:35:35 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/06 18:27:39 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "includes/ft_printf.h"

void		conv_o(t_printf *pf, t_conv *conv)
{
	unsigned int pointer_x;
	char *str;
	int i;
	int len;

	i = 0;
	pointer_x = 0;
	if (conv->modif == 'l')
	{
		pointer_x = ((unsigned long int)pointer_x);
		pointer_x = va_arg(pf->ap, uintmax_t);
	}
	else if (conv->modif == 'L')
	{
		pointer_x = ((unsigned long long int)pointer_x);
		pointer_x = va_arg(pf->ap, uintmax_t);
	}
	else if (conv->modif == 'h')
	{
		pointer_x = ((uint16_t)pointer_x);
		pointer_x = va_arg(pf->ap, uintmax_t);
	}
	else if (conv->modif == 'H')
	{
		pointer_x = ((uint8_t)pointer_x);
		pointer_x = va_arg(pf->ap, uintmax_t);
	}
	else if (conv->modif == 'z')
	{
		pointer_x = ((size_t)pointer_x);
		pointer_x = va_arg(pf->ap, uintmax_t);
	}
	else if (conv->modif == 'j')
	{
		pointer_x = ((uintmax_t)pointer_x);
		pointer_x = va_arg(pf->ap, uintmax_t);
	}
	else
		pointer_x = va_arg(pf->ap, unsigned int);

	str = ft_itoa_base((long long)pointer_x, 8);
	len = ft_strlen(str = ft_itoa(pointer_x));

	if (conv->flags->zero == 1 && conv->flags->minus == 0)
		while (conv->min_width-- > 0 + len)
			ft_putchar('0');
	ft_putstr(str);
	return;
}