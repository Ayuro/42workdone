/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:05:28 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/18 18:05:29 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		put_dname(char *dname, t_flags *fl)
{
	if (fl->nfirst == 1 && !fl->error)
		ft_putchar('\n');
	ft_putstr(dname);
	ft_putendl(":");
}

void		create_list(char *dname, t_flags *fl, t_maxl *maxl, int t)
{
	t_fdata		*fdata;

	fdata = NULL;
	maxl->total = 0;
	maxl->nblocks = 0;
	if (t == 2)
		fdata = fdatanew("", dname, fl, maxl);
	if (t == 3 && (fl->nfirst == 1 || fl->count != 0))
		put_dname(dname, fl);
	fl->error = 0;
	fl->nfirst = 1;
	if (t == 3)
		fdata = get_list(dname, fl, maxl);
	if (t != 3)
		maxl->total = -1;
	fdata = print_list(fdata, fl, maxl);
	while (fl->ur && fdata)
	{
		ft_bzero(maxl, sizeof(t_maxl));
		if (fdata->mode[0] == 'd' && ft_strcmp(fdata->dname, ".") && \
				ft_strcmp(fdata->dname, ".."))
			create_list(fdata->path, fl, maxl, t);
		fdata = fdata->next;
	}
}
