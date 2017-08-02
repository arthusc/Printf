/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/02 16:09:21 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"
/*
 *gere conv_i aussi
 */

void	conv_d(t_printf *pf, t_conv *conv)
{
	char *str;
	int		len;
	va_arg(pf->ap, int);

	len = ft_strlen(str = ft_itoa((int)pf->ap));
	printf("%d\n", len);
	if (conv->flags->zero == 1 || conv->flags->minus == 0)
		while (conv->min_width-- > 1)
			ft_putchar('0');
	if (conv->flags->space == 1)
		while ( conv->min_width-- > 1)
			ft_putchar(' ');
	if (conv->flags->minus == 1)
	{
		ft_putnbr(va_arg(pf->ap, int));
		while (conv->min_width-- > 1)
			ft_putchar(' ');
		return;
	}
	ft_putnbr(va_arg(pf->ap, int));
}
