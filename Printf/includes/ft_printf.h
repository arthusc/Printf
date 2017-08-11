/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/11 13:20:33 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <unistd.h>
# include <wchar.h>

# include <stdio.h>// to delete

# define PRECISION		2048
# define MODIFIER_H		1024
# define MODIFIER_HH	512
# define MODIFIER_L		256
# define MODIFIER_LL	128
# define MODIFIER_J		64
# define MODIFIER_Z		32
# define MINUS			16
# define PLUS			8
# define SHARP			4
# define ZERO			2
# define SPACE			1


typedef struct			s_conv
{
	int					min_width;
	int					precision;
	int					precision_set;
	int					ox;
	int					before;
	char				modif;
	char				type;
	char				sign;
	int					flag;
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
void	conv_s(t_printf *pf, t_conv *conv);
void	conv_d(t_printf *pf, t_conv *conv);
void	conv_d_l(t_printf *pf, t_conv *conv);
void	conv_d_h(t_printf *pf, t_conv *conv);
void	conv_f(t_printf *pf, t_conv *conv);
void	conv_f_L(t_printf *pf, t_conv *conv);
void	print_wint(wint_t wint);
void	conv_p(t_printf *pf, t_conv *conv);
void	print_p(char *str);
void	conv_mx(t_printf *pf, t_conv *conv);
void	conv_x(t_printf *pf, t_conv *conv, char height);
void	conv_o(t_printf *pf, t_conv *conv);
void	conv_u(t_printf *pf, t_conv *conv);
int		option(int n, char c, t_conv *conv, char *s);
