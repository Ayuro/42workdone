/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subshell_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:05:06 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:05:07 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	err(int e, char *cmd)
{
	if (e == 0)
	{
		ft_putstr_fd("Joshua is confused: syntax error near unexpected \
token `", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("'\n", 2);
	}
	return (0);
}

int			check_subshell_full(char *cmd)
{
	int		i;

	i = 0;
	if (!back_strchr(cmd, '('))
		return (1);
	while (cmd && cmd[i] && ft_isspace(cmd[i]))
		i++;
	if (!check_subshell_error(cmd + i))
		return (0);
	return (1);
}

int			check_subshell_error(char *cmd)
{
	int		i;

	i = 0;
	if (cmd[i] != '(')
		return (err(0, cmd + i));
	while (cmd[i] && cmd[i] != ')')
		i++;
	if (!cmd[i])
		return (0);
	i++;
	while (cmd[i] && ft_isspace(cmd[i]))
		i++;
	if (cmd[i])
		return (err(0, cmd + i));
	return (1);
}

int			is_subshell(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i] && cmd[i] != '(')
		i++;
	if (cmd[i] != '(')
		return (0);
	return (1);
}

int			first_subshell(int a)
{
	static int		sub = 0;

	if (a == 0)
		sub++;
	if (a == -1)
		sub = 0;
	return (sub);
}
