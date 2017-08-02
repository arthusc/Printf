/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/02 14:57:25 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

void	conv_c(t_printf *pf, t_conv *conv)
{
	if (conv->flags->zero == 1)
		while(conv->min_width-- > 1)
			ft_putchar('0');
	if (conv->flags->space == 1)
		while(conv->min_width-- > 1)
			ft_putchar(' ');
	if (conv->flags->minus == 1)
	{
		ft_putchar(va_arg(pf->ap, unsigned));
		while(conv->min_width-- > 1)
			ft_putchar(' ');
		return;
	}
	ft_putchar(va_arg(pf->ap, unsigned));
}

