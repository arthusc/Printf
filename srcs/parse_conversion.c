/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:49:25 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/26 17:06:39 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_conv		*parse_flags(t_conv *conv, char *s, int *i)
{
	while (ft_strchr("#0-+ ", s[*i]))
	{
		s[*i] == '-' && !(conv->flag & MINUS) ? conv->flag += MINUS : 0;
		s[*i] == '+' && !(conv->flag & PLUS) ? conv->flag += PLUS : 0;
		s[*i] == '#' && !(conv->flag & SHARP) ? conv->flag += SHARP : 0;
		s[*i] == '0' && !(conv->flag & ZERO) ? conv->flag += ZERO : 0;
		s[*i] == ' ' && !(conv->flag & SPACE) ? conv->flag += SPACE : 0;
		if (s[*i] == '\0')
			break ;
		*i += 1;
	}
	return (conv);
}

static t_conv		*parse_precision(t_printf *pf, t_conv *conv)
{
	!(conv->flag & PRECISION) ? conv->flag += PRECISION : 0;
	conv->precision = ft_atoi(&pf->format[++pf->i]);
	conv->precision > 0 ? conv->precision_set = 1 : 0;//delete
	while (ft_isdigit(pf->format[pf->i]))
		pf->i++;
	if (!pf->format[pf->i])
		ft_error_pf(INFO, "Invalid format. (After Precision)");
	return (conv);
}

static int			overwrite_modifier(int *f)
{
	if (*f & 0x7E0)
	{
		if (*f & MODIFIER_H)
			*f -= MODIFIER_H;
		else if (*f & MODIFIER_HH)
			*f -= MODIFIER_HH;
		else if (*f & MODIFIER_L)
			*f -= MODIFIER_L;
		else if (*f & MODIFIER_LL)
			*f -= MODIFIER_LL;
		else if (*f & MODIFIER_J)
			*f -= MODIFIER_J;
		else if (*f & MODIFIER_Z)
			*f -= MODIFIER_Z;
	}
	return (*f);
}

static void		parse_modifier(int *i, int *f, char *s)
{
	if (ft_strchr("X", s[*i]))
		!(*f & MODIFIER_X) ? (*f += MODIFIER_X) : 0;
	else if (ft_strchr("F", s[*i]))
		!(*f & MODIFIER_F) ? (*f += MODIFIER_F) && *i++ : 0;
	while (ft_strchr("hljzCSDUO", s[*i]))
	{
		overwrite_modifier(&*f);
		if (ft_strchr("CSDUO", s[*i]))
		{
			*f += MODIFIER_L;
			break;
		}
		if (s[*i] == 'h')
			(s[*i + 1] == 'h') ? (*f += MODIFIER_HH) && (*i += 1) 
		: (*f += MODIFIER_HH);
		else if (s[*i] == 'l')
			(s[*i + 1] == 'l') ? (*f += MODIFIER_LL) && (*i += 1)
		: (*f += MODIFIER_L);
		(s[*i] == 'j') ? (*f += MODIFIER_J) : 0;
		(s[*i] == 'z') ? (*f += MODIFIER_Z) : 0;
		*i += 1;
	}
}

static int			parse_type(char c)
{
	int ret;

	ret = 0;
	c == 'd' || c == 'D' || c == 'i' ? ret = TYPE_D : 0;
	c == 's' || c == 'S' ? ret = TYPE_S : 0;
	c == 'c' || c == 'C' ? ret = TYPE_C : 0;
	c == 'x' || c == 'X' ? ret = TYPE_X : 0;
	c == 'o' || c == 'O' ? ret = TYPE_O : 0;
	c == 'p' ? ret = TYPE_P : 0;
	c == 'u' || c == 'U' ? ret = TYPE_U : 0;
	c == 'b' ? ret = TYPE_B : 0;
	c == '%' ? ret = TYPE_PERCENT : 0;
	return (ret);
}

t_printf			*parse_conversion(t_printf *pf)
{
	t_conv		*conv;

	conv = init_conv();
	parse_flags(&*conv, pf->format, &pf->i);
	conv->min_width = ft_atoi(&pf->format[pf->i]);
	while (ft_isdigit(pf->format[pf->i]))
		pf->i++;
	if (!(pf->format))
		ft_error_pf(INFO, "error_parse_minimal_width");
	(pf->format[pf->i] == '.' ? parse_precision(&*pf, &*conv) : 0);
	parse_modifier(&pf->i, &conv->flag, pf->format);
	(!pf->format[pf->i]) ? ft_error_pf(INFO, "error_format_type") : 0;
	conv->flag += parse_type(pf->format[pf->i]);
	conversion_specifier(&*pf, &*conv);
	return (pf);
}
// static t_conv		*parse_flags(t_conv *conv, char *s, int *i)
// {
// 	while (ft_strchr("#0-+ ", s[*i]))
// 	{
// 		s[*i] == '-' && !(conv->flag & MINUS) ? conv->flag += MINUS : 0;
// 		s[*i] == '+' && !(conv->flag & PLUS) ? conv->flag += PLUS : 0;
// 		s[*i] == '#' && !(conv->flag & SHARP) ? conv->flag += SHARP : 0;
// 		s[*i] == '0' && !(conv->flag & ZERO) ? conv->flag += ZERO : 0;
// 		s[*i] == ' ' && !(conv->flag & SPACE) ? conv->flag += SPACE : 0;
// 		if (s[*i] == '\0')
// 			break ;
// 		*i += 1;
// 	}
// 	return (conv);
// }

