# include "includes/ft_printf.h"
/*
 *gere conv_i aussi
 */

void	conv_d(va_list ap, char *format)
{
	int value;

//value = 0;
//	//if((value = option(format)) != 0)
// {
//		write(1, "okey\n", 5);
//		ft_putstr(pf_str_option(ft_itoa(va_arg(ap, int)), ' ', value));
//	}
	//else
		ft_putnbr(va_arg(ap, int));
}
