/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 21:28:19 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/14 21:37:03 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_percent(t_printf *pf, t_conv *conv)
{
	char c;

	c = '%';
	if (conv)
	buffer(&*pf, ((char*)&c), 1);
}