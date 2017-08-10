/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/10 22:57:27 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"
/*
 *gere conv_i aussi

 NE GERE PAS LA PRECISON => x.xx = FLOAT
 */

void	ft_putnbrlong(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n && n > 9)
		ft_putnbrlong(n / 10);
	ft_putchar(n % 10 + '0');
}

void	conv_d_l(t_printf *pf, t_conv *conv)
{
	int			len;
	uintmax_t		apint;
	char		*str;
	
	if (!(apint = va_arg(pf->ap, uintmax_t)))
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
	ft_putnbrlong(apint);
}

void	conv_d_h(t_printf *pf, t_conv *conv)
{
	int		len;
	int16_t	apint;
	char	*str;

	if (!(apint = va_arg(pf->ap, uintmax_t)))
		ft_error("error_conv_d\n");
	len = ft_strlen(str = ft_itoa(apint));
	if (conv->flags->zero == 1 && conv->flags->minus == 0)
		while (conv->min_width-- - len >= 0)
			ft_putchar('0');
	if (conv->flags->space == 1)
		while ( conv->min_width-- -len >= 0)
			ft_putchar(' ');
	if (conv->flags->minus == 1)
	{
		ft_putnbr(apint);
		while (conv->min_width-- - len >= 0)
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
	

	if(conv->modif == 'h' || conv->modif == 'l')
	{
		conv->modif == 'h' ? conv_d_h(pf, conv) : 0;
		conv->modif == 'l' ? conv_d_l(pf, conv) : 0;
		return;
	}
	if(!(apint = va_arg(pf->ap, int)))
		ft_error("error_conv_d\n");
	len = ft_strlen(str = ft_itoa(apint));
	
	if (!conv->min_width && !conv->precision)
	{
		if(conv->flags->space && !conv->flags->plus)
			ft_putchar(' ');
		if(conv->flags->plus)
			ft_putchar('+');
		ft_putstr(str);
		return;
	}

	if (conv->min_width && !conv->precision)
	{
		if(conv->min_width < len)
		{
			if(conv->flags->plus)
			{
				ft_putchar('+');
				ft_putstr(str);
				return;
			}
			if(conv->flags->space)
			{
				ft_putchar(' ');
				ft_putstr(str);
				return;
			}
		}
		else
		{
			if (conv->flags->zero)
			if(conv->flags->space)
			{
				ft_putchar(' ');
				conv->min_width--;
			}
			option(conv->min_width - len, '0', conv, str);
			return;
		}
		}

		ft_putstr(str);
	}
	if (!conv->min_width && conv->precision)

	if (conv->min_width && conv->precision)


	return;
/*

	if (conv->flags->zero && !conv->flags->minus)
		conv->min_width = option(conv->min_width - len, '0', conv, 0);

	if (conv->flags->space == 1)
	{
		if(conv->precision && !conv->min_width)
		{
			ft_putchar(' ');
			
		}
		while ( conv->min_width-- > 0 + len)
			ft_putchar(' ');
	}
	if (conv->flags->minus == 1)
	{
		if(conv->precision_set > 0)
			while ((conv->precision-- - len) >= 1)
			{
				ft_putchar('0');
				conv->min_width = conv->min_width - 1;
			}
		ft_putnbr(apint);
		while (conv->min_width-- > 0 + len)
			ft_putchar(' ');
		return;
	}
	
	if (conv->min_width && !conv->precision)
	{
		option(conv->min_width - len, ' ', conv, str);
		return;
	}

	if(conv->min_width && conv->precision)
	{
		if (conv->flags->plus)
			conv->min_width--;
		while (conv->min_width-- - conv->precision)
			ft_putchar(' ');
		if (conv->flags->plus)
			ft_putchar('+');
		while(conv->precision-- - len)
			ft_putchar('0');
		ft_putstr(str);
		return;
	}


	while (conv->min_width-- > 0 + conv->precision)
			ft_putchar(' ');
	if(conv->precision_set > 0)
		while ((conv->precision-- - len) >= 1)
			ft_putchar('0');

	ft_putnbr(apint);*/
}
