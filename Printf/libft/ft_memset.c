/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:34:33 by achambon          #+#    #+#             */
/*   Updated: 2017/01/06 12:29:04 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = b;
	while (i < len)
	{
		*tmp = (unsigned char)c;
		tmp++;
		i++;
	}
	return (b);
}
