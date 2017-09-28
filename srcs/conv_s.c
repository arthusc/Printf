/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:07:37 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 17:14:59 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_wstrlen(wchar_t *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int		count_wchars(t_conv *conv, wchar_t *wstr, int size)
{
	int		i;
	int		add;
	int		total;

	i = 0;
	add = 0;
	total = 0;
	while (i < size)
	{
		if (wstr[i] <= 0x7F)
			add = 1;
		else if (wstr[i] <= 0x7FF)
			add = 2;
		else if (wstr[i] <= 0xFFFF)
			add = 3;
		else if (wstr[i] <= 0x10FFFF)
			add = 4;
		if (conv->precision_set && conv->flag & TYPE_S
			&& (total + add) > conv->precision)
			break ;
		total += add;
		i++;
	}
	size = i;
	return (total);
}

static void		print_wstring(t_printf *pf, wchar_t *wstr, int n)
{
	while (n--)
		print_wint(&*pf, *wstr++);
}

static void			conv_s_base(t_printf *pf, t_conv *conv, void *str, int len)
{
	str = va_arg(pf->ap, unsigned char *);
	if (str == NULL)
		(str = ft_strdup("(null)"));
	len = ft_strlen(str);
	if (conv->flag & PRECISION && conv->precision < len)
		len = conv->precision;/////
	if (conv->min_width > len && (conv->flag & ZERO) && !(conv->flag & MINUS))
		option_char(&*pf, len, '0', &*conv);
	else if (conv->min_width > len && (conv->flag & SPACE || !(conv->flag & MINUS)))
		option_char(&*pf, len, ' ', &*conv);
	buffer(&*pf, str, len);
	(conv->min_width > len && conv->flag & MINUS)
	? option_char(&*pf, len, ' ', &*conv) : 0;
}

static int		size_wchar(wchar_t *s, int max)
{
	int add = 0;
	int  i = 0;

	while (add < max)
	{
		if (s[i] <= 0x7F)
			add += 1;
		else if (s[i] <= 0x7FF)
			add += 2;
		else if (s[i] <= 0xFFFF)
			add += 3;
		else if (s[i] <= 0x10FFFF)
			add += 4;
		if (add <= max)
			i++;
	}
	return (i);
}

void			conv_s(t_printf *pf, t_conv *conv)
{
	void	*str;
	int		len;
	int 	width = 0;

	str = NULL;
	len = 0;
	if (conv->flag & MODIFIER_F)
	{
		conv_s_file(&*pf);
		return ;
	}
	if (conv->flag & MODIFIER_L)
	{
		str = va_arg(pf->ap, wchar_t *);
		!(MB_CUR_MAX > 1) ? exit (-1) : 0;
		if (str == NULL)
		{
			(str = ft_strdup("(null)"));
			conv_s_base(&*pf, &*conv, str, len);
		}
		else
		{
			len = count_wchars(conv, str, ft_wstrlen(str));
			if (conv->flag & PRECISION && conv->precision < len)
				len = conv->precision;/////
			if (conv->min_width > len && (conv->flag & ZERO) && !(conv->flag & MINUS))
				option_char(&*pf, len, '0', &*conv);
			else if (conv->min_width > len && (conv->flag & SPACE || !(conv->flag & MINUS)))
				option_char(&*pf, len, ' ', &*conv);
			if (conv->flag & PRECISION && conv->precision < ft_wstrlen(str))
				width = size_wchar(str, conv->precision);
			else
				width = ft_wstrlen(str);
			print_wstring(&*pf, str, width);
			(conv->min_width > len && conv->flag & MINUS)
			? option_char(&*pf, len, ' ', &*conv) : 0;
		}
	}
	else
		conv_s_base(&*pf, &*conv, str, len);
}

/*
 ** si la precision est trop petit, print la preci
 ** donc besoin de len;
 ** len = count_Wchar
 */
