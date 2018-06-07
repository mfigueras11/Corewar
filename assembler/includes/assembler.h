/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:57:57 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/07 15:09:09 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"

#define IND_SIZE 2
#define REG_SIZE 4
#define DIR_SIZE REG_SIZE


#define REG_CODE 1
#define DIR_CODE 2
#define IND_CODE 3


#define MAX_ARGS_NUMBER 4
#define MAX_PLAYERS 4
#define MEM_SIZE (4 * 1024)
#define IDX_MOD (MEM_SIZE / 8)
#define CHAMP_MAX_SIZE (MEM_SIZE / 6)

#define COMMENT_CHAR '#'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','

#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"

#define REG_NUMBER 16

#define CYCLE_TO_DIE 1536
#define CYCLE_DELTA 50
#define NBR_LIVE 21
#define MAX_CHECKS 10

typedef char t_arg_type;

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

#define PROG_NAME_LENGTH (128)
#define COMMENT_LENGTH (2048)
#define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct	header_s
{
	unsigned int magic;
	char prog_name [PROG_NAME_LENGTH + 1];
	unsigned int prog_size;
	char how [COMMENT_LENGTH + 1];
}				header_t;

typedef struct	line_s
{
	char			*label;
	char			*opname;
	char			*params[3];
	struct line_s	*next;
	struct line_s	*prev;
}				line_t;

typedef struct	frame_s
{
	line_t		*lines;
	header_t	*header;
}				line_t;

int				ft_input(int fd);
int				ft_line(char *s);
int				ft_header(char *s, int name, int fd);
#endif
