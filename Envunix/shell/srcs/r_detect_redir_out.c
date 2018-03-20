/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_detect_redir_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:10:37 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:10:37 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void		get_fd_redir_out(char *redir, int *i, int *fd, int *append)
{
	if (ft_isdigit(redir[*i]))
	{
		*fd = redir[*i] - '0';
		redir[(*i)++] = ' ';
	}
	if (redir[*i] == '>' && redir[*i + 1] == '>')
	{
		*append = 1;
		redir[(*i)++] = ' ';
		redir[(*i)++] = ' ';
	}
	else
		redir[(*i)++] = ' ';
	if (redir[*i] == '&')
	{
		redir[(*i)++] = ' ';
		*fd = 3;
	}
}

int				detect_redir_out(char *redir)
{
	int		i;
	int		fd;
	int		append;
	char	*to_redir;

	i = 0;
	fd = 1;
	append = 0;
	to_redir = NULL;
	get_fd_redir_out(redir, &i, &fd, &append);
	while (redir[i] && ft_isspace(redir[i]))
		i++;
	if (!redir[i])
		return (NEED_FILENAME);
	to_redir = get_name_of_redir(redir, i);
	return (redirection_out(fd, to_redir, append));
}
