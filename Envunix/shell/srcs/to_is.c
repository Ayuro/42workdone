/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:17:08 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:17:08 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"

int			is_a_unescaped_quote(t_line *line)
{
	if ((line->c == '\"' || line->c == '\'') &&
		((line->prev && line->prev->c != '\\') ||
		!line->prev))
		return (1);
	return (0);
}

int			ft_is_arrow(char *buffer)
{
	if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'D')
		return (1);
	if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'A')
		return (2);
	if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'B')
		return (3);
	if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'C')
		return (4);
	return (0);
}

int			ft_is_del_or_back(char *buffer)
{
	if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == '3' &&
	buffer[3] == '~')
		return (1);
	if (buffer[0] == 127 && buffer[1] == 0)
		return (1);
	return (0);
}
