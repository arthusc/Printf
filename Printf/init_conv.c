/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 23:38:21 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/01 23:39:52 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

static t_flags		*init_flags(void)
{
	t_flags		*newflags;

	newflags = malloc(sizeof(t_flags));
	ft_bzero(newflags, sizeof(t_flags));
	return (newflags);
}

t_conv				*init_conv(void)
{
	t_conv		*conv;
	
	if (!(conv = malloc(sizeof(t_conv))))
		ft_error("error_malloc_init_conv");
	ft_bzero(conv, sizeof(t_conv));
	conv->flags = init_flags();
	conv->modif = NONE;
	return (conv);
}
