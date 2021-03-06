/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:07:30 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 14:07:32 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_word(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) || ((str[i] == '\'' || str[i] == '\"')
													&& str[i - 1] != '\\'))
			break ;
		i++;
	}
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

static int	until_pair(char *str, char pair)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == pair && str[i - 1] != '\\')
			break ;
		i++;
	}
	if (str[i])
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

int			ft_word_counter(char *str)
{
	int		i;
	int		word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if ((str[i] == '\"' || str[i] == '\'') &&
				(((i - 1) >= 0 && str[i - 1] != '\\') || i == 0))
			i += until_pair(str + i, str[i]);
		else if (str[i] != '\"' && str[i] != '\'' && !ft_isspace(str[i]))
			i += skip_word(str + i);
		word_count++;
	}
	return (word_count);
}
