/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:18:44 by achambon          #+#    #+#             */
/*   Updated: 2017/01/06 12:33:12 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	char	*tcontent;

	if (!(tcontent = (char*)malloc(sizeof(char) * content_size)))
		return (NULL);
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
		return (list);
	}
	else
	{
		list->content = ft_memcpy(tcontent, content, content_size);
		list->content_size = content_size;
		list->next = NULL;
	}
	return (list);
}
