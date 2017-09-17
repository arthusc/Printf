/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:30:50 by achambon          #+#    #+#             */
/*   Updated: 2017/09/17 12:18:34 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

char			*ft_str_tolower(char * s)
{
	int		i;

	i = 0;
	while(s[i])
	{
		if (ft_isalpha(s[i]))
			s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}

static t_conv	option_x(t_printf *pf, int n, char c, t_conv *conv, char *s)
{
	int		i;
	char	tab[n + 1];
	int 	len;

	len = ft_strlen(s);
	i = 0;
	tab[n] = '\0';
	if (!n)
		return(*conv);
	if (conv->before == 4)
	{
		if(conv->flag & SHARP)
			n--;
		while (i < n)
			tab[i++] = c;
		buffer(&*pf, tab, n);
		buffer(&*pf, " ", 1);
		if(conv->flag & SHARP)
			buffer(&*pf, "0x", 2);
		buffer(&*pf, s, len);
		return(*conv);
	}
	if (!(conv->before == 3) && conv->before && s)
	{
		if(conv->ox == 1)
			buffer(&*pf, "0x", 2);
		buffer(&*pf, s, len);
	}
	if (conv->precision_set == 2)
	{
		buffer(&*pf, "0x", 2);
		conv->ox = 0;
	}
	if(!(conv->flag & MINUS) || (conv->flag & MINUS && conv->min_width > conv->precision) || conv->before == 3)
	{
		if(conv->flag & SHARP && conv->ox == 2)
		{
			buffer(&*pf, "0x", 2);
		}
		while (i < n)
			tab[i++] = c;
		buffer(&*pf, tab, n);
	}
	if(((conv->flag & PLUS) && !(conv->flag & ZERO) && !(conv->flag & MINUS) && (conv->flag & (TYPE_D + TYPE_U + TYPE_O)) && !(conv->before == 3) && !conv->flag & MODIFIER_HH))
		buffer(&*pf, "+", 1);
	if ((conv->before == 0 && s) || conv->before == 3)
	{
		if(conv->ox == 1)
			buffer(&*pf, "0x", 2);
		buffer(&*pf, &*s, len);
	}
	if((conv->flag & MINUS && !(conv->min_width > conv->precision)) && !(conv->before == 3))
	{
		while (i < n)
			tab[i++] = c;
		buffer(&*pf, tab, n);
	}
	
	return (*conv);
}

t_printf	*add_0x(t_printf *pf, t_conv *conv)
{
	if (conv->flag & MODIFIER_X)
	{
		buffer(&*pf, "0X", 2);
		return(pf);
	}
	buffer(&*pf, "0x", 2);
	return(pf);
}

int	conv_x_minus(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (!conv->min_width && !conv->precision)
			return(pf->i_buf);
	if (conv->min_width && !conv->precision)
	{
		if(conv->min_width < len)
		{
			if(conv->flag & SHARP)
				buffer(&*pf, "0x", 2);
			return(0);
		}
		else if(conv->min_width > len)
		{
			if(conv->flag & SHARP)
			{
				conv->min_width = conv->min_width - 2;
				buffer(&*pf, "0x", 2);
			}
			if(conv->flag & PLUS && !(conv->flag & ZERO) && !(conv->flag & SPACE) /*&& !(conv->flag & MODIFIER_HH)*/)
			{
				conv->before = 1;
				option_x(&*pf, conv->min_width - len, ' ', conv, str);
				return(pf->i_buf);
			}
			if(conv->flag & PLUS && !(conv->flag & ZERO))
			{
				conv->min_width--;
			}
			else if(conv->flag & PLUS && conv->flag & ZERO && !(conv->flag & MODIFIER_HH))
			{
				conv->before = 1;
				option_x(&*pf, conv->min_width - len, ' ', conv, str);
				return(pf->i_buf);
			}
			else if(conv->flag & ZERO)
			{
				conv->before = 1;
				option_x(&*pf, conv->min_width - len, ' ', conv, str);
				return(pf->i_buf);
			}
		}
		if (!(conv->flag & PLUS))
		{
			conv->before = 1;
			option_x(&*pf, conv->min_width - len, ' ', conv, str);
			return(pf->i_buf);
		}
		option_x(&*pf, conv->min_width - len, ' ', conv, str);
		return(0);
	}
	if (!conv->min_width && conv->precision)
	{
		if(conv->flag & SHARP)
				buffer(&*pf, "0x", 2);
		conv->before = 3;
		if(str[0] == '-')
		{
			special_hhd_reverse_0_n_minus(pf, str, '-');
		}
		option_x(&*pf, conv->precision - len, '0', conv, str);
		return(pf->i_buf);
	}
	if (conv->min_width && conv->precision)
	{
		if(conv->min_width > conv->precision)
		{
			if(conv->flag & SHARP)
			{
				buffer(&*pf, "0x", 2);
				conv->min_width = conv->min_width - 2;
			}
			conv->before = 0;
			if (str[0] == '-')
			{
				special_hhd_reverse_0_n_minus(&*pf, str, '-');
			}
			option_x(&*pf, conv->precision - len, '0', conv, str);
			while((conv->min_width-- - conv->precision))
				buffer(&*pf, " ", 1);
			return(0);
		}
		if (conv->min_width <= conv->precision)
		{
			if(str[0] == '-')
			{
				special_hhd_reverse_0_n_minus(&*pf, str, '-');
			}
			if(conv->flag & SHARP)
			{
				buffer(&*pf, "0x", 2);
				conv->min_width = conv->min_width - 2;
			}
			conv->before = 3;
			option_x(&*pf, conv->precision - len, '0', conv, str);
			return(0);
		}
	}
	buffer(&*pf, str, len);
	return(0);
}
int		print_conv_x(t_printf *pf, t_conv *conv, int len, char *str)
{
	int	width_temp;

	len = ft_strlen(str);
	width_temp = conv->min_width;
	if(!conv->precision && conv->precision_tick)
	{
			if(conv->min_width)
				while(conv->min_width--)
					buffer(&*pf, " ", 1);
			if(!(ft_strncmp("0", str, len)))
			{
			 return(pf->i_buf);
			}
	}
	if (!conv->min_width && !conv->precision)
	{
		if(conv->flag & SPACE && !(conv->flag & PLUS))
			return(add_char_and_string_2_buff(&*pf, ' ', str, len));
		if(conv->flag & PLUS)
			return(add_char_and_string_2_buff(&*pf, '+', str, len));
		if(conv->flag & SHARP && str[0] != '0')
			add_0x(&*pf, &*conv);
	}
	if (conv->flag & MINUS)
	{

		(conv_x_minus(&*pf, conv, len, str));
		if (conv->min_width > len || width_temp > len)
		{
			if (str[0] == '-')
			{
				width_temp--;
				if (conv->flag & PLUS && !(conv->flag & SPACE + ZERO))
					width_temp++;
			}
			return (0);
		}
		if(conv->min_width < len && !(conv->flag & SPACE) && !(conv->flag & PLUS) && !conv->precision)
		{
			buffer(&*pf, str, len);
			return(0);
		}
	}
	if(str[0] == '-' && conv->flag & MINUS)
	{
		conv->min_width--;
	}
	if (conv->min_width && !conv->precision)
	{
		if(conv->min_width < len)
		{
			if(conv->flag & SHARP && !(conv->flag & MINUS))
				add_0x(&*pf, &*conv);
			buffer(&*pf, str, len);
			return(0);
		}
		if(conv->min_width >= len || width_temp >= len)
		{
			if(conv->flag & SPACE && !(conv->flag & PLUS))
			{
			}
			if(conv->flag & PLUS && !(conv->flag & ZERO + MODIFIER_HH + SHARP))
				conv->min_width--;
			else if(conv->flag & PLUS && conv->flag & ZERO && !(conv->flag & MODIFIER_HH))
			{
				if(conv->flag & SHARP)
				{
					buffer(&*pf, "0x", 2);
					conv->min_width = conv->min_width - 2;
				}
				option_x(&*pf, conv->min_width - len, '0', &*conv, str);
				return(pf->i_buf);
			}
			else if(conv->flag & ZERO)
			{
				if(str[0] == '-')
				{
					str[0] = '0';
					return(add_char_and_string_2_buff(&*pf, '-', str, len));
				}
				if(conv->flag & SHARP)
				{
					buffer(&*pf, "0x", 2);
					conv->min_width = conv->min_width - 2;
				}
				option_x(&*pf, conv->min_width - len, '0', &*conv, str);
				return(pf->i_buf);
			}
			if(conv->flag & MODIFIER_HH /*&& !(conv->flag & ZERO + PLUS + SPACE)*/)
			{
				while(conv->min_width-- - len)
					buffer(&*pf, " ", 1);
				buffer(&*pf, str, len);
				return(0);
			}
			if(conv->flag & PLUS && !(conv->flag & ZERO) && !(conv->flag & SPACE))
				conv->before = 4;
			if(conv->flag & SHARP)
			{
				conv->ox = 1;
				conv->min_width = conv->min_width - 2;
			}
			option_x(&*pf, conv->min_width - len, ' ', &*conv, str);
			return(pf->i_buf);
		}
	}
	if (!conv->min_width && conv->precision && conv->flag & MINUS)
	{
		return(0);
	}
	if (!conv->min_width && conv->precision && conv->precision > len && !(conv->flag & MINUS))
	{
		conv->before = 3;
		if (conv->flag & SHARP)
			buffer(&*pf, "0x", 2);
		option_x(&*pf, conv->precision - len, '0', &*conv, str);
		return(pf->i_buf);
	}
	if (conv->min_width && conv->precision)
	{
		if(conv->min_width > conv->precision)
		{
			conv->before = 0;
			if(conv->flag & SPACE && !(conv->flag & PLUS + SHARP))
			{
			}
			if(conv->flag & PLUS)
				conv->min_width--;
			if(conv->flag & SHARP)
			{
				conv->ox = 2;
				conv->min_width = conv->min_width - 2;
			}
			while((conv->min_width-- - len))
				buffer(&*pf, " ", 1);
			if(conv->flag & PLUS)
			{
				conv->before = 3;
				buffer(&*pf, " ", 1);
			}
			buffer(&*pf, str, len);
			return(0);
		}
		if (conv->min_width <= conv->precision)
		{
			if(conv->flag & SHARP)
			{
				buffer(&*pf, "0x", 2);
			}
			option_x(&*pf, conv->precision - len, '0', &*conv, str);
			return(0);
		}
	}
	buffer(&*pf, str, len);	
	return(0);
}

