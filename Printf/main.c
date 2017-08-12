/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 23:29:04 by achambon          #+#    #+#             */
/*   Updated: 2017/08/11 15:10:33 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(int ac, char **av)
{
// TEST AVEC %d ET MINUS
//_____convminwidth < len 
/*	ft_printf("m :%-d\n", 123);
	printf("t :%-d\n", 123);
	ft_printf("m :%-1d\n", 124);
	printf("t :%-1d\n", 124);
	ft_printf("m :%-01d\n", 125);
	printf("t :%-01d\n", 125);
	ft_printf("m :%- 1d\n", 126);
	printf("t :%- 1d\n", 126);
	ft_printf("m :%+-1d\n", 127);
	printf("t :%+-1d\n", 127);
	ft_printf("m :%- 01d\n", 128);
	printf("t :%- 01d\n", 128);
	ft_printf("m :%+-01d\n", 129);
	printf("t :%+-01d\n", 129);
	ft_printf("m :%+- 01d\n", 129);
	printf("t :%+- 01d\n", 129);
//______convminwidth > len
	ft_printf("m :%-5d\n", 130);
	printf("t :%-5d\n", 130);
	ft_printf("m :%-05d\n", 131);
	printf("t :%-05d\n", 131);
	ft_printf("m :%- 5d\n", 132);
	printf("t :%- 5d\n", 132);
	ft_printf("m :%+-5d\n", 133);
	printf("t :%+-5d\n", 133);
	ft_printf("m :%- 05d\n", 134);
	printf("t :%- 05d\n", 134);
	ft_printf("m :%+-05d\n", 135);
	printf("t :%+-05d\n", 135);*/
	ft_printf("m :%+- 05d\n", 135);
	printf("t :%+- 05d\n", 135);
//________convprecision
/*	ft_printf("m :%-.5d\n", 136);
	printf("t :%-.5d\n", 136);
	ft_printf("m :%-0.5d\n", 137);
	printf("t :%-0.5d\n", 137);
	ft_printf("m :%- .5d\n", 138);
	printf("t :%- .5d\n", 138);
	ft_printf("m :%+-.5d\n", 139);
	printf("t :%+-.5d\n", 139);
	ft_printf("m :%- 0.5d\n", 140);
	printf("t :%- 0.5d\n", 140);
	ft_printf("m :%+-0.5d\n", 141);
	printf("t :%+-0.5d\n", 141);*/
	ft_printf("m :%+- 0.5d\n", 141);
	printf("t :%+- 0.5d\n", 141);
//_____convmin > convprecision
/*	ft_printf("m :%-10.5d\n", 142);
	printf("t :%-10.5d\n", 142);
	ft_printf("m :%-010.5d\n", 143);
	printf("t :%-010.5d\n", 143);
	ft_printf("m :%- 10.5d\n", 144);
	printf("t :%- 10.5d\n", 144);
	ft_printf("m :%+-10.5d\n", 145);
	printf("t :%+-10.5d\n", 145);
	ft_printf("m :%- 010.5d\n", 146);
	printf("t :%- 010.5d\n", 146);
	ft_printf("m :%+-010.5d\n", 147);
	printf("t :%+-010.5d\n", 147);*/
	ft_printf("m :%+- 010.5d\n", 147);
	printf("t :%+- 010.5d\n", 147);
//______convminwidth < convprecision
	ft_printf("m :%-5.10d\n", 148);
	printf("t :%-5.10d\n", 148);
	ft_printf("m :%-05.10d\n", 149);
	printf("t :%-05.10d\n", 149);
	ft_printf("m :%- 5.10d\n", 150);
	printf("t :%- 5.10d\n", 150);
	ft_printf("m :%+-5.10d\n", 151);
	printf("t :%+-5.10d\n", 151);
	ft_printf("m :%- 05.10d\n", 152);
	printf("t :%- 05.10d\n", 152);
	ft_printf("m :%+-05.10d\n", 153);
	printf("t :%+-05.10d\n", 153);
	ft_printf("m :%+- 05.10d\n", 154);
	printf("t :%+- 05.10d\n", 154);
//_____convminwidth == convprecision
/*	ft_printf("m :%-5.5d\n", 154);
	printf("t :%-5.5d\n", 154);
	ft_printf("m :%-05.5d\n", 155);
	printf("t :%-05.5d\n", 155);
	ft_printf("m :%- 5.5d\n", 156);
	printf("t :%- 5.5d\n", 156);
	ft_printf("m :%+-5.5d\n", 157);
	printf("t :%+-5.5d\n", 157);
	ft_printf("m :%- 05.5d\n", 158);
	printf("t :%- 05.5d\n", 158);
	ft_printf("m :%+-05.5d\n", 159);
	printf("t :%+-05.5d\n", 159);
	ft_printf("m :%+- 05.5d\n", 159);
	printf("t :%+- 05.5d\n", 159);*/

	return (0);
}
