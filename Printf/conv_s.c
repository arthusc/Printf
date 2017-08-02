/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:07:37 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/02 17:38:31 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

void	conv_s(t_printf *pf, t_conv *conv)
{
		char *str;
		int len;
	
		pf->apstring = va_arg(pf->ap, char*);
		len = ft_strlen(pf->apstring);
//	printf("%d\n", len);
	if (conv->flags->zero == 1 && conv->flags->minus == 0)
	while (conv->min_width-- > 0 + len)
	ft_putchar('0');
	if (conv->flags->space == 1)
	while (conv->min_width-- > 0 + len)
	ft_putchar(' ');
	if (conv->flags->minus == 1)
	{
	ft_putstr(pf->apstring);
	while (conv->min_width-- > 0 + len)
	ft_putchar(' ');
	return;
	}
	ft_putstr(pf->apstring);
}
	//char *str;
	// int		moins = 0;

	//str = va_arg(ap, char *);
	// if (ft_strchr("-+#0 ", *format))
	// {
	// 	format++;
	// 	moins = 1;
	// }
	// if (moins && ft_isdigit(*format))
	// {
	// 		minimal_ara = atoi(format);
	// }
	// str = option_minus("tout le monde", 5);
	// while (s[i])
	// {
	// 	i++;
	// }
	// write(1, s, i);
//	ft_putstr((char *)s);
//}
