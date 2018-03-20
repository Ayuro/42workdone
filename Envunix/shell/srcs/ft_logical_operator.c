/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logical_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:40:15 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 14:40:15 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"
#include "../include/minishell.h"

t_e		*op_err(t_e *env, char c)
{
	if (env)
		env->status = 127;
	ft_putstr_fd("Joshua is confused: parse error near `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
	return (env);
}

char	next_operator(char *s)
{
	int		i;

	i = -1;
	while (s && s[++i])
		if (s[i + 1] && (s[i] == '&' || s[i] == '|')
				&& s[i] == s[i + 1])
			return (s[i]);
	return ('\0');
}

t_e		*logical_exec(char *s, char op, t_e *env)
{
	char	*cmd;

	if (op != '\0')
		cmd = ft_sdouble_trunc(s, op);
	else
		cmd = s;
	env = ft_exec_cmd(cmd, env, -1);
	if (op != '\0')
		ft_strdel(&cmd);
	return (env);
}

t_e		*ft_logical_operator(char *s, t_e *env, int n)
{
	int		i;
	char	c;
	char	c2;
	char	*tmp;

	i = -1;
	if (!s || s[0] == '&' || s[0] == '|')
		return (op_err(env, s[0]));
	tmp = s;
	while (++i <= n)
	{
		c = next_operator(tmp);
		if (i == 0)
			env = logical_exec(tmp, c, env);
		tmp = no_double_char(tmp, c);
		c2 = next_operator(tmp);
		if (c == '\0')
			break ;
		if (c == '&' && env->status == 0)
			env = logical_exec(tmp, c2, env);
		else if (c != '&' && env->status != 0)
			env = logical_exec(tmp, c2, env);
	}
	ft_strdel(&tmp);
	return (env);
}
