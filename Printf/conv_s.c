/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:07:37 by mbriffau          #+#    #+#             */
/*   Updated: 2017/07/30 15:33:09 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"


char *option_minus(char *str, int size)
{
	char *dst;
	int i;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	size = size - i;
	while (size--)
	{
		dst[i] = ' ';
		i++;
	}
	dst[i] = '\0';
		return (dst);
}

void	conv_s(t_printf *pf)
{
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
	ft_putstr(va_arg(*pf->ap, char *));
}
