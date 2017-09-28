/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 23:44:27 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:11:12 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**#include "../includes/ft_printf.h"
**
**void			conv_s_file(t_printf *pf)
**{
**	int		fd;
**	char	*s;
**	char	array[32];
**	int		ret;
**
**	s = va_arg(pf->ap, char *);
**	fd = open(s, O_RDONLY);
**	if (fd == -1 || -1 == read(fd, array, 1))
**		exit(-1);
**	close(fd);
**	fd = open(s, O_RDONLY);
**	while ((ret = read(fd, array, 1)) )
**		buffer(&*pf, array, ret);
**}
*/
