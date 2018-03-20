/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:08:00 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:08:01 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"

int				end_is_not_in_line(t_le *le, char *end)
{
	char		*tmp;

	tmp = to_string(get_orig_line(le->line), NORMAL);
	if (ft_strcmp(tmp, end) && !le->sig)
	{
		free(tmp);
		return (1);
	}
	if (!tmp)
		free(tmp);
	return (0);
}
