/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:51:26 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/07 14:40:16 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_valid_line(char *s, int fd)
{
	char	*str;
	char	*tmp;
	int		ret;

	if (!s)
		return (1);
	if (!(str = ft_strtrim(s)))
		return (0);
	ret = 1;
	if (tmp = ft_strchr(str, COMMENT_CHAR))
		*tmp = '\0';
	if (ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
		ret = ft_header(str, 1, fd);
	if (ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
		ret = ft_header(str, 0, fd);
	else if (*str != '\0')
		ret = ft_line(str);
	ft_strdel(&str);
	return (ret);
}

int		ft_input(int fd)
{
	char	*str;

	while (get_next(fd, &str, '\n'))
	{
		if (!ft_valid_line(str, fd))
		{
			ft_strdel(&str);
			return (0);
		}
		ft_strdel(&str);
	}
	if (str)
		ft_strdel(&str);
	return ((str) ? 0 : 1);
}
