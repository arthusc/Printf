/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:21:14 by achambon          #+#    #+#             */
/*   Updated: 2017/01/06 12:11:38 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *lttle, size_t ln)
{
	size_t			i;
	int				flag;

	flag = 0;
	if (*lttle == '\0')
		return ((char*)big);
	i = ft_strlen(lttle);
	while (*big != '\0' && ln >= i)
	{
		if (*big == *lttle && ft_memcmp(big, lttle, i) == 0)
		{
			flag = 1;
			break ;
		}
		big++;
		ln--;
	}
	if (flag == 1)
		return ((char*)big);
	return (NULL);
}
