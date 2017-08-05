/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:35:35 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/05 20:16:08 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "includes/ft_printf.h"

void		conv_o(t_printf *pf, t_conv *conv)
{
	unsigned int pointer_x;
	//char *str;
	int i;

	i = 0;
	pointer_x = 0;
	if (conv->modif == 'l')
	{
		pointer_x = ((unsigned long int)pointer_x);
		pointer_x = va_arg(pf->ap, unsigned long int);
	}
	else
		pointer_x = va_arg(pf->ap, unsigned int);
	//str = ft_itoa_base((long long)pointer_x, 8);
	ft_putstr(ft_itoa_base((long long)pointer_x, 8));
	return;
}