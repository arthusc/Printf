/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:03:58 by achambon          #+#    #+#             */
/*   Updated: 2017/09/20 16:04:06 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_pf(unsigned long long n)
{
	int			i;
	uintmax_t	a;
	char		*str;

	i = 1;
	a = n;
	while ((a = a / 10) > 0)
		i++;
	if (!(str = (char *)malloc((sizeof(char) * i) + 1)))
		return (0);
	ft_bzero(str, i + 1);
	str[i] = '\0';
	while (i-- >= 0)
	{
		str[i] = ((n % 10) + '0');
		n = n / 10;
	}
	return (str);
}

t_conv	option_u2(t_printf *pf, char *tab, char c, t_conv *conv)
{
	int		i;

	i = 0;
	if (!(conv->before == 3) && conv->before && pf->str)
	{
		(conv->ox == 1) ? buffer(&*pf, "0x", 2) : 0;
		buffer(&*pf, pf->str, pf->len);
	}
	(conv->precision_set == 2) ? (buffer(&*pf, "0x", 2)) && (conv->ox = 0) : 0;
	(!(conv->flag & MINUS) || (conv->flag & MINUS
	&& conv->min_width > conv->precision) || conv->before == 3)
	? fill_tab_with_c(&*pf, tab, c) : 0;
	(((conv->flag & PLUS) && !(conv->flag & ZERO) && !(conv->flag & MINUS)
	&& (conv->flag & (TYPE_D + TYPE_U + TYPE_O)) && !(conv->before == 3) &&
	!conv->flag & MODIFIER_HH)) ? buffer(&*pf, "+", 1) : 0;
	if ((conv->before == 0 && pf->str) || conv->before == 3)
	{
		(conv->ox == 1) ? buffer(&*pf, "0x", 2) : 0;
		buffer(&*pf, pf->str, pf->len);
	}
	return (*conv);
}

t_conv	option_u(t_printf *pf, int n, char c, t_conv *conv)
{
	int		i;
	char	tab[n + 1];

	pf->n = n;
	pf->len = ft_strlen(pf->str);
	i = 0;
	tab[n] = '\0';
	if (!n)
		return (*conv);
	if (conv->before == 4)
	{
		while (i < n)
			tab[i++] = c;
		buffer(&*pf, tab, n);
		buffer(&*pf, " ", 1);
		buffer(&*pf, pf->str, pf->len);
		return (*conv);
	}
	option_u2(&*pf, tab, c, conv);
	return (*conv);
}

int		conv_u_minus_width_only2(t_printf *pf, t_conv *conv, int len)
{
	if (conv->min_width < len)
		return (0);
	else if (conv->min_width > len)
	{
		if (conv->flag & PLUS && !(conv->flag & ZERO) && !(conv->flag & SPACE))
		{
			conv->before = 1;
			option_u(&*pf, conv->min_width - len, ' ', conv);
			return (0);
		}
		(conv->flag & PLUS && !(conv->flag & ZERO)) ? conv->min_width-- : 0;
		if (conv->flag & PLUS + ZERO && !(conv->flag & MODIFIER_HH))
		{
			conv->before = 1;
			option_u(&*pf, conv->min_width - len, ' ', conv);
			return (0);
		}
		else if (conv->flag & ZERO)
		{
			conv->before = 1;
			option_u(&*pf, conv->min_width - len, ' ', conv);
			return (0);
		}
	}
	return (1);
}
