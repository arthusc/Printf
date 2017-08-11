/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:10:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/11 14:29:07 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <unistd.h>
# include <wchar.h>

# include <stdio.h>// to delete

# define TYPE_S 		(1 << 31)
# define TYPE_C 		(1 << 30)
# define TYPE_D 		(1 << 29)
# define TYPE_P 		(1 << 28)
# define TYPE_X 		(1 << 27)
# define TYPE_U 		(1 << 26)
# define TYPE_O 		(1 << 25)

# define PRECISION		(1 << 11)

# define MODIFIER_H		(1 << 10)
# define MODIFIER_HH	(1 << 9)
# define MODIFIER_L		(1 << 8)
# define MODIFIER_LL	(1 << 7)
# define MODIFIER_J		(1 << 6)
# define MODIFIER_Z		(1 << 5)

# define MINUS			(1 << 4)
# define PLUS			(1 << 3)
# define SHARP			(1 << 2)
# define ZERO			(1 << 1)
# define SPACE			(1 << 0)

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
