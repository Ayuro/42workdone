/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_check_until.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:13:24 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:13:24 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		check_until(char **arg)
{
	if (!check_do_done(arg))
		return (0);
	return (1);
}
