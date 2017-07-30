/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/07/30 15:32:50 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <unistd.h>

# include <stdio.h>// to delete

typedef struct			s_printf
{
	char 		*format;
	va_list		*ap;
	int			minimum_field_width;
}						t_printf;

int		ft_printf(char *format, ...);
t_printf	*conversion_specifier(t_printf *pf);
void	conv_c(t_printf *pf);
void	conv_d(t_printf *pf);
void	conv_s(t_printf *pf);
void	conv_d(t_printf *pf);
