/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:55:39 by achambon          #+#    #+#             */
/*   Updated: 2017/01/06 12:08:35 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_words(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (j);
}

static int		ft_letter(const char *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**tab;

	i = 0;
	j = 0;
	if (!s || !(tab = (char**)malloc(sizeof(*tab) * ft_words(s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			len = ft_letter(s, c, i);
			if (!(tab[j] = ft_strsub(s, i, len)))
				return (NULL);
			j++;
			i = i + len;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
