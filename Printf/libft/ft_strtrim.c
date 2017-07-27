/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:54:43 by achambon          #+#    #+#             */
/*   Updated: 2017/01/06 12:09:05 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim3d;
	int		begin;
	int		end;

	if (!s)
		return (NULL);
	begin = 0;
	end = ft_strlen(s);
	while (s[begin] == '\t' || s[begin] == '\n' || s[begin] == ' ')
		begin++;
	while (s[end - 1] == '\t' || s[end - 1] == '\n' || s[end - 1] == ' ')
		end--;
	if (begin == 0 || end == ft_strlen(s))
		ft_strdup(s);
	if (end < begin)
		return (ft_strdup(s + begin));
	trim3d = ft_strsub(s, begin, end - begin);
	return (trim3d);
}
