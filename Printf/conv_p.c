/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:58:06 by achambon          #+#    #+#             */
/*   Updated: 2017/08/07 12:47:02 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

void	conv_p(t_printf *pf, t_conv *conv)
{
	void *pointer;
	char *str;
	int i;
	int len;

	i = 0;
	if(!(pointer = va_arg(pf->ap, void *)))
		return(ft_putstr("0x0"));
	str = ft_itoa_base((long long)pointer, 16);
	len = ft_strlen(str);


	if(conv->flags->minus == 1)
	{
		ft_putstr("0x");
		if(conv->precision_set > 0)
			while((conv->precision-- - len) >= 1)
			{
				ft_putchar('0');
				conv->min_width = conv->min_width - 1;
			}
		ft_putstr(str);
	}

	if(conv->flags->zero == 1 && conv->flags->minus == 0 && conv->precision_set == 1)
		ft_putchar(' ');




	while (conv->min_width-- > 1 + conv->precision + 2)
		ft_putchar(' ');
	if (conv->flags->minus == 0)
		ft_putstr("0x");
	if(conv->precision_set > 0)
		while ((conv->precision-- - len) >= 1)
			ft_putchar('0');			
	if (conv->flags->minus == 0)
		ft_putstr(str);


	if (conv->flags->zero == 1 && conv->flags->minus == 0 && conv->precision_set == 0)
	{
		ft_putstr("0x"); // Pas tres propre, a voir//
		while (conv->min_width-- - len - 2 > 0)
			ft_putchar('0');
	}

		if (conv->flags->space == 1)
	{
		while(conv->min_width-- - len - 2 > 0)
			ft_putchar(' ');
		if(conv->flags->minus == 0)
			ft_putstr("0x"); // Pas tres propre, a voir//
	}


	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			str[i] = ft_tolower((int)str[i]);
		}
		i++;
	}

	//while (conv->min_width-- > 0 + len + 2)
	//		ft_putchar(' ');
	//	ft_printf("->LEN = %d", ft_strlen(str));
	return;
}



