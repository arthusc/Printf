/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:56:27 by achambon          #+#    #+#             */
/*   Updated: 2017/01/06 12:34:47 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_negflag(int *n, int *neg)
{
	if (*n < 0)
	{
		*n = *n * (-1);
		*neg = 1;
	}
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		len;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = 0;
	neg = 0;
	ft_negflag(&n, &neg);
	while ((tmp = tmp / 10) != 0)
		len++;
	len = len + neg;
	if (!(str = (char*)malloc(sizeof(char) * len + 2)))
		return (NULL);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
