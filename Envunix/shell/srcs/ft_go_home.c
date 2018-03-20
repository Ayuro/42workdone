/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:12:45 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/13 14:12:45 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char		**boucle_go_home(char **t, int i, t_e *temp, char *s)
{
	while (t && t[i])
	{
		if (t[i][0] == '~' && temp)
		{
			s = ft_strdup(temp->str + 5);
			t[i] = ft_go_home2(t[i], s);
		}
		i++;
	}
	return (t);
}

char			**ft_go_home(char **t, t_e *home, int i)
{
	char		*s;
	t_e			*temp;
	int			a;

	s = NULL;
	a = 0;
	while (t && t[a])
	{
		t[a] = clear_str(t[a]);
		a++;
	}
	temp = home;
	if (!t)
		return (NULL);
	while (temp && ft_start_str("HOME=", temp->str) == 0)
		temp = temp->next;
	t = boucle_go_home(t, i, temp, s);
	if (t[0] && t[1])
		t[1] = ft_get_oldpwd(t[1], home);
	ft_strdel(&s);
	return (t);
}
