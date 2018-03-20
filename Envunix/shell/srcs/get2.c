/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:05:39 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:05:39 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char		*get_name_prog(char *str)
{
	static char		*ret = NULL;

	if (str)
		ret = str;
	return (ret);
}

t_e			*get_t_env(t_e *e)
{
	static t_e	*ori_e = NULL;

	if (!ori_e)
		ori_e = e;
	return (ori_e);
}

t_le		*get_t_le(t_le *le)
{
	static t_le	*ori_le = NULL;

	if (!ori_le)
		ori_le = le;
	return (ori_le);
}

t_line		*get_orig_line(t_line *line)
{
	while (line && line->is_orig == 0)
		line = line->prev;
	return (line->next);
}
