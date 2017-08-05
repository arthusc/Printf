/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:58:06 by achambon          #+#    #+#             */
/*   Updated: 2017/08/05 17:01:37 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

void	conv_p(t_printf *pf, t_conv *conv)
{
	void *pointer;
	char *str;
	int i;

	i = 0;
	if(!(pointer = va_arg(pf->ap, void *)))
		return(ft_putstr("0x0"));
	ft_putstr("0x"); // Pas tres propre, a voir//
	str = ft_itoa_base((long long)pointer, 16);
	str[ft_strlen(str)] = '\0';
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			str[i] = ft_tolower((int)str[i]);
		}
				i++;
	}
	ft_putstr(str);
//	ft_printf("->LEN = %d", ft_strlen(str));
	return;
}



