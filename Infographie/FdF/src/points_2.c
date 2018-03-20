/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:56:38 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:56:39 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static t_point	*point_complete(t_point *p)
{
	if (p->ox == 0 && p->oy == 0)
		return (p);
	if (p->ox != 0)
		p->pl->pr = p;
	if (p->ox == 0)
		p->pt->pb = p;
	if (p->ox != 0 && p->oy != 0)
	{
		p->pt = p->pl->pt->pr;
		p->pl->pt->pr->pb = p;
	}
	return (p);
}

t_point			*point_addonr(t_point *left, t_point *np)
{
	np->pl = left;
	return (point_complete(np));
}

t_point			*point_addonb(t_point *top, t_point *np)
{
	np->pt = top;
	return (point_complete(np));
}
