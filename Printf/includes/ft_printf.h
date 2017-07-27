# include "../libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>

int		ft_printf(char *format, ...);
char	*conv(char *format, va_list ap);
void	conv_c(va_list ap);
void	conv_d(va_list ap, char *format);
void	conv_s(va_list ap, char *format);
void	conv_d(va_list ap, char *format);