// static t_conv		*parse_precision(t_printf *pf, t_conv *conv)
// {
// 	conv->precision_tick = 1;//delete
// 	!(conv->flag & PRECISION) ? conv->flag += PRECISION : 0;
// 	conv->precision = ft_atoi(&pf->format[++pf->i]);
// 	conv->precision > 0 ? conv->precision_set = 1 : 0;//delete
// 	while (ft_isdigit(pf->format[pf->i]))
// 		pf->i++;
// 	if (!pf->format[pf->i])
// 		ft_error_pf(INFO, "Invalid format. (After Precision)");
// 	return (conv);
// }

// static int			overwrite_modifier(int *f)
// {
// 	if (*f & 0x7E0)
// 	{
// 		if (*f & MODIFIER_H)
// 			*f -= MODIFIER_H;
// 		else if (*f & MODIFIER_HH)
// 			*f -= MODIFIER_HH;
// 		else if (*f & MODIFIER_L)
// 			*f -= MODIFIER_L;
// 		else if (*f & MODIFIER_LL)
// 			*f -= MODIFIER_LL;
// 		else if (*f & MODIFIER_J)
// 			*f -= MODIFIER_J;
// 		else if (*f & MODIFIER_Z)
// 			*f -= MODIFIER_Z;
// 	}
// 	return (*f);
// }

// static void		parse_modifier(int *i, int *f, char *s)
// {
// 	if (ft_strchr("X", s[*i]))
// 		!(*f & MODIFIER_X) ? (*f += MODIFIER_X) : 0;
// 	else if (ft_strchr("F", s[*i]))
// 		!(*f & MODIFIER_F) ? (*f += MODIFIER_F) && *i++ : 0;
// 	while (ft_strchr("hljzCSDUO", s[*i]))
// 	{
// 		overwrite_modifier(&*f);
// 		if (ft_strchr("CSDUO", s[*i]))
// 		{
// 			*f += MODIFIER_L;
// 			break;
// 		}
// 		(s[*i] == 'h') && (s[*i + 1] != 'h') ? (*f += MODIFIER_H) : 0;
// 		(s[*i] == 'h') && (s[*i + 1] == 'h') ? (*f += MODIFIER_HH) && (*i++) : 0;
// 		(s[*i] == 'l') && (s[*i + 1] != 'l') ? (*f += MODIFIER_L) : 0;
// 		(s[*i] == 'l') && (s[*i + 1] == 'l') ? (*f += MODIFIER_LL) && (*i++) : 0;
// 		(s[*i] == 'j') ? (*f += MODIFIER_J) : 0;
// 		(s[*i] == 'z') ? (*f += MODIFIER_Z) : 0;
// 		*i += 1;
// 	}
// }

// static int			parse_type(char c)
// {
// 	int ret;

// 	ret = 0;
// 	c == 'd' || c == 'D' || c == 'i' ? ret = TYPE_D : 0;
// 	c == 's' || c == 'S' ? ret = TYPE_S : 0;
// 	c == 'c' || c == 'C' ? ret = TYPE_C : 0;
// 	c == 'x' || c == 'X' ? ret = TYPE_X : 0;
// 	c == 'o' || c == 'O' ? ret = TYPE_O : 0;
// 	c == 'p' ? ret = TYPE_P : 0;
// 	c == 'u' || c == 'U' ? ret = TYPE_U : 0;
// 	c == 'b' ? ret = TYPE_B : 0;
// 	c == '%' ? ret = TYPE_PERCENT : 0;
// 	return (ret);
// }

// t_printf			*parse_conversion(t_printf *pf)
// {
// 	t_conv		*conv;

// 	conv = init_conv();
// 	parse_flags(&*conv, pf->format, &pf->i);
// 	conv->min_width = ft_atoi(&pf->format[pf->i]);
// 	while (ft_isdigit(pf->format[pf->i]))
// 		pf->i++;
// 	if (!(pf->format))
// 		ft_error_pf(INFO, "error_parse_minimal_width");
// 	(pf->format[pf->i] == '.' ? parse_precision(&*pf, &*conv) : 0);
// 	parse_modifier(&pf->i, &conv->flag, pf->format);
// 	(!pf->format[pf->i]) ? ft_error_pf(INFO, "error_format_type") : 0;
// 	conv->flag += parse_type(pf->format[pf->i]);
// 	conversion_specifier(&*pf, &*conv);
// 	return (pf);
// }
// static t_conv		*parse_flags(t_conv *conv, char *s, int *i)
// {
// 	while (ft_strchr("#0-+ ", s[*i]))
// 	{
// 		s[*i] == '-' && !(conv->flag & MINUS) ? conv->flag += MINUS : 0;
// 		s[*i] == '+' && !(conv->flag & PLUS) ? conv->flag += PLUS : 0;
// 		s[*i] == '#' && !(conv->flag & SHARP) ? conv->flag += SHARP : 0;
// 		s[*i] == '0' && !(conv->flag & ZERO) ? conv->flag += ZERO : 0;
// 		s[*i] == ' ' && !(conv->flag & SPACE) ? conv->flag += SPACE : 0;
// 		if (s[*i] == '\0')
// 			break ;
// 		*i += 1;
// 	}
// 	return (conv);
// }

