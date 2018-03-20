/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_redir2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:09:31 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:09:31 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"
#include "../include/minishell.h"

int		count_red_help(char *s)
{
	int		i;
	int		n;
	bool	c;

	i = -1;
	n = 0;
	c = false;
	while (s[++i])
	{
		if (s[i] == '>' && i > 0 && s[i - 1] != '>'
				&& !ft_backslash_check(s, i))
		{
			if (!c)
				c = true;
			else
				n++;
		}
		else if (!ft_isalnum(s[i]) && !ft_isspace(s[i])
				&& !ft_backslash_check(s, i))
			break ;
	}
	return (n);
}

char	*ret_next(char *s, int i)
{
	int		n;

	n = 0;
	while (i >= 0)
	{
		while (s[n] && s[n] == '>' && !ft_backslash_check(s, i))
			n++;
		while (s[n] && (s[n] != '>' || (s[n] == '>'
						&& ft_backslash_check(s, n))))
			n++;
		i--;
	}
	return (s + n);
}

t_e		*ft_redir_loop(t_e *e, char *s)
{
	pid_t	pid;
	int		status;
	int		err;
	int		std_copy;

	status = 0;
	if ((pid = fork()))
		waitpid(pid, &status, WUNTRACED | WCONTINUED);
	else
	{
		std_copy = dup(0);
		if ((err = loop_redir(s, std_copy)))
			redir_error(err);
		ft_exec_cmd(s, e, -1);
		exit(0);
	}
	e = ret_env_err(e, status);
	return (e);
}
