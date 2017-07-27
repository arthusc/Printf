# include "includes/ft_printf.h"

char	*conv(char *format, va_list ap)
	{
		int count;

		count  = 0;
		while (ft_strchr("sSpdDioOuUxXcC", *format))
		{
			format++;
			count++;
		}
	//format++;
	//if((value = option(format)) != 0)
	//{
	//write(1, "okey\n", 5);
	//ft_putstr		(pf_str_option(ft_itoa(va_arg(ap, int)), ' ', value));
	//}
	if (*format == 's')
	{
		conv_s(ap, (format - count));
	}
	if (*format == 'c')
	{
		write(1, "c", 1);
	//	conv_c(ap);
	}
	if (*format == 'd')
	{
		write(1, "d", 1);
	//	conv_d(ap, format);
	}
	return (&*format);
}
