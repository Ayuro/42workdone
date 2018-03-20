/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:29:04 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/19 18:29:05 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_fdata		*lst_insert(t_fdata *prev, t_fdata *new, t_fdata *lst, t_fdata *tmp)
{
	if (!prev)
		lst = new;
	else
		prev->next = new;
	new->next = tmp;
	return (lst);
}

t_fdata		*lst_insort(t_fdata *fdata, t_fdata *elem, t_flags *fl)
{
	t_fdata		*tmp;
	t_fdata		*prev;

	if (!fdata)
		return (elem);
	tmp = fdata;
	prev = NULL;
	if (fl->t)
	{
		while (tmp && intcmp(elem->mtime, tmp->mtime, fl) != fl->r && \
				(prev = tmp))
			tmp = tmp->next;
		while (tmp && elem->mtime == tmp->mtime && \
				intcmp(elem->nsec, tmp->nsec, fl) != fl->r && (prev = tmp))
			tmp = tmp->next;
		while (tmp && elem->mtime == tmp->mtime && elem->nsec == tmp->nsec && \
				scmp(elem->dname, tmp->dname) != fl->r && (prev = tmp))
			tmp = tmp->next;
	}
	else
		while (tmp && scmp(elem->dname, tmp->dname) != fl->r && (prev = tmp))
			tmp = tmp->next;
	return (lst_insert(prev, elem, fdata, tmp));
}

t_fdata		*lst_add(t_fdata *fdata, t_fdata *elem)
{
	t_fdata		*tmp;

	if (!fdata)
		return (elem);
	tmp = fdata;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (fdata);
}

char		*get_fname(char *str)
{
	int					i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '/')
		i--;
	return (str + i + 1);
}

t_fdata		*get_list(char *dname, t_flags *fl, t_maxl *maxl)
{
	t_fdata				*fdata;
	DIR					*dir;
	struct dirent		*curdir;
	t_fdata				*tmp;

	curdir = NULL;
	fdata = NULL;
	if (!(dir = opendir(dname)))
	{
		ft_putstr_fd("ls: ", 2);
		perror(get_fname(dname));
	}
	else
	{
		while ((curdir = readdir(dir)))
		{
			tmp = fdatanew(dname, curdir->d_name, fl, maxl);
			if (tmp && fl->f)
				fdata = lst_add(fdata, tmp);
			else if (tmp)
				fdata = lst_insort(fdata, tmp, fl);
		}
		closedir(dir);
	}
	return (fdata);
}
