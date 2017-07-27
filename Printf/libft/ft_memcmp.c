/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:54:55 by achambon          #+#    #+#             */
/*   Updated: 2017/01/06 12:32:07 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*sc1;
	const char	*sc2;

	sc1 = s1;
	sc2 = s2;
	i = 0;
	while (n)
	{
		if (*sc1 != *sc2)
			return (((unsigned char)*sc1) - (unsigned char)*sc2);
		sc1++;
		sc2++;
		n--;
	}
	return (0);
}
