# include "includes/ft_printf.h"

void	conv_c(va_list ap)
{
		ft_putchar(va_arg(ap, unsigned));
}
