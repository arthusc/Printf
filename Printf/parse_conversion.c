/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:49:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/02 01:52:19 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

static t_conv		*parse_flags(t_printf *pf, t_conv *conv)
{
	while (ft_strchr("#0-+ ", pf->format[pf->i]))
	{
		pf->format[pf->i] == '#' ? conv->flags->sharp = 1 : 0;
		pf->format[pf->i] == '0' ? conv->flags->zero = 1 : 0;
		pf->format[pf->i] == '-' ? conv->flags->minus = 1 : 0;
		pf->format[pf->i] == '+' ? conv->flags->plus = 1 : 0;
		pf->format[pf->i] == ' ' ? conv->flags->space = 1 : 0;
		if (pf->format[pf->i] == '\0')
			break;
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

static t_conv	*parse_precision(t_printf *pf, t_conv *conv)
{
	conv->precision = atoi(&pf->format[++pf->i]);
	conv->precision > 0 ? conv->precision_set = 1 : 0 ;
	while (ft_isdigit(pf->format[pf->i]))
		pf->i++;
	if (!pf->format[pf->i]) 
		ft_error("Invalid format. (After Precision)");
	return (conv);
}

t_printf	*parse_conversion(t_printf *pf)
{
	t_conv		*conv;

	conv = init_conv();
	conv = parse_flags(&*pf, conv);
	conv = parse_minimal_width(&*pf, conv);
	conv = (pf->format[pf->i] == '.' ? parse_precision(&*pf, conv) : conv);
	while (!(ft_strchr("sdc", pf->format[pf->i])))
		pf->i += 1;
	pf->format[pf->i] == 's' ? conv_s(pf) : 0;
	pf->format[pf->i] == 'c' ? conv_c(pf) : 0;
	pf->format[pf->i] == 'd' ? conv_d(pf) : 0;
	//printf("\nprec %d\n", conv->precision);
	return (pf);
}
