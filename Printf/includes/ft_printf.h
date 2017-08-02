/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/02 16:21:53 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <unistd.h>
# include <wchar.h>

# include <stdio.h>// to delete


typedef struct			s_flags
{
	int					minus;
	int					plus;
	int					sharp;
	int					zero;
	int					space;
}						t_flags;

typedef struct			s_conv
{
	int					min_width;
	int					precision;
	int					precision_set;
	char				modif;
	char				type;
	char				sign;
	t_flags				*flags;
}						t_conv;

typedef struct			s_printf
{
	char 		*format;
	va_list		ap;
	int			i;
}						t_printf;


int		ft_printf(char *format, ...);
t_printf	*parse_conversion(t_printf *pf);
t_conv		*init_conv(void);

void	conv_c(t_printf *pf, t_conv *conv);
void	conv_s(t_printf *pf);
void	conv_d(t_printf *pf, t_conv *conv);
