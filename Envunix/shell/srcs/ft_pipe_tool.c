/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:41:58 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 14:41:58 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			get_ret(int ret)
{
	static int		newret = -12;

	if (ret != -12)
		newret = ret;
	return (newret);
}

void		child_handler(int sig)
{
	pid_t			pid;
	int				status;
	int				i;

	i = 0;
	(void)sig;
	while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
	{
		kill(pid, SIGKILL);
		get_ret(status);
	}
}

int			ft_pipe_parse_error(char *s)
{
	if (!s || s[0] == '|' || double_red(s, '|') == 1)
	{
		ft_putendl_fd("Joshua is confused: parse error near `|'", 2);
		return (1);
	}
	return (0);
}
