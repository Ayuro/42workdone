/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:18:23 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/19 18:18:27 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	sort_args(t_diser *args, t_flist *elem, int type, t_flags *flags)
{
	int				tmp;
	int				tmp2;

	if (type == 1)
	{
		tmp = flags->t;
		tmp2 = flags->r;
		flags->t = 0;
		flags->r = 0;
		args->error = args_insort(args->error, elem, flags);
		flags->t = tmp;
		flags->r = tmp2;
	}
	else if (type == 2)
		args->file = args_insort(args->file, elem, flags);
	else if (type == 3)
		args->dir = args_insort(args->dir, elem, flags);
}

void	fill_args(t_diser *args, t_flist *elem, int type)
{
	if (type == 2)
		args->file = add_args(args->file, elem);
	else if (type == 3)
		args->dir = add_args(args->dir, elem);
}

t_flist	*add_args(t_flist *list, t_flist *elem)
{
	t_flist	*tmp;

	if (!list)
		return (elem);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (list);
}

t_flist	*new_args(char *name, time_t time)
{
	t_flist	*new;

	new = ft_memalloc(sizeof(t_flist));
	new->dname = ft_strdup(name);
	new->mtime = time;
	new->next = NULL;
	return (new);
}

void	get_args(int ac, char **av, t_diser *args)
{
	int			i;
	t_flist		*elem;

	i = 0;
	while (++i < ac)
	{
		elem = new_args(av[i], 0);
		args->iargs = add_args(args->iargs, elem);
	}
}
