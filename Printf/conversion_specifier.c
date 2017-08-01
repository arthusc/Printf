/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:49:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/01 15:24:22 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

t_printf	*conversion_specifier(t_printf *pf)
{
	pf->i++;
	while ((pf->format[pf->i + pf->too_far_format]) != 's' && (pf->format[pf->i + pf->too_far_format]) != 'd' && (pf->format[pf->i + pf->too_far_format]) != 'c')
	{
		pf->too_far_format += 1;
	}
	if ((pf->format[pf->i + pf->too_far_format]) == 's')
	{
		conv_s(pf);
		pf->i++;
	}
	if ((pf->format[pf->i + pf->too_far_format]) == 'c')
	{
		conv_c(pf);
		pf->i++;
	}
	if ((pf->format[pf->i +pf->too_far_format]) == 'd')
	{
		conv_d(pf);
		pf->i++;
	}
	pf->format += pf->too_far_format;
	pf->too_far_format = 0;
	return (pf);
}
