/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_error2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:01:40 by flemaist          #+#    #+#             */
/*   Updated: 2017/03/10 16:01:45 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"
#include "../include/minishell.h"

int		is_empty(char *s)
{
	int		i;

	i = -1;
	if (!s)
		return (0);
	while (s && s[++i])
		if (!ft_isspace(s[i]))
			return (0);
	return (1);
}

int		is_redir(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

int		print_red_error(char *s, int i, int check)
{
	if (check < 0)
	{
		if (check == -1)
			ft_putendl_fd("Joshua is confused: ambiguous output redirect", 2);
		else
			ft_putendl_fd("Joshua is confused: null argument between \
redirection", 2);
		return (-1);
	}
	ft_putstr_fd("Joshua is confused: parse error near `", 2);
	if (i == -1)
	{
		ft_putchar_fd(s[0], 2);
		if (s[1] && s[1] == s[0])
			ft_putchar_fd(s[0], 2);
	}
	else
	{
		ft_putchar_fd(s[i - check], 2);
		if (s[i - check + 1] == s[i - check])
			ft_putchar_fd(s[i - check + 1], 2);
	}
	ft_putstr_fd("'\n", 2);
	return (-1);
}
