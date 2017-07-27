# include "includes/ft_printf.h"

int		pf_nputstr(char *str, int size)
{
	write(1, str, size);
	return (0);
}

int		ft_printf(char *format, ...)
{
	va_list ap;
	int		before_conv_size;

	before_conv_size = 0;
	va_start(ap, format); 
	/*
	 * stdarg permet de gerer quand il y a une 
	 * variete de nombre d'argument possibles, de types pouvant etre 
	 * differents
	  */
	while (*format)
	{
		if (*format == '%')
		{
			before_conv_size = pf_nputstr(format - before_conv_size, before_conv_size);
//			conv(++format, ap);
		}
		format++;
		before_conv_size++;
	}
	if (before_conv_size > 0)
			before_conv_size = pf_nputstr(format - before_conv_size, before_conv_size);
	va_end(ap);
	return (0);
}


/*
 * Quand la precision est trop grande, printf comble avec des 0
 * Le flag 0 est ignore lorsque le flag - est present 
 * *
 */
