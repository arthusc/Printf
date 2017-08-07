/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:58:06 by achambon          #+#    #+#             */
/*   Updated: 2017/08/07 19:40:37 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

void	conv_p_minus(t_printf *pf, t_conv *conv, char *str, int len)
{
	ft_putstr("0x");
	if (conv->min_width > conv->precision)
	{
		option(conv->precision - ft_strlen("0x"),, '0', 0, str);
		conv->min_width = conv->min_width - conv->precision - 2;
		while(conv->min_width-- > 0)
			ft_putchar(' ');
	}
	if(conv->min_width < conv->precision || conv->min_width == conv->precision)
		if(conv->min_width && conv->precision)
			option(conv->precision - ft_strlen("0x"), '0', 0, str);
	if(conv->flags->minus == 1 && !conv->precision && conv->min_width)
	{
		ft_putstr("0x");
		option(conv->min_width - len - ft_strlen("0x"), ' ', 1, str);
	}
	if(conv->flags->minus == 1 && !conv->min_width && conv->precision)
	{
		ft_putstr("0x");
		option(conv->precision - ft_strlen("0x"), '0', 0, str);
	}
}

void	conv_p(t_printf *pf, t_conv *conv)
{
	void *pointer;
	char *str;
	int i;
	int len;

	i = 0;
	if(!(pointer = va_arg(pf->ap, void *)))
		return(ft_putstr("0x0"));
	str = ft_itoa_base((long long)pointer, 16);

	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			str[i] = ft_tolower((int)str[i]);
		}
		i++;
	}
	len = ft_strlen(str);

	if(conv->flags->minus == 1 && conv->precision && conv->min_width)
		conv_p_minus(pf, conv, str, len);

	if(conv->flags->minus == 0 && conv->precision && conv->min_width)
	{
		if(conv->min_width > conv->precision)
		{
			while(conv->min_width-- - conv->precision - ft_strlen("0x") > 0)
				ft_putchar(' ');
			ft_putstr("0x");
			option(conv->precision -  ft_strlen("0x"),'0', 0, str);
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

	return;
}



