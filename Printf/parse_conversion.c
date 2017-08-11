/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:49:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/11 13:20:58 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

static t_conv		*parse_flags(t_printf *pf, t_conv *conv)
{
	while (ft_strchr("#0-+ ", pf->format[pf->i]))
	{ 	
		pf->format[pf->i] == '-' ? conv->flag += MINUS : 0;
		pf->format[pf->i] == '+' ? conv->flag += PLUS : 0;
		pf->format[pf->i] == '#' ? conv->flag += SHARP : 0;
		pf->format[pf->i] == '0' ? conv->flag += ZERO : 0;
		pf->format[pf->i] == ' ' ? conv->flag += SPACE : 0;
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
	
	if (ft_strchr("CSDUOX", pf->format[pf->i]))
		conv-> modif = 'l';
	else if (ft_strchr("hljz", pf->format[pf->i]))
	{
		conv->modif = *ft_strchr("hljz", pf->format[pf->i++]);
		if (pf->format[pf->i] == conv->modif)
		{
			conv->modif = ft_toupper(conv->modif);
			pf->i++;
		}
	}
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
	(!pf->format[pf->i]) ? ft_error("error_format_type") : 0;
	conv->type = pf->format[pf->i];
	while (!(ft_strchr("cCsSdDipxXuUoO", conv->type)))
		pf->i += 1;
	(ft_strchr("dDi", conv->type)) ? conv_d(pf, conv) : 0;
	conv->type == 's' || conv->type == 'S' ? conv_s(pf, conv) : 0;
	conv->type == 'c' || conv->type == 'C' ? conv_c(pf, conv) : 0;
	conv->type == 'p' ? conv_p(pf, conv) : 0;
	conv->type == 'x' ? conv_x(pf, conv, 'x') : 0;
	conv->type == 'X' ? conv_x(pf, conv, 'X') : 0;
	conv->type == 'o' || conv->type == 'O'? conv_o(pf, conv) : 0;
	conv->type == 'u' ? conv_u(pf, conv) : 0;
	return (pf);
}
