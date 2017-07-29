/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:49:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/07/29 22:56:26 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

char	*conversion_specifier(char *format, t_printf *pf)
{
	int count;

	count  = 0;
	// while (ft_strchr("sSpdDioOuUxXcC", *format))
	// {
	// 	format++;
	// 	count++;
	// }
	//format++;
	//if((value = option(format)) != 0)
	//{
	//write(1, "okey\n", 5);
	//ft_putstr		(pf_str_option(ft_itoa(va_arg(ap, int)), ' ', value));
	//}

	if (*format == 's')
	{
		conv_s(pf, (format - count));
		format++;
	}
	else if (*format == 'c')
	{
		conv_c(pf);
		format++;
	}
	else if (*format == 'd')
	{
		conv_d(pf, format);
		format++;
	}
	return (&*format);
}
