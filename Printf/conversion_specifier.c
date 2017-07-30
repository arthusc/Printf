/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:49:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/07/31 00:51:53 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

t_printf	*conversion_specifier(t_printf *pf)
{
	int count;
	//write(1, &*pf->format, 1);

	char	*ret_chr;
	ret_chr = 0;
	count  = 0;
	pf->format++;
	pf->too_far_format = 0;
	printf("count1 :%d\n", pf->too_far_format);
	while ((*pf->format +pf->too_far_format) != 's' && (*pf->format +pf->too_far_format) != 'd' && (*pf->format +pf->too_far_format) != 'c')
	{
		pf->too_far_format += 1;
	}
	printf("count :%d\n", pf->too_far_format);
	// if (ret_chr == 0)
	// {
	// 	ft_error("error_conversion_specifier");
	// }
	//write(1, (&*pf->format + pf->too_far_format), 1);
	if ((*pf->format + pf->too_far_format) == 's')
	{
		//write(1, &*pf->format, 1);
		conv_s(pf);
		pf->format++;
	}
	else if ((*pf->format + pf->too_far_format) == 'c')
	{
		conv_c(pf);
		pf->format++;
	}
	else if ((*pf->format +pf->too_far_format) == 's')
	{
		conv_d(pf);
		pf->format++;
	}
	pf->format += pf->too_far_format;
	return (pf);
}
