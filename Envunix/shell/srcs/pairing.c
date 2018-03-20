/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:09:47 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:09:56 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"

/*
***		Parsing d'appairage
*/

static int		pipe_is_alone(t_line *line)
{
	while (line)
	{
		if (line->c == '|')
		{
			while (line)
			{
				if (line->c != ' ' && line->c != '\0' && line->c != '|' &&
																line->c != '\n')
					break ;
				line = line->next;
			}
			if (!line)
				return (1);
		}
		line = line->next;
	}
	return (0);
}

static char		*pair_index(char *str)
{
	if (*str == ')' || *str == '}')
		return (str - 3);
	return (str);
}

char			reverse_pair(char c)
{
	if (c == '{')
		return ('}');
	else if (c == '(')
		return (')');
	else if (c == '[')
		return (']');
	return (c);
}

int				search_pair(t_line *line, char f)
{
	while (line)
	{
		if (line->c == f && line->prev && line->prev->c != '\\')
		{
			line->paired = 1;
			return (1);
		}
		line = line->next;
	}
	return (0);
}

char			*missing_pair(t_line *line, int *inquotes)
{
	static char		prompts[7][10] = {"quote> ", "dquote> ", "subsh> ",\
										"cursh> ", "bquote> ", "glob> ",\
										"pipe> "};
	static char		missing[7] = "\'\"({`[";
	char			*find;
	int				paired;
	t_line			*first;

	first = line;
	while (line)
	{
		paired = 0;
		if ((find = ft_strchr(missing, line->c)) &&
							is_not_paired(inquotes, &paired, line) &&
							is_in_quotes(inquotes, line))
			return (prompts[pair_index(find) - missing]);
		else if (is_paired(inquotes, find, paired, line))
			line->paired = 1;
		check_quotes(line, inquotes);
		line = line->next;
	}
	if (!find)
		ft_strdel(&find);
	return (pipe_is_alone(first) ? prompts[6] : NULL);
}
