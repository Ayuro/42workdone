/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_check_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:12:34 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:12:35 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				error_bracket_if(void)
{
	ft_putstr_fd("Joshua is confused: [: too many arguments\n", 2);
	return (-1);
}

int				ft_isnum(char *str)
{
	int			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int				check_condition_num_if(char **arg, int i)
{
	if (i == 0 || !arg[i + 1] || !ft_isnum(arg[i + 1]) || !ft_isnum(arg[i - 1]))
	{
		ft_putstr_fd("Joshua is confused: integer expression expected\n", 2);
		return (0);
	}
	return (10);
}

int				check_condition_alpha_if(char **arg, int i)
{
	if (i == 0 || !arg[i + 1] || !arg[i - 1])
	{
		ft_putstr_fd("Joshua is confused: expression expected\n", 2);
		return (0);
	}
	return (5);
}

int				check_condition_file_if(char **arg, int i)
{
	if (i != 0 || !arg[i + 1])
	{
		ft_putstr_fd("Joshua is confused: parse error: expected two \
arguments\n", 2);
		return (0);
	}
	return (1);
}
