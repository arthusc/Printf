/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:58:25 by achambon          #+#    #+#             */
/*   Updated: 2017/09/20 16:01:32 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	conv_u_minus_width_only(t_printf *pf, t_conv *conv, int len)
{
	if (conv->min_width && !conv->precision)
	{
		if (!(conv_u_minus_width_only2(&*pf, conv, len)))
			return (0);
		if (!(conv->flag & PLUS))
		{
			conv->before = 1;
			option_u(&*pf, conv->min_width - len, ' ', conv);
			return (0);
		}
		option_u(&*pf, conv->min_width - len, ' ', conv);
		return (0);
	}
	return (1);
}

int	conv_u_minus_width_and_prec(t_printf *pf, t_conv *conv, int len)
{
	if (conv->min_width && conv->precision)
	{
		if (conv->min_width > conv->precision)
		{
			conv->before = 0;
			if (pf->str[0] == '-')
				special_hhd_reverse_0_n_minus(&*pf, pf->str, '-');
			option_u(&*pf, conv->precision - len, '0', conv);
			while ((conv->min_width-- - conv->precision))
				buffer(&*pf, " ", 1);
			return (0);
		}
		if (conv->min_width <= conv->precision)
		{
			if (pf->str[0] == '-')
				special_hhd_reverse_0_n_minus(&*pf, pf->str, '-');
			conv->before = 3;
			option_u(&*pf, conv->precision - len, '0', conv);
			return (0);
		}
	}
	return (1);
}

int	conv_u_minus(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (!conv->min_width && !conv->precision)
		return (pf->i_buf);
	if (!(conv_u_minus_width_only(&*pf, conv, len)))
		return (pf->i_buf);
	if (!conv->min_width && conv->precision)
	{
		conv->before = 3;
		if (pf->str[0] == '-')
			special_hhd_reverse_0_n_minus(pf, pf->str, '-');
		option_u(&*pf, conv->precision - len, '0', conv);
		return (pf->i_buf);
	}
	if (!(conv_u_minus_width_and_prec(&*pf, conv, len)))
		return (pf->i_buf);
	buffer(&*pf, str, len);
	return (pf->i_buf);
}

int	conv_u_minus2(t_printf *pf, char *str, int len, t_conv *conv)
{
	if (conv->flag & MINUS)
	{
		(conv_u_minus(&*pf, conv, len, str));
		if (conv->min_width > len || conv->width_temp > len)
		{
			if (str[0] == '-')
			{
				conv->width_temp--;
				if (conv->flag & PLUS && !(conv->flag & SPACE + ZERO))
					conv->width_temp++;
			}
			return (0);
		}
		if (conv->min_width < len && !(conv->flag & SPACE)
				&& !(conv->flag & PLUS) && !conv->precision)
		{
			buffer(&*pf, str, len);
			return (0);
		}
		if (str[0] == '-' && conv->flag & MINUS)
			conv->min_width--;
	}
	return (1);
}

int	conv_u_width_only2(t_printf *pf, t_conv *conv, char *str, int len)
{
	if (conv->flag & PLUS && !(conv->flag & ZERO + MODIFIER_HH))
		conv->min_width--;
	else if (conv->flag & PLUS + ZERO && !(conv->flag & MODIFIER_HH))
	{
		option_u(&*pf, conv->min_width - len, '0', &*conv);
		return (0);
	}
	else if (conv->flag & ZERO)
	{
		if (str[0] == '-')
		{
			str[0] = '0';
			return (add_char_and_string_2_buff(&*pf, '-', str, len));
		}
		option_u(&*pf, conv->min_width - len, '0', &*conv);
		return (0);
	}
	if (conv->flag & MODIFIER_HH)
	{
		while (conv->min_width-- - len)
			buffer(&*pf, " ", 1);
		buffer(&*pf, str, len);
		return (0);
	}
	return (1);
}
