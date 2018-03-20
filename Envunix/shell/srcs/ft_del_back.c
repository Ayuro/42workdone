/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:11:18 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/13 14:11:19 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char		*ft_del_back(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	new = ft_memalloc(ft_strlen(str));
	while (str[++i])
	{
		if (str[i] != '\\')
			new[j++] = str[i];
	}
	return (new);
}
