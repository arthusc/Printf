/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:18 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/01 15:25:44 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

void		pf_nputstr(char *str, int size)
{
	write(1, str, size);
	return;
}

int		ft_printf(char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	va_start(pf.ap, format);
	pf.format = format;
	while (pf.format[pf.i] != 0)
	{
		if (pf.format[pf.i] == '%')
		{
			if (pf.before_conv_size > 0)
			{
				pf_nputstr(&pf.format[pf.i - pf.before_conv_size], pf.before_conv_size);
				pf.before_conv_size = 0;
			}
			conversion_specifier(&pf);
		}
		if (pf.format == 0)
		{
			break;
		}
		pf.i++;
		pf.before_conv_size++;
	}
	if (pf.before_conv_size > 0)
		pf_nputstr(&pf.format[pf.i - pf.before_conv_size], pf.before_conv_size);
	va_end(pf.ap);
	return (0);
}


/*
 * Quand la precision est trop grande, printf comble avec des 0
 * Le flag 0 est ignore lorsque le flag - est present 
 * *
 */
