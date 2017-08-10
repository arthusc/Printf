/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:58:06 by achambon          #+#    #+#             */
/*   Updated: 2017/08/10 14:36:18 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

void	print_p(char *str)
{
	ft_putstr("0x");
	ft_putstr(str);
	return;
}


void	conv_p(t_printf *pf, t_conv *conv)
{
	void *pointer;
	char *str;
	int i;
	int len;

	i = 0;
	conv->ox = 1;
	if(!(pointer = va_arg(pf->ap, void *)))
		return (ft_putstr("0x0"));
	str = ft_itoa_base((long long)pointer, 16);
	len = ft_strlen(str);
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			str[i] = ft_tolower((int)str[i]);
		i++;
	}

	if (!(conv->min_width) && !(conv->precision))
		return (print_p(str));

	if(conv->min_width && !(conv->precision))
	{
		if (conv->flags->minus == 1)
		{
			conv->before = 1;
			option(conv->min_width - len - 2, ' ', conv, str);
			return;
		}
		if (conv->min_width <= len)
			return(print_p(str));
		conv->before = 0;
		option(conv->min_width - len - 2, ' ', conv, str);
		return;
	}

	if(!(conv->min_width) && conv->precision)
	{
		if (conv->precision <= len)
			return(print_p(str));
		conv->before = 0;
		conv->precision_set = 2;
		option(conv->precision - len, '0', conv, str);
		return;
	}

	if(conv->min_width && conv->precision)
	{
		if(conv->precision <= len && conv->min_width <= len)
		{
			print_p(str);
		}
			if(conv->precision > conv->min_width && conv->precision > len)
		{
			conv->before = 0;
			conv->precision_set = 2;
			option(conv->precision - len, '0', conv, str);
			return;
		}
		if(conv->min_width > conv->precision && conv->min_width >= len)
		{
			if(conv->flags->minus == 1)
			{
				conv->before = 1;
				option(conv->min_width - len - 2, ' ', conv, str);
				return;
			}
			conv->before = 0;
			option(conv->min_width - len - 2, ' ', conv, str);
			return;
		}
	}







	/*
	len = ft_strlen(str);
	if(conv->flags->minus == 1 && conv->precision && conv->min_width)
		conv_p_minus(pf, conv, str, len);
	if(conv->flags->minus == 0 && conv->precision && conv->min_width)
	{
		if(conv->min_width > conv->precision)
		{
			while(conv->min_width-- - len - ft_strlen("0x") > 0)
				ft_putchar(' ');
			ft_putstr("0x");
			option((conv->min_width - conv->precision) - ft_strlen("0x"),'0', 0, str);
		}
		if(conv->min_width < conv->precision || conv->min_width == conv->precision)
		{
			ft_putstr("0x");
			option(conv->precision - ft_strlen("0x"), '0', 0, str);
		}
	}

	if(!conv->precision && conv->min_width)
	{
		while(conv->min_width-- - len - conv->precision - ft_strlen("0x") > 0)
			ft_putchar(' ');
		ft_putstr("0x");
		ft_putstr(str);
	}
	if(!conv->min_width && conv->precision)
	{
		ft_putstr("0x");
		option(conv->precision - len, '0', 0, str);
	}
*/
	return;
}



