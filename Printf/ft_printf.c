/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:18 by mbriffau          #+#    #+#             */
/*   Updated: 2017/07/29 22:59:48 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

int		pf_nputstr(char *str, int size)
{
	write(1, str, size);
	return (0);
}

int		ft_printf(char *format, ...)
{
	va_list 	ap;
	t_printf	*pf;	
	int		before_conv_size;

	before_conv_size = 0;
	va_start(ap, format);
	if (!(pf = (t_printf *)malloc(sizeof(t_printf *))))
		return (-1);
	pf->ap = &ap;
	/*
	 * stdarg permet de gerer quand il y a une 
	 * variete de nombre d'argument possibles, de types pouvant etre 
	 * differents
	  */
	while (*format)
	{
		if (*format == '%')
		{
			if (before_conv_size > 0)
			{
				before_conv_size = pf_nputstr(format - before_conv_size, before_conv_size);
			}
			format = conversion_specifier(++format, pf);
		}
		format++;
		before_conv_size++;
	}
	if (before_conv_size > 0)
			before_conv_size = pf_nputstr(format - before_conv_size, before_conv_size);
	va_end(*pf->ap);
	return (0);
}


/*
 * Quand la precision est trop grande, printf comble avec des 0
 * Le flag 0 est ignore lorsque le flag - est present 
 * *
 */
