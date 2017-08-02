/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/02 18:36:45 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"
/*
 *gere conv_i aussi

 NE GERE PAS LA PRECISON => x.xx = FLOAT
 */

void	conv_d_l(t_printf *pf, t_conv *conv)
{
	int		len;
	int		apint;
	char	*str;

	if (!(apint = va_arg(pf->ap, long)))
		ft_error("error_conv_d\n");
	len = ft_strlen(str = ft_itoa(apint));
	if (conv->flags->zero == 1 && conv->flags->minus == 0)
		while (conv->min_width-- > 0 + len)
			ft_putchar('0');
	if (conv->flags->space == 1)
		while ( conv->min_width-- > 0 + len)
			ft_putchar(' ');
	if (conv->flags->minus == 1)
	{
		ft_putnbr(apint);
		while (conv->min_width-- > 0 + len)
			ft_putchar(' ');
		return;
	}
	ft_putnbr(apint);
}

void	conv_d_h(t_printf *pf, t_conv *conv)
{
	int		len;
	int		apint;
	char	*str;

	if (!(apint = va_arg(pf->ap, short)))
		ft_error("error_conv_d\n");
	len = ft_strlen(str = ft_itoa(apint));
	if (conv->flags->zero == 1 && conv->flags->minus == 0)
		while (conv->min_width-- > 0 + len)
			ft_putchar('0');
	if (conv->flags->space == 1)
		while ( conv->min_width-- > 0 + len)
			ft_putchar(' ');
	if (conv->flags->minus == 1)
	{
		ft_putnbr(apint);
		while (conv->min_width-- > 0 + len)
			ft_putchar(' ');
		return;
	}
	ft_putnbr(apint);
}

void	conv_d(t_printf *pf, t_conv *conv)
{
	int		len;
	int		apint;
	char	*str;

	if(conv->modif == 'h')
		conv_d_h(pf, conv);
	if(conv->modif == 'l')
		conv_d_l(pf, conv);
	if(!(apint = va_arg(pf->ap, int)))
		ft_error("error_conv_d\n");
	len = ft_strlen(str = ft_itoa(apint));
	if (conv->flags->zero == 1 && conv->flags->minus == 0)
		while (conv->min_width-- > 0 + len)
			ft_putchar('0');
	if (conv->flags->space == 1)
		while ( conv->min_width-- > 0 + len)
			ft_putchar(' ');
	if (conv->flags->minus == 1)
	{
		ft_putnbr(apint);
		while (conv->min_width-- > 0 + len)
			ft_putchar(' ');
		return;
	}
	ft_putnbr(apint);
}
