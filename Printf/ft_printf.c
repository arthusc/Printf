/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:18 by mbriffau          #+#    #+#             */
/*   Updated: 2017/07/30 17:29:33 by mbriffau         ###   ########.fr       */
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
	va_list 	ap;
	t_printf	*pf;	
	int		before_conv_size;

	before_conv_size = 0;
	va_start(ap, format);
	if (!(pf = (t_printf *)malloc(sizeof(t_printf *))))
		return (-1);
	pf->ap = &ap;
	pf->format = format;
	/*
	 * stdarg permet de gerer quand il y a une 
	 * variete de nombre d'argument possibles, de types pouvant etre 
	 * differents
	  */
	while (*pf->format)
	{
		if (*pf->format == '%')
		{
			if (before_conv_size > 0)
			{
				pf_nputstr(pf->format - before_conv_size, before_conv_size);
				before_conv_size = 0;
			}
			conversion_specifier(pf);
		}
		pf->format++;
		before_conv_size++;
	}
	if (before_conv_size > 0)
			pf_nputstr(pf->format - before_conv_size, before_conv_size);
	va_end(*pf->ap);
	return (0);
}


/*
 * Quand la precision est trop grande, printf comble avec des 0
 * Le flag 0 est ignore lorsque le flag - est present 
 * *
 */
