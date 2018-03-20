/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_quote_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:10:33 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/13 14:10:34 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		spec_char(char c)
{
	if (c == '$' || c == '`' || c == '|' || c == '>' || c == '<'
		|| c == '[' || c == ']')
		return (1);
	return (0);
}

static void		add_slash(char *str, int *id)
{
	str[*id] = 92;
	*id = *id + 1;
}

char			*replace_space(char *str)
{
	int			i;
	int			id;
	char		*newstr;

	i = 0;
	id = 0;
	if (!str)
		return (NULL);
	newstr = (char*)ft_memalloc(sizeof(char) * ft_strlen(str) * 2);
	while (newstr && str[i])
	{
		if (spec_char(str[i]))
			add_slash(newstr, &id);
		newstr[id] = str[i];
		id++;
		i++;
	}
	ft_strdel(&str);
	newstr[id - 1] = 0;
	return (newstr);
}
