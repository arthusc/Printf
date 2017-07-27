/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:21:58 by achambon          #+#    #+#             */
/*   Updated: 2017/01/06 12:35:38 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		list = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void*)alst);
		*alst = list;
	}
}
