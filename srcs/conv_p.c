/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:58:06 by achambon          #+#    #+#             */
/*   Updated: 2017/09/20 16:22:19 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"


t_conv	option_p(t_printf *pf, int n, char c, t_conv *conv)
{
	int		i;
	char	tab[n + 1];
	int 	len;

	len = ft_strlen(pf->str);
	i = 0;
	tab[n] = '\0';
	if (!n)
		return(*conv);
	while (i < n)
		tab[i++] = c;
	buffer(&*pf, tab, n);
	
	return (*conv);
}

int		print_p(t_printf *pf, int len, char *str)
{
	buffer(&*pf, "0x", 2);
	buffer(&*pf, str, len);
	return (0);
}

int		going_for_option(t_printf *pf, t_conv *conv)
{
	buffer(&*pf, "0x", 2);
		if(conv->precision > pf->len)
			option_p(&*pf, conv->precision - pf->len, '0', conv);
	buffer(&*pf, pf->str, pf->len);	
	return (pf->i_buf);
}

int		conv_p_minus(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (!conv->min_width && !conv->precision)
			return(pf->i_buf);
	if (conv->min_width && !conv->precision)
	{
		if(conv->min_width < len)
		{
			return(0);
		 }
		print_p(&*pf, len, str);
		option_p(&*pf, conv->min_width - len - 2, ' ', conv);
		return(0);
	}
	if (!conv->min_width && conv->precision)
	{
		buffer(&*pf, "0x", 2);
		if(conv->precision > len)
		{
			(option_p(&*pf, conv->precision - len - 2, '0', conv));
		}
		return(pf->i_buf);
	}
	if (conv->min_width && conv->precision)
	{
		buffer(&*pf, "0x", 2);
		if(conv->min_width > conv->precision)
		{
			buffer(&*pf, str, len);
			if(conv->precision > len)
				option_p(&*pf, conv->min_width - conv->precision - 2, ' ', conv);
			return(0);
		}
		if (conv->min_width <= conv->precision)
		{
			if(conv->precision > len)
				option_p(&*pf, conv->precision - len, '0', conv);
		}
	}
	buffer(&*pf, str, len);
	return(0);
}

int		conv_p2(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (conv->min_width && !conv->precision)
	{
		if(conv->min_width < len)
			return (print_p(&*pf, len, str));
		if(conv->min_width >= len)
		{
			if(conv->flag & ZERO)
			{
				buffer(&*pf, "0x", 2);
				option_p(&*pf, conv->min_width - len - 2, '0', conv);
				buffer(&*pf, str, len);
				return(0);
			}
			option_p(&*pf, conv->min_width - len - 2, ' ', conv);
			print_p(&*pf, len, str);
			return(0);
		}
	}
	if (!conv->min_width && conv->precision && conv->flag & MINUS)
	{
		buffer(&*pf, str, len);
		return(0);
	}
	return (1);
}
int		conv_p(t_printf *pf, t_conv *conv)
{
	void *pointer;
	char *str;
	int i;
	int len;
	
	i = 0;
	conv->ox = 1;
	if(!(pointer = va_arg(pf->ap, void *)))
	{
		buffer(&*pf, "0x0", 3);
		return(pf->i_buf);
	}
	str = ft_itoa_base((long long)pointer, 16);
	pf->str = str;
	len = ft_strlen(str);
	pf->len = len;
	while (str[i++])
		(ft_isalpha(str[i])) ? str[i] = ft_tolower((int)str[i]): 0;
	if (!(conv->min_width) && !(conv->precision))
	{
		print_p(pf, len ,str);
		return (pf->i_buf);
	}
	if (conv->flag & MINUS)
	{
		(conv_p_minus(&*pf, conv, len, str));
		if (conv->precision && conv->min_width)
			return (pf->i_buf);
	}
	if (!(conv_p2(&*pf, conv, len, str)))
		return (pf->i_buf);
	if (!conv->min_width && conv->precision && !(conv->flag & MINUS))
		return (going_for_option(&*pf, conv));
	if (conv->min_width && conv->precision)
		return (going_for_option(&*pf, conv));
	buffer(&*pf, str, len);	
	return(0);
}
