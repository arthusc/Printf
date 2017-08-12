/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/11 15:19:35 by achambon         ###   ########.fr       */
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
	return;
}

void	conv_d_h(t_printf *pf, t_conv *conv)
{
	return;
}

int	conv_d_minus(t_conv *conv, int len, char *str)
{
	//	if (!conv->min_width && !conv->precision)


	if (conv->min_width && !conv->precision)
	{
		if(conv->min_width < len)
			return(0);
		else if(conv->min_width > len)
		{
			if(conv->flag & SPACE)
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

	if (!conv->min_width && conv->precision)
	{
		conv->before = 3;
		if (conv->flag & SPACE)
			ft_putchar(' ');
		if (conv->flag & PLUS)
			ft_putchar('+');
		return(option(conv->precision - len, '0', conv, str));
	}
	if (conv->min_width && conv->precision)
	{
		if(conv->min_width > conv->precision)
		{
			conv->before = 0;
			if(conv->flag & SPACE)
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
		if (conv->min_width < conv->precision)
		{
			if(conv->flag & PLUS)
			{
				conv->min_width--;
				ft_putchar('+');
			}
			if(conv->flag & SPACE)
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


	if(conv->modif == 'h' || conv->modif == 'l')
	{
		conv->modif == 'h' ? conv_d_h(pf, conv) : 0;
		conv->modif == 'l' ? conv_d_l(pf, conv) : 0;
		return(0);
	}
	if(!(apint = va_arg(pf->ap, int)))
		ft_error("error_conv_d\n");
	len = ft_strlen(str = ft_itoa(apint));
	if (!conv->min_width && !conv->precision)
	{
		if(conv->flag & SPACE && !(conv->flag & PLUS))
			ft_putchar(' ');
		if(conv->flag & PLUS)
			ft_putchar('+');
		ft_putstr(str);
		return(0);
	}

	if (conv->flag & MINUS)
	{
		(conv_d_minus(conv, len, str));
		if (conv->min_width > len)
			return (0);
		if(conv->min_width < len && !(conv->flag & SPACE) && !(conv->flag & PLUS) && !conv->precision)
		{
			ft_putstr(str);
			return(0);
		}
	}

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
		}
		else if(conv->min_width >= len)
		{
			if(conv->flag & SPACE)
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
			{
				return(option(conv->min_width - len, '0', conv, str));
			}
		}
	}

	//	ft_putstr(str);
	//	if (!conv->min_width && conv->precision)

	//	if (conv->min_width && conv->precision)


	return(0);
}
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
