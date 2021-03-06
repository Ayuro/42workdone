/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:10:21 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/13 14:10:21 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char		*adjust_to_back_quote(const char *s, char **one, char **two)
{
	int			i;
	int			begin;
	int			end;

	end = 0;
	begin = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == '`')
		{
			if (!begin)
				begin = i + 1;
			else if (!end)
				end = i;
		}
		i++;
	}
	*one = ft_strsub(s, 0, begin - 1 < 0 ? 0 : begin - 1);
	*two = ft_strsub(s, end + 1, i - end < 0 ? 0 : i - end);
	return (ft_strsub(s, begin, end - begin < 0 ? 0 : end - begin));
}

static char		*concat_all_bq(int fd, int bq)
{
	char		*final;
	char		str[100];
	int			ret;

	final = "";
	str[0] = 0;
	ft_bzero(str, sizeof(str));
	while ((ret = read(fd, str, 100)) == 100)
	{
		final = ft_strjoin(final, str);
		ft_bzero(str, sizeof(str));
	}
	if (read(fd, str, 100) != -1)
		final = ft_strjoin(final, str);
	if (bq)
		return (replace_space(final));
	return (final);
}

static char		*ret_final_back_quote(char **cmdfirst, char **cmdsecond,
	char **cmd)
{
	char		*final;
	char		*ret;

	final = ft_strjoin(*cmdfirst, *cmd);
	ret = ft_strjoin(final, *cmdsecond);
	ft_strdel(&final);
	final = ret;
	ret = ft_strjoin(ret, " ");
	ft_multi_del(&final, cmd, cmdfirst, cmdsecond);
	return (ret);
}

void			ft_back_quote(char *s, t_e *e)
{
	char		*cmd;
	int			fd[2];
	char		*cmdfirst;
	char		*cmdsecond;

	cmd = adjust_to_back_quote(s, &cmdfirst, &cmdsecond);
	pipe(fd);
	if (fork() == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		ft_exec_cmd(cmd, e, -1);
		cmd = NULL;
		ft_multi_del(&cmd, &cmdfirst, &cmdsecond, NULL);
		exit(1);
	}
	else
	{
		ft_strdel(&cmd);
		cmd = concat_all_bq(fd[0], 1);
		wait(NULL);
	}
	close(fd[0]);
	close(fd[1]);
	e = ft_exec_cmd(ret_final_back_quote(&cmdfirst, &cmdsecond, &cmd), e, -1);
}

char			*ft_replace_back_quote(char *s, t_e *e)
{
	char		*cmd;
	int			fd[2];
	char		*cmdfirst;
	char		*cmdsecond;

	cmd = adjust_to_back_quote(s, &cmdfirst, &cmdsecond);
	pipe(fd);
	if (fork() == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		ft_exec_cmd(cmd, e, -1);
		ft_multi_del(&cmd, &cmdfirst, &cmdsecond, NULL);
		exit(1);
	}
	else
	{
		ft_strdel(&cmd);
		cmd = concat_all_bq(fd[0], 0);
		wait(NULL);
	}
	close(fd[0]);
	close(fd[1]);
	ft_strdel(&s);
	return (ret_final_back_quote(&cmdfirst, &cmdsecond, &cmd));
}
