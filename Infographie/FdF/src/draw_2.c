/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:55:10 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:55:10 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

void		write_color(unsigned char *ptr, int color)
{
	int		dec;
	int		opp;
	t_mlxd	*m;

	m = sg_mlx();
	opp = m->opp;
	dec = opp;
	while (dec--)
	{
		if (m->endian == m->lendian && m->endian)
			*(ptr + dec) = ((unsigned char *)(&color))[4 - opp + dec];
		else if (m->endian == m->lendian && !(m->endian))
			*(ptr + dec) = ((unsigned char *)(&color))[dec];
		else if (m->endian)
			*(ptr + dec) = ((unsigned char *)(&color))[opp - 1 - dec];
		else
			*(ptr + dec) = ((unsigned char *)(&color))[3 - dec];
	}
}

void		put_point_to_img(int x, int y, int color)
{
	t_mlxd			*m;
	unsigned char	*ptr;

	m = sg_mlx();
	if (x < 0 || y < 0 || x >= sg_screen()->w || y >= sg_screen()->h)
		return ;
	ptr = m->data + y * (m->sl) + x * m->opp;
	write_color(ptr, mlx_get_color_value(m->i, color));
}

void		put_points_to_img(void)
{
	t_point			*cp;
	t_point			*cl;

	cl = sg_map()->ptl;
	while (cl != NULL)
	{
		cp = cl;
		while (cp != NULL)
		{
			put_point_to_img(cp->x, cp->y, color_of(cp->oz));
			lines_of_point_to_img(cp);
			cp = cp->pr;
		}
		cl = cl->pb;
	}
}
