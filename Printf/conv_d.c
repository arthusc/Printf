/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/14 20:50:04 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"
/*
 *gere conv_i aussi

 NE GERE PAS LA PRECISON => x.xx = FLOAT
 */


int	conv_d_minus(t_conv *conv, int len, char *str)
{
	//	if (!conv->min_width && !conv->precision)

//JUSTE LARGEUR MINIMALE
	if (conv->min_width && !conv->precision)
	{
		if(conv->min_width < len)
		{
			return(0);
		}
			else if(conv->min_width > len)
		{
			if(conv->flag & SPACE && !(conv->flag & PLUS))
			{
				ft_putchar(' ');
				conv->min_width--;
			}
			if(conv->flag & PLUS && !(conv->flag & ZERO) && !(conv->flag & SPACE))
			{
				conv->min_width--;
				conv->before = 1;
				ft_putchar('+');
				return(option(conv->min_width - len, ' ', conv, str));
			}
			if(conv->flag & PLUS && !(conv->flag & ZERO))
			{
				conv->min_width--;
			}
			else if(conv->flag & PLUS && conv->flag & ZERO)
			{
				conv->before = 1;
				ft_putchar('+');
				return(option(conv->min_width - 1 - len, ' ', conv, str));
			}
			else if(conv->flag & ZERO)
			{
				conv->before = 1;
				return(option(conv->min_width - len, ' ', conv, str));
			}
		}
		if (!(conv->flag & PLUS))
		{
			conv->before = 1;
			return(option(conv->min_width - len, ' ', conv, str));
		}
		option(conv->min_width - len, ' ', conv, str);
		return(len + conv->min_width);
	}
//JUSTE PRECISION
	if (!conv->min_width && conv->precision)
	{
		conv->before = 3;
		if (conv->flag & SPACE && !(conv->flag & PLUS))
			ft_putchar(' ');
		if (conv->flag & PLUS)
			ft_putchar('+');
		return(option(conv->precision - len, '0', conv, str));
	}
//LARGEUR MINIMALE ET PRECISION PRESENTES
	if (conv->min_width && conv->precision)
	{
		if(conv->min_width > conv->precision)
		{
			conv->before = 0;
			if(conv->flag & SPACE && !(conv->flag & PLUS))
			{
				conv->min_width--;
				ft_putchar(' ');
			}
				if(conv->flag & PLUS)
			{
				conv->min_width--;
				ft_putchar('+');
			}
			option(conv->precision - len, '0', conv, str);
			while((conv->min_width-- - conv->precision))
				ft_putchar(' ');
			return(0);
		}
		if (conv->min_width <= conv->precision)
		{
			if(conv->flag & PLUS)
			{
				conv->min_width--;
				ft_putchar('+');
			}
			if(conv->flag & SPACE && !(conv->flag & PLUS))
			{
				conv->min_width--;
				ft_putchar(' ');
			}
			conv->before = 3;
			option(conv->precision - len, '0', conv, str);
			return(0);
		}
	}
	ft_putstr(str);
	return(0);

}
int		conv_d(t_printf *pf, t_conv *conv)
{
	int		len;
	int		apint;
	char	*str;

	conv->flag & MODIFIER_H ? apint = va_arg(pf->ap, short) : apint == 1;
	conv->flag & MODIFIER_HH ? apint = va_arg(pf->ap, char) : apint == 1;
	conv->flag & MODIFIER_L ? apint = va_arg(pf->ap, long) : apint == 1;
	conv->flag & MODIFIER_LL ? apint = va_arg(pf->ap, long long) : apint == 1;
	conv->flag & MODIFIER_Z ? apint = va_arg(pf->ap, size_t) : apint == 1;
	conv->flag & MODIFIER_J ? apint = va_arg(pf->ap, uintmax_t) : apint == 1;
	!(conv->flag & MODIFIER_H) && !(conv->flag & MODIFIER_HH) && !(conv->flag & MODIFIER_L) && !(conv->flag & MODIFIER_LL) && !(conv->flag & MODIFIER_Z) && !(conv->flag & MODIFIER_J) ? apint = va_arg(pf->ap, int) : apint == 1;
	if(apint == 1)
		ft_error("error_conv_d\n");
	len = ft_strlen(str = ft_itoa(apint));
//	if (str[0] == '-' && conv->flag & MODIFIER_HH)
//		str[0] = '0';
	if (!conv->min_width && !conv->precision)
	{
		if(conv->flag & SPACE && !(conv->flag & PLUS))
			ft_putchar(' ');
		if(conv->flag & PLUS)
			ft_putchar('+');
		ft_putstr(str);
		return(0);
	}
int a = conv->min_width;
	if (conv->flag & MINUS)
	{
		(conv_d_minus(conv, len, str));
		if (a > len)
		{
			return (0);
		}
		if(conv->min_width < len && !(conv->flag & SPACE) && !(conv->flag & PLUS) && !conv->precision)
		{
			ft_putstr(str);
			return(0);
		}
	}
//	if(str[0] == '-')
//	{
//		conv->min_width--;
//	}
//JUSTE LARGEUR MINIMALE
	if (conv->min_width && !conv->precision)
	{
		if(conv->min_width < len)
		{
			if(conv->flag & PLUS)
			{
				ft_putchar('+');
				ft_putstr(str);
				return(0);
			}
			if(conv->flag & SPACE)
			{
				ft_putchar(' ');
				ft_putstr(str);
				return(0);
			}
			ft_putstr(str);
			return(0);
		}
		else if(conv->min_width >= len)
		{
			if(conv->flag & SPACE && !(conv->flag & PLUS))
			{
				ft_putchar(' ');
				conv->min_width--;
			}
			if(conv->flag & PLUS && !(conv->flag & ZERO))
				conv->min_width--;
			else if(conv->flag & PLUS && conv->flag & ZERO)
			{
				ft_putchar('+');
				return(option(conv->min_width - 1 - len, '0', conv, str));
			}
			else if(conv->flag & ZERO)
				return(option(conv->min_width - len, '0', conv, str));
			return(option(conv->min_width - len, ' ', conv, str));
		}
	}
//JUSTE PRECISION
	if (!conv->min_width && conv->precision)
	{
		conv->before = 3;
		if (conv->flag & SPACE && !(conv->flag & PLUS))
			ft_putchar(' ');
		if (conv->flag & PLUS)
			ft_putchar('+');
		return(option(conv->precision - len, '0', conv, str));
	}
//LARGEUR MINIMALE ET PRECISION PRESENTES
	if (conv->min_width && conv->precision)
	{
		if(conv->min_width > conv->precision)
		{
			conv->before = 0;
			if(conv->flag & SPACE && !(conv->flag & PLUS))
			{
				conv->min_width--;
				ft_putchar(' ');
			}
			if(conv->flag & PLUS)
				conv->min_width--;
			while((conv->min_width-- - conv->precision))
				ft_putchar(' ');
			if(conv->flag & PLUS)
			{
				conv->before = 3;
				ft_putchar('+');
			}
			option(conv->precision - len, '0', conv, str);
			return(0);
		}
		if (conv->min_width <= conv->precision)
		{
			if(conv->flag & PLUS)
			{
				conv->min_width--;
				ft_putchar('+');
			}
			if(conv->flag & SPACE && !(conv->flag & PLUS))
			{
				conv->min_width--;
				ft_putchar(' ');
			}
			conv->before = 3;
			option(conv->precision - len, '0', conv, str);
			return(0);
		}
	}
	ft_putstr(str);
	return(0);
}
