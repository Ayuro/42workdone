/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:12:06 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:12:06 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"
#include "../include/minishell.h"

int		second_csh(int c, int n)
{
	if (c > '>')
		c = '|';
	if (n < 0 || n > 2)
		return (n);
	return (c);
}

int		csh_error(char *s, int i, int n, char c)
{
	int		check;
	char	*tmp;

	if (second_csh(c, n) == n)
		return (n);
	tmp = no_char(s, c);
	check = 0;
	while (s && !ft_strequ(tmp, s) && tmp[++i] && n < 3 && ++check)
	{
		if ((check_empty(tmp, i, check) == 1 && is_redir(tmp[i]) == 1
				&& ((tmp[i] == c && c != '|'))) || (tmp[i] == '<' && c == '|'))
			return (-1);
		if (check_empty(tmp, i, check) == 1 && is_redir(tmp[i]) == 1)
			return (-2);
		else if (check > 0 && is_redir(tmp[i] == 1))
		{
			if (ft_strequ(no_char(tmp, c), tmp))
				break ;
			tmp = no_char(tmp, c);
			check = 0;
		}
	}
	ft_strdel(&tmp);
	return (csh_error(s, -1, n + 1, c + 2));
}

int		red_error(t_e *env, char *s, int i)
{
	int		j;
	int		check;

	if (ft_err_red(env, s, -1) == -1)
		return (-1);
	if ((j = csh_error(s, -1, 0, '<')) < 0)
		return (print_red_error(s, 0, j));
	if (s && is_redir(s[0]) == 1 && (!s[1] || s[1] != '&'))
		return (print_red_error(s, -1, 0));
	while (s && s[++i])
	{
		check = 0;
		while (s[i] && is_redir(s[i]) == 1)
		{
			i++;
			check++;
			j = i;
			while (s[j] && (s[j] == ' ' || s[j] == '\t'))
				j++;
			if (((!s[j] || s[j] == ';') && s[i] == '|') || check > 2
					|| (check == 2 && (s[i - 1] != s[i - 2] || s[i] == '|')))
				return (print_red_error(s, i, check));
		}
	}
	return (1);
}
