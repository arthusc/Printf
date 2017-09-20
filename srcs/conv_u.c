/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:05:40 by achambon          #+#    #+#             */
/*   Updated: 2017/09/20 15:58:08 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		conv_u_width_only(t_printf *pf, t_conv *conv, char *str, int len)
{
	if (conv->min_width && !conv->precision)
	{
		if (conv->min_width < len)
		{
			buffer(&*pf, str, len);
			return (0);
		}
		if (conv->min_width >= len || conv->width_temp >= len)
		{
			if (conv->flag & SPACE && !(conv->flag & PLUS))
			{
				if (conv->flag & ZERO)
					minwidth_decr_add_char_2_buff(&*pf, '0', &*conv);
				else
					minwidth_decr_add_char_2_buff(&*pf, ' ', &*conv);
			}
			if (!(conv_u_width_only2(&*pf, conv, str, len)))
				return (0);
			(conv->flag & PLUS && !(conv->flag & ZERO)
			&& !(conv->flag & SPACE)) ? conv->before = 4 : 0;
			option_u(&*pf, conv->min_width - len, ' ', &*conv);
			return (0);
		}
	}
	return (1);
}

int		conv_u_width_and_prec2(t_printf *pf, t_conv *conv, char *str, int len)
{
	(conv->flag & PLUS && !(conv->flag & ZERO + MODIFIER_HH))
	? conv->min_width-- : 0;
	if (conv->flag & PLUS + ZERO && !(conv->flag & MODIFIER_HH))
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

int		conv_u_width_and_prec(t_printf *pf, t_conv *conv, char *str, int len)
{
	if (conv->min_width && !conv->precision)
	{
		if (conv->min_width < len)
		{
			buffer(&*pf, str, len);
			return (0);
		}
		if (conv->min_width >= len || conv->width_temp >= len)
		{
			if (conv->flag & SPACE && !(conv->flag & PLUS))
			{
				if (conv->flag & ZERO)
					minwidth_decr_add_char_2_buff(&*pf, '0', &*conv);
				else
					minwidth_decr_add_char_2_buff(&*pf, ' ', &*conv);
			}
			if (!(conv_u_width_and_prec(&*pf, conv, str, len)))
				return (0);
			(conv->flag & PLUS && !(conv->flag & ZERO)
			&& !(conv->flag & SPACE)) ? conv->before = 4 : 0;
			option_u(&*pf, conv->min_width - len, ' ', &*conv);
			return (0);
		}
	}
	return (1);
}

int		print_conv_u(t_printf *pf, char *str, t_conv *conv)
{
	int len;

	len = ft_strlen(str);
	pf->str = str;
	conv->width_temp = conv->min_width;
	if (!(conv_u_minus2(&*pf, str, len, conv)))
		return (pf->i_buf);
	if (!(conv_u_width_only(&*pf, conv, pf->str, len)))
		return (pf->i_buf);
	if (!conv->min_width && conv->precision && conv->flag & MINUS)
		return (0);
	if (!conv->min_width && conv->precision && !(conv->flag & MINUS))
	{
		conv->before = 3;
		option_u(&*pf, conv->precision - len, '0', &*conv);
		return (pf->i_buf);
	}
	if (!(conv_u_width_and_prec(&*pf, conv, str, len)))
		return (pf->i_buf);
	buffer(&*pf, str, len);
	return (0);
}

void	conv_u(t_printf *pf, t_conv *conv)
{
	unsigned long int ptr;

	ptr = 0;
	if (conv->flag & MODIFIER_L)
		ptr = (unsigned long int)ptr;
	else if (conv->flag & MODIFIER_LL)
		ptr = (unsigned long long int)ptr;
	else if (conv->flag & MODIFIER_H)
		ptr = (uint16_t)ptr;
	else if (conv->flag & MODIFIER_HH)
		ptr = (uint8_t)ptr;
	else if (conv->flag & MODIFIER_Z)
		ptr = (size_t)ptr;
	else if (conv->flag & MODIFIER_J)
		ptr = (uintmax_t)ptr;
	else
	{
		ptr = (unsigned int)ptr;
		ptr = va_arg(pf->ap, unsigned int);
		print_conv_u(pf, ft_itoa_pf(ptr), conv);
		return ;
	}
	ptr = va_arg(pf->ap, uintmax_t);
	print_conv_u(pf, ft_itoa_pf((uintmax_t)ptr), conv);
	return ;
}
