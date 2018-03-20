/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdatanew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:21:59 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/18 18:22:00 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			get_long_data(struct stat dstat, t_fdata *elem, t_maxl *maxl)
{
	int		i;

	maxl->nblocks += dstat.st_blocks;
	get_uid(dstat.st_uid, dstat.st_gid, elem);
	i = ft_strlen(elem->ouid);
	maxl->uid = (i > maxl->uid) ? i : maxl->uid;
	i = ft_strlen(elem->ogid);
	maxl->gid = (i > maxl->gid) ? i : maxl->gid;
	elem->nlinks = dstat.st_nlink;
	i = ft_intsize(dstat.st_nlink);
	maxl->links = (i > maxl->links) ? i : maxl->links;
	i = ft_intsize(dstat.st_size);
	maxl->size = (i > maxl->size) ? i : maxl->size;
	elem->rdev = dstat.st_rdev;
	if ((elem->mode[0] == 'c' || elem->mode[0] == 'b'))
	{
		i = ft_intsize(MAJOR(dstat.st_rdev) / 16);
		maxl->masize = (i > maxl->masize) ? i : maxl->masize;
		i = ft_intsize(MINOR(dstat.st_rdev));
		maxl->masize = (i > maxl->masize) ? i : maxl->masize;
		maxl->size = (maxl->masize * 2) + 1;
	}
	get_time(elem);
}

void			get_data(struct stat dstat, t_fdata *elem, t_maxl *maxl)
{
	int		i;

	elem->size = dstat.st_size;
	elem->atime = dstat.st_atime;
	elem->mtime = dstat.st_mtime;
	elem->nsec = dstat.st_mtimespec.tv_nsec;
	elem->ino = dstat.st_ino;
	elem->mode = get_attr(get_type(get_mode(dstat.st_mode), dstat.st_mode), \
		elem->path);
	i = ft_intsize(elem->ino);
	maxl->ino = (i > maxl->ino ? i : maxl->ino);
}

char			*get_path(char *dst, char *src)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(dst);
	tmp = ft_realloc(tmp, ft_strlen(src) + 2);
	if (*dst)
		ft_strcat(tmp, "/");
	ft_strcat(tmp, src);
	return (tmp);
}

t_fdata			*fdatanew(char *dname, char *fname, t_flags *fl, t_maxl *maxl)
{
	t_fdata			*elem;
	struct stat		dstat;

	if (!(elem = ft_memalloc(sizeof(t_fdata))))
		return (NULL);
	if (!(elem->dname = ft_strdup(fname)) || (!fl->a && elem->dname[0] == '.'))
		return (NULL);
	if (fl->ua && (!ft_strcmp(elem->dname, ".") || \
		!ft_strcmp(elem->dname, "..")))
		return (NULL);
	dname = get_path(dname, fname);
	elem->path = ft_strdup(dname);
	if (lstat(dname, &dstat) == -1)
	{
		ft_putstr("ft_ls: ");
		perror(dname);
		return (NULL);
	}
	get_data(dstat, elem, maxl);
	if (fl->l)
		get_long_data(dstat, elem, maxl);
	elem->next = NULL;
	return (elem);
}
