/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subshell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:43:28 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 14:43:28 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_word			*first_subsh(int flag)
{
	static t_word	*new;

	if (!new)
		new = ft_memalloc(sizeof(t_word));
	if (flag == RES)
	{
		clear_words(new);
		new = NULL;
	}
	return (new);
}

void			cpy_sub_to_word(t_word *subsh, char **cmd, int id, char *tmp)
{
	int		i;

	i = 0;
	while (tmp && *cmd != tmp + 1)
	{
		subsh->word[i++] = **cmd;
		if (**cmd != '(' && **cmd != ')')
			**cmd = id;
		(*cmd)++;
	}
}

t_word			*replace_subshell(char *cmd, char id)
{
	char	*tmp;
	t_word	*subsh;

	id = 'a';
	subsh = NULL;
	while (*cmd)
	{
		if (*cmd == '(')
		{
			tmp = ft_strchr(cmd, ')');
			if (!subsh)
				subsh = first_subsh(RET);
			else
			{
				subsh->next = ft_memalloc(sizeof(t_word));
				subsh = subsh->next;
			}
			subsh->word = ft_memalloc(tmp - cmd + 2);
			cpy_sub_to_word(subsh, &cmd, id, tmp);
			id++;
		}
		cmd++;
	}
	return (subsh);
}

char			*get_subshell(char *cmd)
{
	t_word		*subsh;

	subsh = first_subsh(RET);
	if (!subsh)
		return (ft_strdup(""));
	ft_strcpy(cmd, subsh->word);
	first_subsh(RES);
	return (cmd);
}

void			do_subshell(t_e *e, char *cmd)
{
	int			i;
	t_e			*backup;
	char		*newcmd;

	i = 0;
	if (!cmd || !e)
		return ;
	while (cmd && cmd[i] && ft_isspace(cmd[i]))
		i++;
	if (!check_subshell_error(cmd + i))
		return ;
	backup = ft_envdup(e);
	cmd = get_subshell(cmd);
	newcmd = delete_subshell(cmd, i + 1);
	if (!newcmd)
		malloc_handling();
	backup = ft_exec_cmd(newcmd, backup, -1);
	free(newcmd);
}
