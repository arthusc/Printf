/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:41:29 by achambon          #+#    #+#             */
/*   Updated: 2016/12/02 11:00:10 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*(char*)dst = *(const char*)src;
		if (*(unsigned char*)src == (unsigned char)c)
			return (dst + 1);
		src++;
		dst++;
		n--;
	}
	return (NULL);
}
