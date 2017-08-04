/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:07:37 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/04 16:36:43 by mbriffau         ###   ########.fr       */
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
// static int		count_wchars(t_conversion *conv, wchar_t *wstr, int *size)
// {
// 	int		i;
// 	int		add;
// 	int		total;

// 	i = 0;
// 	add = 0;
// 	total = 0;
// 	while (i < *size)
// 	{
// 		if (wstr[i] <= 0x7F)
// 			add = 1;
// 		else if (wstr[i] <= 0x7FF)
// 			add = 2;
// 		else if (wstr[i] <= 0xFFFF)
// 			add = 3;
// 		else if (wstr[i] <= 0x10FFFF)
// 			add = 4;
// 		if (conv->prec_set && conv->type == 's'
// 			&& (total + add) > conv->precision)
// 			break ;
// 		total += add;
// 		i++;
// 	}
// 	*size = i;
// 	return (total);
// }

int		count_wchars(t_conv *conv, wchar_t *wstr, int size)
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
	void *apstring;
	int len;
	if (conv->modif == 'l')
		len = ft_strlen(apstring = va_arg(pf->ap, wchar_t *));
	else
		len = ft_strlen(apstring = va_arg(pf->ap, unsigned char *));
//	printf("%d\n", len);
	if (conv->flags->zero == 1 && conv->flags->minus == 0)
		while (conv->min_width-- > 0 + len)
			ft_putchar('0');
	if (conv->flags->space == 1)
		while (conv->min_width-- > 0 + len)
			ft_putchar(' ');
	if (conv->flags->minus == 1)
	{
		if (conv->modif == 'l')
			print_wstring(conv, apstring, ft_wstrlen(apstring));//////////////
		else
			ft_putstr(apstring);
		while (conv->min_width-- > 0 + len)
			ft_putchar(' ');
		return;
	}
	if (conv->modif == 'l')
			print_wstring(conv, apstring, ft_wstrlen(apstring));//////////////
	else
		ft_putstr(apstring);
}
	//char *str;
	// int		moins = 0;

	//str = va_arg(ap, char *);
	// if (ft_strchr("-+#0 ", *format))
	// {
	// 	format++;
	// 	moins = 1;
	// }
	// if (moins && ft_isdigit(*format))
	// {
	// 		minimal_ara = atoi(format);
	// }
	// str = option_minus("tout le monde", 5);
	// while (s[i])
	// {
	// 	i++;
	// }
	// write(1, s, i);
//	ft_putstr((char *)s);
//}
