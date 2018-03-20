/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_redir_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:11:22 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:11:22 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		redir_error(int err)
{
	ft_putstr_fd("Joshua is confused : Redirection : ", 2);
	if (err == BAD_FD)
		ft_putstr_fd("bad filedescriptor\n", 2);
	else if (err == PARSE_ERROR)
		ft_putstr_fd("parse error\n", 2);
	else if (err == NEED_FILENAME)
		ft_putstr_fd("no filename\n", 2);
	else if (err == AMBIGUOUS_REDIR)
		ft_putstr_fd("ambiguous redirect\n", 2);
	else if (err == IS_NOT_VALID)
		ft_putstr_fd("impossible to redir this file\n", 2);
	else if (err == OPEN_ERROR)
		ft_putstr_fd("impossible to open this file\n", 2);
	reset_term();
	exit(EXIT_FAILURE);
}
