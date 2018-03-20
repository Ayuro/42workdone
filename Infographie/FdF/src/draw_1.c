/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:55:04 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:55:05 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

void		draw(void)
{
	t_mlxd	*m;

	m = sg_mlx();
	m->img = mlx_new_image(m->i, sg_screen()->w, sg_screen()->h);
	m->data = (unsigned char *)mlx_get_data_addr(m->img, &(m->bpp), \
													&(m->sl), &(m->endian));
	calc();
	put_points_to_img();
	mlx_put_image_to_window (m->i, m->win, m->img, 0, 0);
}
