/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:51:26 by achambon          #+#    #+#             */
/*   Updated: 2017/01/06 12:16:54 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	join = malloc(sizeof(char*) * ((ft_strlen(s1) + (ft_strlen(s2) + 1))));
	if (!join)
		return (NULL);
	ft_strcpy(join, (char*)s1);
	ft_strcat(join, (char*)s2);
	return (join);
}
