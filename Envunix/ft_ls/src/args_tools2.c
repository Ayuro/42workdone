/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:20:44 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/19 18:20:45 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		intcmp(long a, long b, t_flags *flags)
{
	if (a < b)
		return (1);
	else if (a > b)
		return (0);
	return (flags->r);
}

int		scmp(char *a, char *b)
{
	return ((ft_strcmp(a, b) >= 0) ? 1 : 0);
}

t_flist	*args_insort(t_flist *fdata, t_flist *elem, t_flags *flgs)
{
	t_flist	*tmp;
	t_flist	*prev;

	if (!fdata)
		return (elem);
	tmp = fdata;
	prev = NULL;
	if (flgs->t)
	{
		while (flgs->t && tmp && intcmp(elem->mtime, tmp->mtime, flgs) != \
			flgs->r && (prev = tmp))
			tmp = tmp->next;
		while (tmp && scmp(elem->dname, tmp->dname) != flgs->r && (prev = tmp))
			tmp = tmp->next;
	}
	else
		while (tmp && scmp(elem->dname, tmp->dname) != flgs->r && (prev = tmp))
			tmp = tmp->next;
	if (!prev)
		fdata = elem;
	else
		prev->next = elem;
	elem->next = tmp;
	return (fdata);
}
