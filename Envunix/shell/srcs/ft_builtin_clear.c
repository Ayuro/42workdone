/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:10:48 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/13 14:10:49 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/edit_line.h"

void	ft_builtin_clear(void)
{
	tputs(tgetstr("ho", NULL), 0, ft_putint);
	tputs(tgetstr("cd", NULL), 0, ft_putint);
}
