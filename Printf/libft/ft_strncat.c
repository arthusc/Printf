/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:12:15 by achambon          #+#    #+#             */
/*   Updated: 2016/12/02 14:06:32 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(s1);
	while (j < n && *s2)
	{
		s1[i] = *s2;
		i++;
		s2++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
