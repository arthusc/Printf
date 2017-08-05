/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:30:50 by achambon          #+#    #+#             */
/*   Updated: 2017/08/05 18:24:44 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

void		conv_x(t_printf *pf, t_conv *conv)
{

	unsigned int pointer_x;
	char *str;
	int i;

	i = 0;

	if(!(pointer_x = va_arg(pf->ap, unsigned int)))
		return(ft_putstr("0x0"));
	str = ft_itoa_base((long long)pointer_x, 16);
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			str[i] = ft_tolower((int)str[i]);
		}
		i++;
	}
	ft_putstr(str);
	return;
}

void		conv_mx(t_printf *pf, t_conv *conv)
{

	unsigned int pointer_x;
	char *str;
	int i;

	i = 0;

	if(!(pointer_x = va_arg(pf->ap, unsigned int)))
		return(ft_putstr("0x0"));
	str = ft_itoa_base((long long)pointer_x, 16);
	ft_putstr(str);
	return;
}
