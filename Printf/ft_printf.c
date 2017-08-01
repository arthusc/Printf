/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:18 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/01 23:56:47 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

static int	print_until(char *s, int i, int c)
{
	while (s[i] != 0 && s[i] != c)
		write(1, &s[i++], 1);
	return (i);
}

int		ft_printf(char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	va_start(pf.ap, format);
	pf.format = format;
	while (pf.format[pf.i] != 0)
	{
		pf.i = print_until(pf.format, pf.i, '%');
		if (pf.format[pf.i] == '%')
			pf.i++;
		if (pf.format != 0)
			parse_conversion(&pf);
		pf.i++;
		pf.i = print_until(pf.format, pf.i, '%');
	}
	va_end(pf.ap);
	return (0);
}

/*
 * Quand la precision est trop grande, printf comble avec des 0
 * Le flag 0 est ignore lorsque le flag - est present 
 * *
 */
