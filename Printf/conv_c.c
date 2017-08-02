/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/02 13:52:39 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

/*char	*option_minus_c(va_list *format, int minimum_field_width)
{
	char *str;
	int count;

	count = 0;
	str = malloc(sizeof(char) * ft_strlen((char*)format) + 1);
	while (*format)
	{
		*str = (char)format;
		format++;
		str++;
	}
	while (count <= minimum_field_width)
	{
		*str = ' ';
		str++;
	}
	*str = '\0';
	return (str);
}
*/

void	conv_c(t_printf *pf, t_conv *conv)
{
/*	char *str;

	if (!(str = malloc(sizeof(char*))))
		return;
//	va_arg(pf->ap, unsigned);
	while(!(ft_strchr("-0 ", pf->format[pf->i])))
		pf->i++;
	while (pf->format[pf->i])
		{
			if (pf->format[pf->i] == '-')
			{
				str = option_minus_c(&pf->ap, conv->min_width);
				ft_putstr(str);
				return;
			}
			pf->i++;
		}*/
	if (conv->flags->zero == 1)
	{
		while(conv->min_width-- > 1)
			ft_putchar('0');
	}
	ft_putchar(va_arg(pf->ap, unsigned));
}

/* Can deal with option "-" if there is a minimal_width
 * Can't deal with option "+" no matter what
 * Can't deal with option "#"
 * Can deal with option "0" and option "space"
 */

