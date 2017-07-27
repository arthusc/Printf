/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:19:32 by achambon          #+#    #+#             */
/*   Updated: 2017/01/06 12:12:15 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	const char	*tmp1;
	const char	*tmp2;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		tmp1 = big;
		tmp2 = little;
		while (*tmp1 == *tmp2 && *tmp1 != '\0' && *tmp2 != '\0')
		{
			tmp1++;
			tmp2++;
		}
		if (*tmp2 == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
