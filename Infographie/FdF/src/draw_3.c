/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:55:14 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:55:15 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

void		ldata_init(t_point *p0, t_point *p1, t_ldata *ld)
{
	ld->x0 = p0->x;
	ld->y0 = p0->y;
	ld->x1 = p1->x;
	ld->y1 = p1->y;
	ld->dx = abs(ld->x1 - ld->x0);
	ld->dy = abs(ld->y1 - ld->y0);
	ld->sx = ld->x0 < ld->x1 ? 1 : -1;
	ld->sy = ld->y0 < ld->y1 ? 1 : -1;
	ld->err = (ld->dx > ld->dy ? ld->dx : -ld->dy) / 2;
}

void		line(t_point *p0, t_point *p1)
{
	t_ldata		ld;

	ldata_init(p0, p1, &ld);
	while (TRUE)
	{
		put_point_to_img(ld.x0, ld.y0, color_of(p0->oz));
		if (ld.x0 == ld.x1 && ld.y0 == ld.y1)
			break ;
		ld.e2 = ld.err;
		if (ld.e2 > -ld.dx)
		{
			ld.err -= ld.dy;
			ld.x0 += ld.sx;
		}
		if (ld.e2 < ld.dy)
		{
			ld.err += ld.dx;
			ld.y0 += ld.sy;
		}
	}
}

void		lines_of_point_to_img(t_point *p)
{
	if (p->pr != NULL)
		line(p, p->pr);
	if (p->pb != NULL)
		line(p, p->pb);
}
