/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:08:08 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:08:08 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"

void		add_word_to_line(char *to_add, t_le *le)
{
	int			i;

	i = -1;
	while (to_add && to_add[++i])
		add_to_line(le, &(le->line), to_add[i]);
}

t_line		*cut_line_for_hist(t_line *line)
{
	int		i;
	t_line	*first;

	i = 0;
	first = line;
	while (++i < 1024 && line)
		line = line->next;
	if (line)
	{
		clear_line(line->next);
		line->next = NULL;
	}
	return (first);
}

t_line		*cpy_line(t_line *line)
{
	t_line	*cpy;
	t_line	*tmp;

	cpy = ft_memalloc(sizeof(t_line));
	line = line->next;
	tmp = cpy;
	while (line)
	{
		tmp->next = ft_memalloc(sizeof(t_line));
		tmp->next->c = line->c;
		tmp->next->prev = tmp;
		tmp = tmp->next;
		line = line->next;
	}
	return (cpy);
}

void		clear_line(t_line *line)
{
	t_line	*jeanclaude;

	jeanclaude = line;
	if (line && !(line->next))
	{
		free(line);
		if (!jeanclaude)
			free(jeanclaude);
		return ;
	}
	while (line && line->next)
	{
		jeanclaude = line;
		line = line->next;
		free(jeanclaude);
	}
	free(line);
	line = NULL;
}
