/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_temp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:12:06 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/13 14:12:07 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"
#include "../include/minishell.h"

t_export	*ft_export_error(char *cmd, t_export *env)
{
	if (env)
		env->status = 256;
	ft_putstr_fd(cmd + 1, 2);
	ft_putendl_fd(": command not found", 2);
	return (env);
}

t_export	*ft_is_exist(t_export *e, char *s)
{
	t_export	*tmp;

	tmp = e;
	if (!tmp)
	{
		ft_strdel(&s);
		return (NULL);
	}
	while (tmp)
	{
		if (ft_start_str(s, tmp->export_env))
		{
			ft_strdel(&s);
			return (tmp);
		}
		tmp = tmp->next;
	}
	ft_strdel(&s);
	free(tmp);
	return (NULL);
}

t_export	*ft_modif_export(t_export *e, t_export *mod, char *s, int check)
{
	char		*tmp;

	if (!mod)
		return (e);
	ft_strdel(&(mod->export_env));
	if (check == 0)
	{
		tmp = ft_strjoin(s, "''");
		mod->export_env = tmp;
	}
	else
		mod->export_env = ft_strdup(s);
	mod->display = true;
	free(tmp);
	return (e);
}

t_export	*ft_export_condition(t_export *e, char *s, char *t)
{
	t_export	*find;
	char		*tmp;

	tmp = NULL;
	if (!t || !(tmp = ft_str_trunc(s, '=')))
		return (e);
	if (!t[0])
	{
		if (!(find = ft_is_exist(e, tmp)))
			e = ft_export_temp2(e, s);
		else
			e = ft_modif_export(e, find, s, 0);
	}
	else
	{
		if (!(find = ft_is_exist(e, tmp)))
			e = ft_add_export(e, s, false);
		else
			e = ft_modif_export(e, find, s, 1);
	}
	free(tmp);
	return (e);
}

t_export	*ft_export_temp(char **t, char *cmd, t_export *env, t_e *e)
{
	char		*tmp;
	int			i;
	int			off;

	i = -1;
	off = 0;
	while (t[++i])
	{
		if (!back_strchr(t[i], '='))
			break ;
		if (t[i][0] == '=')
			return (ft_export_error(t[i], env));
		tmp = no_char(t[i], '=');
		env = ft_export_condition(env, t[i], tmp);
		off += ft_strlen(t[i]);
	}
	if (t[i])
		e = ft_exec_cmd(cmd + off, e, -1);
	free(tmp);
	return (env);
}
