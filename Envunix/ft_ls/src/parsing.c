/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:23:43 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/18 17:23:45 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	get_error(t_flist *elem, t_diser *args, t_flags *flags)
{
	elem = new_args(args->iargs->dname, errno);
	sort_args(args, elem, 1, flags);
	args->iargs = args->iargs->next;
	flags->nfirst = 1;
	flags->error = 1;
}

void	parse_args(t_diser *args, t_flags *flags)
{
	t_flist			*elem;
	struct stat		s;
	struct stat		sl;
	int				tmp;

	while (args->iargs)
	{
		if (stat(args->iargs->dname, &s) == -1 && \
			lstat(args->iargs->dname, &sl) == -1)
		{
			get_error(elem, args, flags);
			continue ;
		}
		lstat(args->iargs->dname, &sl);
		tmp = 2;
		tmp = S_ISDIR(s.st_mode) ? 3 : tmp;
		tmp = (S_ISLNK(sl.st_mode) && flags->l) ? 2 : tmp;
		elem = new_args(args->iargs->dname, s.st_mtime);
		if (flags->f)
			fill_args(args, elem, tmp);
		else
			sort_args(args, elem, tmp, flags);
		args->iargs = args->iargs->next;
	}
}

int		check_empty(int ac, char **av)
{
	while (--ac)
		if (!av[ac][0])
			return (0);
	return (1);
}
