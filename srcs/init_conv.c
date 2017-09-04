/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 23:38:21 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/11 13:25:11 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_conv				*init_conv(void)
{
	t_conv		*conv;
	
	if (!(conv = malloc(sizeof(t_conv))))
		ft_error("error_malloc_init_conv");
	ft_bzero(conv, sizeof(t_conv));
	conv->modif = '0';
	conv->flag = 0;
	return (conv);
}
