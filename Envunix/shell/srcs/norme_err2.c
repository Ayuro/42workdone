/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_err2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:08:53 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:08:53 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"
#include "../include/minishell.h"

t_e		*ft_init_env(void)
{
	t_e		*env;
	int		fd;
	char	*str;

	if (tgetent(NULL, "xterm-256color") == ERR)
		quit_error_fd("Joshua is confused: terminals database is \
inaccessible", 2);
	env = ft_get_env(0);
	if (env)
		env->export = ft_get_export(0);
	exec_shrc(env);
	env->gitlen = 0;
	if ((fd = open(".git", O_RDONLY) != -1))
	{
		str = getenv("PWD");
		get_git(str);
		if (str)
			env->gitlen = ft_strlen(str);
	}
	return (env);
}

void	replace_var_quote(char **s, t_e **e)
{
	int		i;
	int		max;

	if (!s || !*s || !e)
		return ;
	i = 0;
	max = ft_strlen(*s);
	while ((*s)[i])
	{
		if ((*s)[i] == '$')
		{
			replace_var(e, s, ft_strdup(*s + i + 1), i - 1);
			max = ft_strlen(*s);
		}
		if (i >= max)
			return ;
		if ((*s)[i] == 39)
		{
			i++;
			while ((*s)[i] && (*s)[i] != 39)
				i++;
		}
		i++;
	}
}

char	**ft_inhib(char *s, t_e **e)
{
	replace_var_quote(&s, e);
	return (ft_go_home(ft_bananasplit(s), *e, 0));
}

int		read_error(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putendl_fd(": not a valid identifier", 2);
	return (1);
}

t_e		*ft_setexport_err(t_e *env)
{
	ft_putendl_fd("export: wrong arguments, arguments contain '='", 2);
	if (env)
		env->status = 1;
	return (env);
}
