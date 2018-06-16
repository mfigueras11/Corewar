/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:44:29 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/14 22:54:18 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			setup_ops(t_op_code *table)
{
	table[454501] = &op_live;
	table[1764] = &op_ld;
	table[1908] = &op_st;
	table[26468] = &op_add;
	table[30578] = &op_sub;
	table[26596] = &op_and;
	table[1778] = &op_or;
	table[32498] = &op_xor;
	table[519920] = &op_zjmp;
	table[28265] = &op_ldi;
	table[30569] = &op_sti;
	table[421739] = &op_fork;
	table[28388] = &op_lld;
	table[454249] = &op_lldi;
	table[7237483] = &op_lfork;
	table[26470] = &op_aff;
}

static t_op_code	get_op(long op_code)
{
	static t_op_code	table[7237484];

	if (op_code < 1 || op_code > 7237483)
		return (NULL);
	if (!table[1764])
		setup_ops(table);
	return (table[op_code]);
}

static long			hash_name(char *name)
{
	long			hash;

	if (!name)
		return (0);
	hash = 0;
	while (*name)
	{
		hash = hash << 4;
		hash |= *name;
		name++;
	}
	return (hash);
}

static void			move_to_next_op(t_vm *vm, t_process *ps)
{
	int				op_code;
	t_op			*seek;

	while (1)
	{
		get_next_bytes(vm, ps, &op_code, 1);
		seek = g_op_tab;
		while (seek->op_code)
		{
			if (op_code == seek->op_code)
			{
				ps->pc = ps->pc_tmp;
				return ;
			}
			seek++;
		}
	}
}

void				do_op(t_vm *vm, t_process *ps, int op_code)
{
	t_op_code		op_function;
	t_op			*seek;

	seek = g_op_tab;
	while (seek->op_code && seek->op_code != op_code)
		seek++;
	if (!(op_function = get_op(hash_name(seek->name))))
	{
		move_to_next_op(vm, ps);
		ps->sleep_cycles = 1;
	}
	else
	{
		op_function(vm, ps);
		ps->sleep_cycles = seek->nb_cycles;
	}
}
