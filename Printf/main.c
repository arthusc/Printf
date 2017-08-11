/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 23:29:04 by achambon          #+#    #+#             */
/*   Updated: 2017/08/11 00:57:42 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(int ac, char **av)
{
	// size_t a = 123456;
	//  uintmax_t max = 789456123;
	//  unsigned char uchar = 65;
	if (ac)
	//  {
	//  	 ac = ac;
	//  }
	// int c = 14574;
	// int *d = &c;
	ft_printf("abcd%s\n", " 1");
	ft_printf("efg%-15s\n", " 1");
	ft_printf("->%-10c\n", 'a');
	ft_printf("->%s\n", "test_s");
	ft_printf("->%.2d\n", 42);
	ft_printf("->%-10s\n", "Salut");

/*-----------tests pour %c----------*/
	ft_printf("->%010S\n", L"ひらがな");
	ft_printf("->%015C\n", L'ひ');
	ft_printf("->% 15C\n", L'ひ');
	ft_printf("->%-15lc\n", L'ひ');
	ft_printf("->%-15c\n", 'a');

//	ft_printf("m :%lo\n", 30);
//	ft_printf("m :% 15zo\n", a);
//	ft_printf("m :%jo\n", max);
//	ft_printf("m :%010o\n", 60);
//	ft_printf("m :%hho\n", uchar);

