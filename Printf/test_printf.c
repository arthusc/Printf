#include "includes/ft_printf.h"

int main(int ac, char **av)
{

	if (ac < 1)
		ft_printf("av[1] = %s\n", av[1]);
	ft_printf("\n----| Debut_du_test_ft_printf |------\n");

	printf("\n---test00---------------------\n");
	printf("abcd\n");
	ft_printf("abcd\n");

	printf("\n---test01_c---------------------\n");
	printf("->%c\n", 'a');
	ft_printf("->%c\n", 'a');

	printf("\n---test02_s---------------------\n");
	printf("->%s\n", "test_s");
	ft_printf("->%s\n", "test_s");

	printf("\n---test03_d---------------------\n");
	printf("->%d\n", 42);
	ft_printf("->%d\n", 42);

	printf("\n---test04_-4d---------------------\n");
	printf("->%-10s\n", "Salut");
	ft_printf("->%-10s\n" "Salut");

	return (0);
}
