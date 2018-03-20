/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_check_if_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:13:09 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:13:09 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				check_then_fi_present(char **arg)
{
	if (!arg || !arg[0])
		return (0);
	if (!arg[1])
	{
		ft_putstr_fd("Joshua is confused: missing `then'\n", 2);
		return (0);
	}
	if (!arg[2])
	{
		ft_putstr_fd("Joshua is confused: missing `fi'\n", 2);
		return (0);
	}
	return (1);
}

int				check_then_fi_helper(int nb_then, int check)
{
	if ((check - nb_then) < 0)
	{
		ft_putstr_fd("Joshua is confused: missing `fi'\n", 2);
		return (0);
	}
	return (1);
}
