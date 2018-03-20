/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:52:45 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/18 17:52:47 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		print_final(t_flist *list, t_flags *flags, t_maxl *maxl, int type)
{
	t_fdata		*fdata;

	fdata = ft_memalloc(sizeof(t_fdata));
	if (!(flags->count = 0) && list && list->next)
		flags->count = 1;
	while (list)
	{
		create_list(list->dname, flags, maxl, type);
		list = list->next;
		flags->count = -1;
	}
	return (flags->count);
}

void	print_error(t_flist *list)
{
	while (list)
	{
		ft_putstr_fd("ft_ls: ", 2);
		if (list->dname)
		{
			ft_putstr_fd(list->dname, 2);
			ft_putstr_fd(": ", 2);
		}
		ft_putendl_fd(strerror(list->mtime), 2);
		list = list->next;
	}
}
