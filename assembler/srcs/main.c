/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:35:56 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/07 14:20:25 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		return (ft_printf("ERROR"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_printf("Can not process file"));
	if (!ft_input(fd))
		return (ft_printf("ERROR"));
	if (close(fd) == -1)
		return (ft_printf("Can not process file"));
	return (0);
}
