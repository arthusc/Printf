# include "includes/ft_printf.h"


char *option_minus(char *str, int size)
{
	char *dst;
	int i;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	size = size - i;
	while (size--)
	{
		dst[i] = ' ';
		i++;
	}
	dst[i] = '\0';
		return (dst);
}

void	conv_s(va_list ap, char *format)
{
	char *str;

	str = va_arg(ap, char *);
	if (ft_strchr("-+#0 ")
		format++;
		pf->moins = 1;
	if (is_digit(
			p->minimal_ara = atoi(format

		str = option_minus("tout le monde", 5);
	ft_putstr(str);
}
