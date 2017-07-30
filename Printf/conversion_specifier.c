/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:49:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/07/30 15:33:25 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

t_printf	*conversion_specifier(t_printf *pf)
{
	int count;

	count  = 0;
	pf->format++;
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

	if (*pf->format == 's')
	{
		conv_s(pf);
		pf->format++;
	}
	else if (*pf->format == 'c')
	{
		conv_c(pf);
		pf->format++;
	}
	else if (*pf->format == 'd')
	{
		conv_d(pf);
		pf->format++;
	}
	return (pf);
}
