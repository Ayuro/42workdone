/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:55:22 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:55:23 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static void	exit_failure_exitmode(t_bool exitmode)
{
	if (exitmode == TRUE)
		exit(-1);
}

int			exit_failure_malloc(void)
{
	ft_putstr_fd(ERR_PNAME, STDERR);
	ft_putendl_fd(ERR_MALLOC, STDERR);
	exit_failure_exitmode(TRUE);
	return (RET_FAIL);
}

int			exit_failure_1s(char *s, t_bool exitmode)
{
	ft_putstr_fd(ERR_PNAME, STDERR);
	ft_putendl_fd(s, STDERR);
	exit_failure_exitmode(exitmode);
	return (RET_FAIL);
}

int			exit_failure_2s(char *s1, char *s2, t_bool exitmode)
{
	ft_putstr_fd(ERR_PNAME, STDERR);
	ft_putstr_fd(s1, STDERR);
	ft_putendl_fd(s2, STDERR);
	exit_failure_exitmode(exitmode);
	return (RET_FAIL);
}

int			exit_failure_3s(char *s1, char *s2, char *s3, t_bool exitmode)
{
	ft_putstr_fd(ERR_PNAME, STDERR);
	ft_putstr_fd(s1, STDERR);
	ft_putstr_fd(s2, STDERR);
	ft_putendl_fd(s3, STDERR);
	exit_failure_exitmode(exitmode);
	return (RET_FAIL);
}
