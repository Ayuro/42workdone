/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:52:04 by flemaist          #+#    #+#             */
/*   Updated: 2017/03/10 15:55:26 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_multi_del(char **arg1, char **arg2, char **arg3, char **arg4)
{
	if (!arg1)
		ft_strdel(arg1);
	if (!arg2)
		ft_strdel(arg2);
	if (!arg3)
		ft_strdel(arg3);
	if (!arg4)
		ft_strdel(arg4);
}
