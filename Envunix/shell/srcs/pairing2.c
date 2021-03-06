/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:10:04 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:10:04 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"

int			is_not_paired(int *inquotes, int *paired, t_line *line)
{
	if ((inquotes[1] && line->c != '\"') || (inquotes[0] && line->c != '\'') ||
			(!inquotes[0] && !inquotes[1]))
		if (line->paired == 0)
			if (!(*paired = search_pair(line->next, reverse_pair(line->c))))
				if (line->c)
					if (((line->prev && line->prev->c != '\\') || !line->prev))
						return (1);
	return (0);
}

void		check_quotes(t_line *line, int *inquotes)
{
	if ((line && line->c == '\"') && !inquotes[1] && !inquotes[0])
		inquotes[0] = 1;
	else if ((line && line->c == '\"') && inquotes[0])
		inquotes[0] = 0;
	if ((line && line->c == '\'') && !inquotes[0] && !inquotes[1])
		inquotes[1] = 1;
	else if ((line && line->c == '\'') && inquotes[1])
		inquotes[1] = 0;
}

int			is_paired(int *inquotes, char *find, int paired, t_line *line)
{
	if (!inquotes[0] && !inquotes[1])
		if (find)
			if (paired)
				if ((line->prev && line->prev->c != '\\') || !line->prev)
					return (1);
	return (0);
}

int			is_in_quotes(int *quotes, t_line *line)
{
	return (!quotes[0] && line->c != '\"') || (!quotes[1] && line->c != '\'');
}
