/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:49:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/02 00:55:39 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

static t_conv		*parse_flags(t_printf *pf, t_conv *conv)
{
	while (ft_strchr("#0-+ ", pf->format[pf->i]))
	{
		if (pf->format[pf->i] == '#')
			conv->flags->sharp = 1;
		else if (pf->format[pf->i] == '0')
			conv->flags->zero = 1;
		else if (pf->format[pf->i] == '-')
			conv->flags->minus = 1;
		else if (pf->format[pf->i] == '+')
			conv->flags->plus = 1;
		else if (pf->format[pf->i] == ' ')
			conv->flags->space = 1;
		else if (pf->format[pf->i] == '\0')
			break ;
		else
			ft_error("error_parse_flags");
		pf->i++;
	}
	return (conv);
}

static t_conv	*parse_minimal_width(t_printf *pf, t_conv *conv)
{
	conv->min_width = atoi(&pf->format[pf->i]);
	while (ft_isdigit(pf->format[pf->i]))
		pf->i++;
	if (!(pf->format))
		ft_error("error_parse_minimal_width");
	return (conv);
}

t_printf	*parse_conversion(t_printf *pf)
{
	t_conv		*conv;

	//write(1, "x", 1);
	conv = init_conv();
	conv = parse_flags(&*pf, conv);
	conv = parse_minimal_width(&*pf, conv);
	while (!(ft_strchr("sdc", pf->format[pf->i])))
	{
		pf->i += 1;
	}
	if ((pf->format[pf->i + pf->too_far_format]) == 's')
		conv_s(pf);
	if ((pf->format[pf->i + pf->too_far_format]) == 'c')
		conv_c(pf);
	if ((pf->format[pf->i +pf->too_far_format]) == 'd')
		conv_d(pf);
	pf->format += pf->too_far_format;
	pf->too_far_format = 0;
	printf("\nmin %d\n", conv->min_width);
	return (pf);
}


// t_printf	*parse_conversion(t_printf *pf)
// {
// 	t_conv		*conv;
// 	ft_bzero(&conv, sizeof(t_conv));
// 	while ((pf->format[pf->i + pf->too_far_format]) != 's'
// 		&& (pf->format[pf->i + pf->too_far_format]) != 'd'
// 		&& (pf->format[pf->i + pf->too_far_format]) != 'c')
// 	{
// 		pf->too_far_format += 1;
// 	}
// 	if ((pf->format[pf->i + pf->too_far_format]) == 's')
// 		conv_s(pf);
// 	if ((pf->format[pf->i + pf->too_far_format]) == 'c')
// 		conv_c(pf);
// 	if ((pf->format[pf->i +pf->too_far_format]) == 'd')
// 		conv_d(pf);
// 	pf->format += pf->too_far_format;
// 	pf->too_far_format = 0;
// 	return (pf);
// }
