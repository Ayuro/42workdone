/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fget_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:40:48 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/18 18:40:49 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	get_time(t_fdata *fdata)
{
	char	*stime;
	int		t;

	stime = ft_memset(ft_memalloc(sizeof(char) * 15), ' ', 14);
	t = time(NULL);
	if (t - fdata->mtime > 15778800 || fdata->mtime - t > 15778800)
	{
		ft_strncpy(stime + 1, ctime(&(fdata->mtime)) + 4, 6);
		ft_strncpy(stime + 9, ctime(&(fdata->mtime)) + 20, 4);
	}
	else
		ft_strncpy(stime + 1, ctime(&(fdata->mtime)) + 4, 12);
	fdata->smtime = stime;
}

void	get_uid(uid_t st_uid, gid_t st_gid, t_fdata *fdata)
{
	struct passwd	*tmp;
	struct group	*tmp2;

	tmp = getpwuid(st_uid);
	fdata->ouid = ft_strdup(tmp->pw_name);
	tmp2 = getgrgid(st_gid);
	fdata->ogid = ft_strdup(tmp2->gr_name);
}

char	*get_mode(mode_t mode)
{
	char	*ret;

	ret = ft_strnew(11);
	ret[1] = S_IRUSR & mode ? 'r' : '-';
	ret[2] = S_IWUSR & mode ? 'w' : '-';
	if ((S_ISUID & mode))
		ret[3] = ((S_IXUSR & mode) ? 's' : 'S');
	else
		ret[3] = ((S_IXUSR & mode) ? 'x' : '-');
	ret[4] = S_IRGRP & mode ? 'r' : '-';
	ret[5] = S_IWGRP & mode ? 'w' : '-';
	if ((mode & S_ISGID))
		ret[6] = ((S_IXGRP & mode) ? 's' : 'S');
	else
		ret[6] = ((S_IXGRP & mode) ? 'x' : '-');
	ret[7] = S_IROTH & mode ? 'r' : '-';
	ret[8] = S_IWOTH & mode ? 'w' : '-';
	if ((S_ISVTX & mode))
		ret[9] = ((S_IXOTH & mode) ? 't' : 'T');
	else
		ret[9] = ((S_IXOTH & mode) ? 'x' : '-');
	return (ret);
}

char	*get_type(char *ret, mode_t mode)
{
	ret[0] = S_ISDIR(mode) ? 'd' : '-';
	ret[0] = S_ISLNK(mode) ? 'l' : ret[0];
	ret[0] = S_ISBLK(mode) ? 'b' : ret[0];
	ret[0] = S_ISCHR(mode) ? 'c' : ret[0];
	ret[0] = S_ISSOCK(mode) ? 's' : ret[0];
	ret[0] = S_ISFIFO(mode) ? 'p' : ret[0];
	ret[0] = S_ISWHT(mode) ? 'w' : ret[0];
	return (ret);
}

char	*get_attr(char *ret, char *dname)
{
	ssize_t		xattr;
	acl_t		acl;

	xattr = listxattr(dname, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_link_np(dname, ACL_TYPE_EXTENDED);
	if (xattr > 0)
		ret[10] = '@';
	else if (acl != NULL)
		ret[10] = '+';
	else
		ret[10] = ' ';
	return (ret);
}
