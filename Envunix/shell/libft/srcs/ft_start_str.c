/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:19:41 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 13:19:42 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start_str(char *start, char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!start || !s)
		return (0);
	tmp = ft_strdup(s);
	tmp = epur_backslash(tmp);
	if (!tmp)
		return (0);
	while (start[i] && tmp[i])
	{
		if (start[i] != tmp[i])
		{
			ft_strdel(&tmp);
			return (0);
		}
		i++;
	}
	if (!s[i] && tmp[i])
		i = 0;
	else
		i = 1;
	ft_strdel(&tmp);
	return (i);
}
