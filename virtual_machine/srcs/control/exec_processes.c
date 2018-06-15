/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:54:49 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/15 02:34:13 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void		exec_process(t_vm *vm, t_process *ps)
{
	printf("Executing %x | pc  %d | carry %d\n", ps->number, ps->pc, ps->carry);//
	ps->pc_tmp = ps->pc;
	do_op(vm, ps, (int) vm->memory[ps->pc]);
}

void			exec_processes(t_vm *vm)
{
	t_process	*ps;

	ps = vm->process;
	while (ps)
	{
		exec_process(vm, ps);
		ps = ps->next;
	}
}