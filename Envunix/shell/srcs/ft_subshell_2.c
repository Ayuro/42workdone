/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subshell_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:04:59 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:04:59 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_export		*ft_exportdup(t_export *exp)
{
	t_export	*tmp;
	t_export	*newexp;

	tmp = exp;
	newexp = NULL;
	while (tmp)
	{
		newexp = ft_add_export(newexp, tmp->export_env, tmp->display);
		if (newexp)
			newexp->status = tmp->status;
		tmp = tmp->next;
	}
	return (newexp);
}

t_e				*ft_envdup(t_e *e)
{
	t_e			*tmp;
	t_e			*env;
	int			i;

	i = 0;
	tmp = e;
	env = NULL;
	while (tmp)
	{
		env = ft_add_e(env, tmp->str);
		if (i == 0 && env)
		{
			env->export = ft_exportdup(tmp->export);
			env->ret = tmp->ret;
			env->op = tmp->op;
			env->status = tmp->status;
		}
		if (tmp->err && i == 0)
			env->err = ft_strdup(tmp->err);
		i++;
		tmp = tmp->next;
	}
	return (env);
}

char			*delete_subshell(char *cmd, int begin)
{
	int		i;

	i = begin;
	while (cmd && cmd[i] && cmd[i] != ')')
		i++;
	return (ft_strsub(cmd, begin, i - begin > 0 ? i - begin : 0));
}
