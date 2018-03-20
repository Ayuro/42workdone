/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shrc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:09:47 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/13 14:09:47 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_e		*exec_cmd_shrc(t_e *e, int fd)
{
	char	*line;

	line = NULL;
	if (!e)
		return (e);
	while (get_next_line(fd, &line) > 0)
	{
		e = ft_exec_cmd(line, e, -1);
		ft_strdel(&line);
	}
	return (e);
}

t_e				*exec_shrc(t_e *e)
{
	int		fd;
	char	*tmp;

	if (!e)
		return (e);
	if (!(tmp = getenv("HOME")))
		tmp = "";
	tmp = ft_strjoin(tmp, "/.42shrc");
	if (!tmp)
		malloc_handling();
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		free(tmp);
		return (e);
	}
	free(tmp);
	return (exec_cmd_shrc(e, fd));
}
