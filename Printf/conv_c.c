/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/07/31 21:56:57 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

// char	*option_minus_c(va_list *format, int minimum_field_width)
// {
// 	char *str;
// 	int count;

// 	count = 0;
// 	str = malloc(sizeof(char) * ft_strlen((char*)format) + 1);
// 	while (*format)
// 	{
// 		*str = (char)format;
// 		format++;
// 		str++;
// 	}
// 	while (count <= minimum_field_width)
// 	{
// 		*str = ' ';
// 		str++;
// 	}
// 	*str = '\0';
// 	return (str);
// }

// int		check_if_minimum_field_width(char *format)
// {
// 	int minimum_field_width;
// 	format = format;
// 	minimum_field_width = 5;
// 	return (minimum_field_width);
//}
void	conv_c(t_printf *pf)
{
// 	char *str;
	
// //	va_arg(*pf->ap, unsigned);
// 	if (ft_strchr("-0 ", *pf->format))
// 			{
// 				while (*pf->format)
// 				{
// 					if (*pf->format == '-')
// 					{
// 						pf->minimum_field_width = check_if_minimum_field_width(pf->format);
// 							str = option_minus_c(pf->ap, pf->minimum_field_width);
// 							ft_putstr(str);
// 							return;
// 					}
// 					pf->format++;
// 				}
// 			}
	ft_putchar(va_arg(pf->ap, unsigned));
}

/* Can deal with option "-" if there is a minimal_width
 * Can't deal with option "+" no matter what
 * Can't deal with option "#"
 * Can deal with option "0" and option "space"
 */