//	 ft_printf("m :%p\n", d);
//	 printf("t :%p\n", d);
//	 ft_printf("m :%20p\n", d);
//	 printf("t :%20p\n", d);
//	 ft_printf("m :%10p\n", d);
//	 printf("t :%10p\n", d);
	
	// ft_printf("m :%010p\n", d);
	//  printf("t :%010p\n", d);
	//  ft_printf("m :%.5p\n", d);
	//  printf("t :%.5p\n", d);
	//  ft_printf("m :%.25p\n", d);
	//  printf("t :%.25p\n", d);
	//  ft_printf("m :%-.5p\n", d);
	//  printf("t :%-.5p\n", d);
	//  ft_printf("m :%-.25p\n", d);
	//  printf("t :%-.25p\n", d);
	//  ft_printf("m :%0.5p\n", d);
	//  printf("t :%0.5p\n", d);
	//  ft_printf("m :%-0.25p\n", d);
	//  printf("t :%-0.25p\n", d);
	//  ft_printf("m :%- 25p\n", d);
	//  printf("t :%- 25p\n", d);
	//  ft_printf("m :%10.20p\n", d);
	//  printf("t :%10.20p\n", d);
	//  ft_printf("m :%20.10p\n", d);
	//  printf("t :%20.10p\n", d);
	//  ft_printf("m :%-10.20p\n", d);
	//  printf("t :%-10.20p\n", d);
	//  ft_printf("m :%+20.30p\n", d);
	//  printf("t :%+20.30p\n", d);
	//  ft_printf("m :%50.100p\n", d);
	//  printf("t :%50.100p\n", d);
	//  ft_printf("m :%-010.5p\n", d);
	//  printf("t :%-010.5p\n", d);

	// printf("t :%10u\n", c);
	// ft_printf("m :%10u\n", c);
	// printf("t :%.10u\n", c);
	// ft_printf("m :%.10u\n", c);
	// printf("t :%10.5u\n", c);
	// ft_printf("m :%10.5u\n", c);
	// printf("t :%5.10u\n", c);
	// ft_printf("m :%5.10u\n", c);
	// printf("t :%-10u\n", c);
	// ft_printf("m :%-10u\n", c);
	// printf("t :%-.10u\n", c);
	// ft_printf("m :%-.10u\n", c);
	// printf("t :%-10.5u\n", c);
	// ft_printf("m :%-10.5u\n", c);
	// printf("t :%-5.10u\n", c);
	// ft_printf("m :%-5.10u\n", c);/

	// printf("t :%10o\n", c);
	// ft_printf("m :%10o\n", c);
	// printf("t :%.10o\n", c);
	// ft_printf("m :%.10o\n", c);
	// printf("t :%10.5o\n", c);
	// ft_printf("m :%10.5o\n", c);
	// printf("t :%5.10o\n", c);
	// ft_printf("m :%5.10o\n", c);
	// printf("t :%-10o\n", c);
	// ft_printf("m :%-10o\n", c);
	// printf("t :%-.10o\n", c);
	// ft_printf("m :%-.10o\n", c);
	// printf("t :%-10.5o\n", c);
	// ft_printf("m :%-10.5o\n", c);
	// printf("t :%-5.10o\n", c);
	// ft_printf("m :%-5.10o\n", c);

	// printf("t :%10x\n", c);
	// ft_printf("m :%10x\n", c);
	// printf("t :%.10x\n", c);
	// ft_printf("m :%.10x\n", c);
	// printf("t :%10.5x\n", c);
	// ft_printf("m :%10.5x\n", c);
	// printf("t :%5.10x\n", c);
	// ft_printf("m :%5.10x\n", c);
	// printf("t :%-10x\n", c);
	// ft_printf("m :%-10x\n", c);
	// printf("t :%-.10x\n", c);
	// ft_printf("m :%-.10x\n", c);
	// printf("t :%-10.5x\n", c);
	// ft_printf("m :%-10.5x\n", c);
	// printf("t :%-5.10x\n", c);
	// ft_printf("m :%-5.10x\n", c);

	// ft_printf("m :%10.5d\n", 784);
	// printf("t :%10.5d\n", 784);
	// ft_printf("m :% 10.5d\n", 784);
	// printf("t :% 10.5d\n", 784);
	// ft_printf("m :%+10.5d\n", 784);
	// printf("t :%+10.5d\n", 784);
	// ft_printf("m :%-10.5d\n", 784);
	// printf("t :%-10.5d\n", 784);
	// ft_printf("m :%+-10.5d\n", 784);
	// printf("t :%+-10.5d\n", 784);
	// ft_printf("m :%-010.5d\n", 784);
	// printf("t :%-010.5d\n", 784);
	// ft_printf("m :%+010.5d\n", 784);
	// printf("t :%+010.5d\n", 784);
	// ft_printf("m :%-+010.5d\n", 784);
	// printf("t :%-+010.5d\n", 784);
	// ft_printf("m :% 010.5d\n", 784);
	// printf("t :% 010.5d\n", 784);


	// ft_printf("t :% .5d\n", 784);
	// printf("t :% .5d\n", 784);
	// ft_printf("t :% .5d\n", 784);
	// printf("t :% .5d\n", 784);
	// ft_printf("t :% .5d\n", 784);
	// printf("t :% .5d\n", 784);

	// ft_printf("t :% 5d\n", 784);
	// printf("t :% 5d\n", 784);
	// ft_printf("t :% 5d\n", 784);
	// printf("t :% 5d\n", 784);
	// ft_printf("t :% 5d\n", 784);
	// printf("t :% 5d\n", 784);
//	printf("% s\n", "14 is a positive number");
//	printf("% u\n", 747);
//	printf("% x\n", 784);
//	printf("% o\n", 784);
//	printf("% p\n", 784);
	return (0);
}

// int		main(int ac, char **av)
// {
// 	if (ac)

// 	ft_printf("abcd%s\n", " 1");
// 	ft_printf("efg%-15s\n", " 1");
// 	ft_printf("efg%#15s\n", " 1");
// 	ft_printf("efg%+15s\n", " 1");
// 	ft_printf("efg% 15s\n", " 1");
// 	ft_printf("efg%015s\n", " 1");
// 	ft_printf("->%c\n", 'a');
// 	ft_printf("->%s\n", "test_s");
// 	ft_printf("->%d\n", 42);
// 	ft_printf("->%-10s\n", "Salut");
// 	return (0);
// }
