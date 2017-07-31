/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:18 by mbriffau          #+#    #+#             */
/*   Updated: 2017/07/31 20:18:10 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

t_printf	*init_t_printf(va_list *ap, char *format)
{
	t_printf	*pf;

	if (!(pf = (t_printf *)malloc(sizeof(t_printf))))
		return (0);	
	pf->minimum_field_width = 0;
	pf->too_far_format = 0;
	pf->ap = ap;
	pf->format = format;
	pf->i = 0;
	return (pf);
}

void		pf_nputstr(char *str, int size)
{
	write(1, str, size);
	return;
}

int		ft_printf(char *format, ...)
{
	va_list 	ap;
	int		before_conv_size;
	t_printf	*pf;

	va_start(ap, format);
	pf = init_t_printf(&ap, format);
	before_conv_size = 0;
	
	/*
	 * stdarg permet de gerer quand il y a une 
	 * variete de nombre d'argument possibles, de types pouvant etre 
	 * differents
	  */
	while (pf->format[pf->i])
	{
		if (pf->format[pf->i] == '%')
		{
			if (before_conv_size > 0)
			{
				pf_nputstr(&pf->format[pf->i - before_conv_size], before_conv_size);
				before_conv_size = 0;
			}
			conversion_specifier(pf);
		}
		pf->i++;
		before_conv_size++;
	}
	if (before_conv_size > 0)
			pf_nputstr(&pf->format[pf->i - before_conv_size], before_conv_size);
	va_end(*pf->ap);
	return (0);
}


/*
 * Quand la precision est trop grande, printf comble avec des 0
 * Le flag 0 est ignore lorsque le flag - est present 
 * *
 */
