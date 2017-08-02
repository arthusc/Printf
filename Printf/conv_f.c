/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 18:17:08 by achambon          #+#    #+#             */
/*   Updated: 2017/08/02 18:35:08 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

void	conv_f_L(t_printf *pf, t_conv *conv)
{
	int		len;
	int		apint;
	char	*str;

	if (!(apint = va_arg(pf->ap, long double)))
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

void	conv_f(t_printf *pf, t_conv *conv)
{
	int		len;
	int		apint;
	char	*str;


	if(conv->modif == 'L')
		conv_f_L(pf, conv);
	if(!(apint = va_arg(pf->ap, double)))
		ft_error("error_conv_f\n");
	len = ft_strlen(str = ft_itoa(apint));
	if (conv->flags->zero == 1 && conv->flags->minus == 0)
		while (conv->min_width-- > 0 + len)
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

/* Need add precision
 * */
