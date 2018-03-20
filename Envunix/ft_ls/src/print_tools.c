/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:24:07 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/19 16:24:09 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_ino(t_fdata *fdata, t_maxl *maxl, t_flags *flags)
{
	if (flags->i)
	{
		put_padded(NULL, fdata->ino, maxl->ino);
		ft_putchar(' ');
	}
}

void		append_type(t_fdata *fdata, t_flags *flags)
{
	int		i;

	i = 0;
	if (fdata->mode[0] == 'd')
		return (ft_putchar('/'));
	if (flags->uf)
	{
		if (fdata->mode[0] == 'l')
			return (ft_putchar('@'));
		if (fdata->mode[0] == 's')
			return (ft_putchar('='));
		if (fdata->mode[0] == 'p')
			return (ft_putchar('|'));
		if (fdata->mode[0] == 'w')
			return (ft_putchar('%'));
		while (i < 10)
		{
			if (fdata->mode[i] == 'x')
				return (ft_putchar('*'));
			i++;
		}
	}
}

void		print_long(t_fdata *fdata, t_maxl *maxl, t_flags *flags)
{
	if (maxl->total != -1)
	{
		ft_putstr("total ");
		ft_putnbr(maxl->nblocks);
		ft_putchar('\n');
		maxl->total = -1;
	}
	print_ino(fdata, maxl, flags);
	ft_putstr(fdata->mode);
	put_padded(NULL, fdata->nlinks, maxl->links + 1);
	if (!flags->g)
		put_padded(fdata->ouid, 0, maxl->uid);
	if (!flags->o)
		put_padded(fdata->ogid, 0, maxl->gid);
	if (fdata->mode[0] == 'c' || fdata->mode[0] == 'b')
		put_majmin(fdata->rdev, maxl);
	else
		put_padded(NULL, fdata->size, maxl->size + 1);
	ft_putstr(fdata->smtime);
	ft_putstr(fdata->dname);
	if (flags->uf || flags->p)
		append_type(fdata, flags);
	if (fdata->mode[0] == 'l')
		putlink(fdata->path);
}

t_fdata		*print_list(t_fdata *fdata, t_flags *flags, t_maxl *maxl)
{
	t_fdata		*tmp;

	tmp = fdata;
	while (fdata)
	{
		if (flags->l)
			print_long(fdata, maxl, flags);
		else if (!flags->l)
			ft_putstr(fdata->dname);
		if ((flags->uf || flags->p) && !flags->l)
			append_type(fdata, flags);
		ft_putchar('\n');
		fdata = fdata->next;
	}
	return (tmp);
}
