/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 18:00:23 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/27 22:08:52 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printf	*conversion_specifier(t_printf *pf, t_conv *conv)
{
	if (conv->flag & 0xFF800000)
	{
		conv->flag & TYPE_D ? conv_d(&*pf, &*conv) : 0;
		conv->flag & TYPE_S ? conv_s(&*pf, &*conv) : 0;
		conv->flag & TYPE_C ? conv_c(&*pf, &*conv) : 0;
		conv->flag & TYPE_P ? conv_p(&*pf, &*conv) : 0;
		conv->flag & TYPE_X ? conv_x(&*pf, &*conv) : 0;
		conv->flag & TYPE_O ? conv_x(&*pf, &*conv) : 0;
		conv->flag & TYPE_U ? conv_x(&*pf, &*conv) : 0;
		conv->flag & TYPE_B ? conv_b(&*pf, &*conv) : 0;
		conv->flag & TYPE_PERCENT ? conv_percent(&*pf, &*conv) : 0;
	}
	else if (!(conv->flag & 0xFF800000))
		(conv->flag & 0x1F) && conv->min_width ? no_conv(&*pf, &*conv) : 0;
	pf->i++;
	return (pf);
}
