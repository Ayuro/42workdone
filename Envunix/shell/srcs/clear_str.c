/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:11:07 by flemaist          #+#    #+#             */
/*   Updated: 2017/03/10 16:11:08 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char		*clear_str(char *str)
{
	int			i;
	int			j;
	char		*new;

	i = 0;
	j = 0;
	if (!str || (str[0] != '\'' && str[0] != '\"'))
		return (str);
	new = ft_memalloc(ft_strlen(str) + 10);
	while (str && str[++i + 1])
	{
		if (str[i] == '\\' && str[i + 1] == '\"')
			i++;
		new[j++] = str[i];
	}
	return (new);
}
