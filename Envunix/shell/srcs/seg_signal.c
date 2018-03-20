/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:14:36 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:14:37 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void		seg_exit(void)
{
	ft_putstr_fd("Joshua is confused: segmentation fault  ", 2);
	ft_putendl_fd(get_name_prog(NULL), 2);
}

void			safe_exit(int a, char *str)
{
	char	c;

	c = 0;
	get_name_prog(str);
	if (a == SIGINT)
		return ;
	if (a == SIGSEGV)
		seg_exit();
}
