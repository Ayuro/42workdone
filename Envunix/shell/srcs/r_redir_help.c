/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_redir_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:11:29 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:11:29 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			is_a_redir(char a)
{
	if (a == '>')
		return (1);
	if (a == '<')
		return (1);
	return (0);
}

char		*until_redir(char *file)
{
	int		i;
	char	buffer[4096];
	char	*tmp;

	i = -1;
	ft_bzero(buffer, sizeof(buffer));
	if (file[0] == '\'' || file[0] == '\"')
	{
		tmp = ft_strdup(file);
		free(file);
		file = ft_memalloc(1);
		return (tmp);
	}
	while (file[++i] && !is_a_redir(file[i]))
	{
		buffer[i] = file[i];
		file[i] = ' ';
	}
	free(tmp);
	return (ft_strdup(buffer));
}

int			word_before_redir(char *str, int i)
{
	if (!ft_isdigit(str[i]) && i > 0)
		return (1);
	while (i >= 0)
	{
		if (!ft_isspace(str[i]) && str[i] != ';')
			return (1);
		i--;
	}
	return (PARSE_ERROR);
}
