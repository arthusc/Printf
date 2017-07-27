# include "includes/ft_printf.h"

char	*conv(char *format, va_list ap)
	{
	int value;
	if (ft_strchr("-+#0 ", (int)format) != NULL)
	{
		format++;
		if (ft_strchr("0123456789", (int)format))
			format++;
	}
	//format++;
	//if((value = option(format)) != 0)
	//{
	//write(1, "okey\n", 5);
	//ft_putstr		(pf_str_option(ft_itoa(va_arg(ap, int)), ' ', value));
	//}
	if (*format == 's')
		conv_s(ap, format);
	if (*format == 'c')
		conv_c(ap);
	if (*format == 'd')
		conv_d(ap, format);
	return (&*format);
}
