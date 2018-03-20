/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:54:44 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:54:45 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static void		rotate_n_rebase(t_point *p)
{
	double			r1x;
	double			r1y;
	const double	r1z = (double)(p->oz) * sg_mods()->sz;

	r1x = (double)(p->ox) * sg_mods()->cos_rz;
	r1x -= (double)(p->oy) * sg_mods()->sin_rz;
	r1y = (double)(p->ox) * sg_mods()->sin_rz;
	r1y += (double)(p->oy) * sg_mods()->cos_rz;
	p->x = r1x + sg_screen()->mid_w;
	p->y = (sg_mods()->cos_rx) * r1y - (sg_mods()->sin_rx) * r1z;
	p->y += sg_screen()->mid_h;
}

void			calc(void)
{
	t_point			*cp;
	t_point			*cl;

	cl = sg_map()->ptl;
	while (cl != NULL)
	{
		cp = cl;
		while (cp != NULL)
		{
			rotate_n_rebase(cp);
			cp = cp->pr;
		}
		cl = cl->pb;
	}
}
