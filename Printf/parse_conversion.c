/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:49:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/02 17:33:36 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

static t_conv		*parse_flags(t_printf *pf, t_conv *conv)
{
	while (ft_strchr("#0-+ ", pf->format[pf->i]))
	{
		pf->format[pf->i] == '#' ? conv->flags->sharp = 1 : 0;
		/* # The result is converted to an ‘‘alternative form’’. For o conversion, it increases the precision, if and only if necessary, to force the first digit of the result to be a zero (if the value and precision are both 0, a single 0 is printed). For x (or X) conversion, a nonzero result has 0x (or 0X) prefixed to it. For a, A, e, E, f, F, g, and G conversions, the result of converting a floating-point number always contains a decimal-point character, even if no digits follow it. (Normally, a decimal-point character appears in the result of these conversions only if a digit follows it.) For g and G conversions, trailing zeros are not removed from the result. For other conversions, the behavior is undefined. */
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

static t_conv	*parse_modifier(t_printf *pf, t_conv *conv)
{
	if (!(ft_strchr("hljz", pf->format[pf->i])))
		return (conv);
	if (ft_strncmp(&pf->format[pf->i], "hh", 2) == 0)
	{
		conv->modif = 'H';
		pf->i += 2;
		return (conv);
	}
	if (ft_strncmp(&pf->format[pf->i], "ll", 2) == 0)
	{
		conv->modif = 'L';
		pf->i += 2;
		return (conv);
	}
	pf->format[pf->i] == 'h' ? conv-> modif = 'h': 0;
	pf->format[pf->i] == 'l' ? conv-> modif = 'l': 0;
	pf->format[pf->i] == 'j' ? conv-> modif = 'j': 0;
	pf->format[pf->i] == 'z' ? conv-> modif = 'z': 0;
	pf->i++;
	return (conv);
}

t_printf	*parse_conversion(t_printf *pf)
{
	t_conv		*conv;

	conv = init_conv();
	conv = parse_flags(&*pf, conv);
	conv = parse_minimal_width(&*pf, conv);
	conv = (pf->format[pf->i] == '.' ? parse_precision(&*pf, conv) : conv);
	conv = parse_modifier(&*pf, conv);
	while (!(ft_strchr("sdc", pf->format[pf->i])))
		pf->i += 1;
	pf->format[pf->i] == 's' ? conv_s(pf, conv) : 0;
	pf->format[pf->i] == 'c' ? conv_c(pf, conv) : 0;
	pf->format[pf->i] == 'd' ? conv_d(pf, conv) : 0;
	if (conv->modif != '0')
		printf("\nmodif %c\n", conv->modif);
	return (pf);
}
