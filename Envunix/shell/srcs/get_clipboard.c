/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clipboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:05:49 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:05:50 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"

void		clipboard_to_line(char *first_chars, t_le *le)
{
	char	buffer[1024];
	int		i;

	i = -1;
	while (first_chars[++i])
	{
		if (ft_isprint(first_chars[i]) && !ft_isspace(first_chars[i]))
			add_to_line(le, &(le->line), first_chars[i]);
		else if (ft_isprint(first_chars[i]) && ft_isspace(first_chars[i]))
			add_to_line(le, &(le->line), ' ');
	}
	i = -1;
	ft_bzero(buffer, sizeof(buffer));
	read(0, buffer, 1023);
	while (buffer[++i])
	{
		if (ft_isprint(buffer[i]) && !ft_isspace(buffer[i]))
			add_to_line(le, &(le->line), buffer[i]);
		else if (ft_isprint(buffer[i]) && ft_isspace(buffer[i]))
			add_to_line(le, &(le->line), ' ');
	}
}
