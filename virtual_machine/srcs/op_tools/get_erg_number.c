/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:40:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/19 14:50:09 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int					get_reg_number(int reg)
{
	if (reg < 1 || reg > REG_NUMBER)
		return (0);
	return (reg);
}
