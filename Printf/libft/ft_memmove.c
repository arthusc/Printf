/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:51:02 by achambon          #+#    #+#             */
/*   Updated: 2016/12/02 13:49:42 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = -1;
	if (src < dst)
		while (len--)
			*((char*)dst + len) = *((char*)src + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
