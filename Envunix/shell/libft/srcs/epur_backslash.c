/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_backslash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:11:47 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 14:11:49 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		epur_len(char *s)
{
	int		i;
	int		n;

	n = 0;
	i = -1;
	while (s[++i])
		if (s[i] == '\\' && !ft_backslash_check(s, i))
		{
			n++;
		}
	return (i - n + 1);
}

char	*epur_backslash(char *s)
{
	int		i;
	int		n;
	char	*new;

	if (!s || !(new = ft_memalloc(sizeof(char) * epur_len(s))))
		return (NULL);
	i = -1;
	n = 0;
	while (s[++i])
	{
		if (s[i] != '\\')
		{
			new[n] = s[i];
			n++;
		}
		else if (s[i + 1] && s[i + 1] == '\\')
		{
			i++;
			new[n] = s[i];
			n++;
		}
	}
	ft_strdel(&s);
	return (new);
}
