/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:07:37 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/07 23:06:05 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

int		ft_wstrlen(wchar_t *s)
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
		(wstr[i] <= 0x7F) ? add = 1 : 0;
		(wstr[i] <= 0x7FF) ? add = 2 : 0;
		(wstr[i] <= 0xFFFF) ? add = 3 : 0;
		(wstr[i] <= 0x10FFFF) ? add = 4 : 0;
		if (conv->precision_set && conv->type == 's'
			&& (total + add) > conv->precision)
			break ;
		total += add;
		i++;
	}
	size = i;
	return (total);
}
static void	print_wstring(t_conv *conv, wchar_t *wstr, int size)
{
	int i = 0;

	count_wchars(conv, wstr, size);
	while (i < size)
	{
		print_wint(wstr[i]);
		i++;		
	}
}

void	conv_s(t_printf *pf, t_conv *conv)
{
	void *str;
	int len;

	conv->modif == 'l' ? (len = ft_strlen(str = va_arg(pf->ap, wchar_t *))) :
	(len = ft_strlen(str = va_arg(pf->ap, unsigned char *)));
	if (conv->flags->zero && !conv->flags->minus)
		conv->min_width = option(conv->min_width - len, '0', 0, 0);
	else if (conv->flags->space)
		conv->min_width = option(conv->min_width - len, ' ', 0, 0);
	else if (conv->flags->minus)
	{
		conv->modif == 'l' ? print_wstring(conv, str, ft_wstrlen(str)) : ft_putstr(str);
		conv->min_width = option(conv->min_width - len, ' ', 0, 0);
		return;
	}
	if (conv->modif == 'l')
			print_wstring(conv, str, ft_wstrlen(str));
	else
		ft_putstr(str);
}