// static t_conv		*parse_precision(t_printf *pf, t_conv *conv)
// {
// 	conv->precision_tick = 1;//delete
// 	!(conv->flag & PRECISION) ? conv->flag += PRECISION : 0;
// 	conv->precision = ft_atoi(&pf->format[++pf->i]);
// 	conv->precision > 0 ? conv->precision_set = 1 : 0;//delete
// 	while (ft_isdigit(pf->format[pf->i]))
// 		pf->i++;
// 	if (!pf->format[pf->i])
// 		ft_error_pf(INFO, "Invalid format. (After Precision)");
// 	return (conv);
// }

// static int			overwrite_modifier(int *f)
// {
// 	if (*f & 0x7E0)
// 	{
// 		if (*f & MODIFIER_H)
// 			*f -= MODIFIER_H;
// 		else if (*f & MODIFIER_HH)
// 			*f -= MODIFIER_HH;
// 		else if (*f & MODIFIER_L)
// 			*f -= MODIFIER_L;
// 		else if (*f & MODIFIER_LL)
// 			*f -= MODIFIER_LL;
// 		else if (*f & MODIFIER_J)
// 			*f -= MODIFIER_J;
// 		else if (*f & MODIFIER_Z)
// 			*f -= MODIFIER_Z;
// 	}
// 	return (*f);
// }

// static void		parse_modifier(int *i, int *f, char *s)
// {
// 	if (ft_strchr("X", s[*i]))
// 		!(*f & MODIFIER_X) ? (*f += MODIFIER_X) : 0;
// 	else if (ft_strchr("F", s[*i]))
// 		!(*f & MODIFIER_F) ? (*f += MODIFIER_F) && *i++ : 0;
// 	while (ft_strchr("hljzCSDUO", s[*i]))
// 	{
// 		overwrite_modifier(&*f);
// 		if (ft_strchr("CSDUO", s[*i]))
// 		{
// 			*f += MODIFIER_L;
// 			break;
// 		}
// 		(s[*i] == 'h') && (s[*i + 1] != 'h') ? (*f += MODIFIER_H) : 0;
// 		(s[*i] == 'h') && (s[*i + 1] == 'h') ? (*f += MODIFIER_HH) && (*i++) : 0;
// 		(s[*i] == 'l') && (s[*i + 1] != 'l') ? (*f += MODIFIER_L) : 0;
// 		(s[*i] == 'l') && (s[*i + 1] == 'l') ? (*f += MODIFIER_LL) && (*i++) : 0;
// 		(s[*i] == 'j') ? (*f += MODIFIER_J) : 0;
// 		(s[*i] == 'z') ? (*f += MODIFIER_Z) : 0;
// 		*i += 1;
// 	}
// }

// static int			parse_type(char c)
// {
// 	int ret;

// 	ret = 0;
// 	c == 'd' || c == 'D' || c == 'i' ? ret = TYPE_D : 0;
// 	c == 's' || c == 'S' ? ret = TYPE_S : 0;
// 	c == 'c' || c == 'C' ? ret = TYPE_C : 0;
// 	c == 'x' || c == 'X' ? ret = TYPE_X : 0;
// 	c == 'o' || c == 'O' ? ret = TYPE_O : 0;
// 	c == 'p' ? ret = TYPE_P : 0;
// 	c == 'u' || c == 'U' ? ret = TYPE_U : 0;
// 	c == 'b' ? ret = TYPE_B : 0;
// 	c == '%' ? ret = TYPE_PERCENT : 0;
// 	return (ret);
// }

// t_printf			*parse_conversion(t_printf *pf)
// {
// 	t_conv		*conv;

// 	conv = init_conv();
// 	parse_flags(&*conv, pf->format, &pf->i);
// 	conv->min_width = ft_atoi(&pf->format[pf->i]);
// 	while (ft_isdigit(pf->format[pf->i]))
// 		pf->i++;
// 	if (!(pf->format))
// 		ft_error_pf(INFO, "error_parse_minimal_width");
// 	(pf->format[pf->i] == '.' ? parse_precision(&*pf, &*conv) : 0);
// 	parse_modifier(&pf->i, &conv->flag, pf->format);
// 	(!pf->format[pf->i]) ? ft_error_pf(INFO, "error_format_type") : 0;
// 	conv->flag += parse_type(pf->format[pf->i]);
// 	conversion_specifier(&*pf, &*conv);
// 	return (pf);
// }
