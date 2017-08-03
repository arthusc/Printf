/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:07:37 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/03 02:27:27 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

// static void	print_wstring(t_printf *pf, )
// {

// }

void	conv_s(t_printf *pf, t_conv *conv)
{
	char *apstring;
	int len;

	if (!(apstring = va_arg(pf->ap, char*)))
				ft_error("error_conv_s\n");
	len = ft_strlen(apstring);
//	printf("%d\n", len);
	if (conv->flags->zero == 1 && conv->flags->minus == 0)
		while (conv->min_width-- > 0 + len)
			ft_putchar('0');
	if (conv->flags->space == 1)
		while (conv->min_width-- > 0 + len)
			ft_putchar(' ');
	if (conv->flags->minus == 1)
	{
		ft_putstr(apstring);
		while (conv->min_width-- > 0 + len)
			ft_putchar(' ');
		return;
	}
	ft_putstr(apstring);
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