void		conv_x(t_printf *pf, t_conv *conv)
{
	uintmax_t	va_ptr;
	char		*str;

	va_ptr = 1;
	conv->flag & MODIFIER_L ? ((va_ptr = (unsigned long int)va_ptr) &&
		(va_ptr = va_arg(pf->ap, unsigned long int))) : 0;
	conv->flag & MODIFIER_LL ? ((va_ptr = (unsigned long long int)va_ptr) &&
		(va_ptr = va_arg(pf->ap, unsigned long long int))) : 0;
	conv->flag & MODIFIER_H ? ((va_ptr = (uint16_t)va_ptr) &&
		(va_ptr = va_arg(pf->ap, unsigned int))) : 0;
	conv->flag & MODIFIER_HH ? ((va_ptr = (uint8_t)va_ptr) &&
		(va_ptr = va_arg(pf->ap, unsigned int))) : 0;
	conv->flag & MODIFIER_Z ? ((va_ptr = (size_t)va_ptr) &&
		(va_ptr = va_arg(pf->ap, size_t))) : 0;
	conv->flag & MODIFIER_J ? ((va_ptr = (uintmax_t)va_ptr) &&
		(va_ptr = va_arg(pf->ap, uintmax_t))) : 0;
	!(conv->flag & 0x7E0) ? ((va_ptr = (unsigned int)va_ptr) &&
		(va_ptr = va_arg(pf->ap, unsigned int))) : 0;
	str = ft_itoa_base((long long)va_ptr, 16);
	conv->flag & MODIFIER_X ? 0 : (str = ft_str_tolower(str));
	print_conv_x(pf, conv, ft_strlen(str), str);
	return;
}
