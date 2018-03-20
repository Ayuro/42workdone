/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:55:56 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:55:57 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int			rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int			color_of(int z)
{
	z = z * sg_opt()->colorstep;
	if (z < -3000)
		return (0x341260);
	if (z >= -3000 && z < -1500)
		return (0x361489);
	if (z >= -1500 && z < -600)
		return (0x351da4);
	if (z >= -600 && z < 0)
		return (0x3e1fcc);
	if (z >= 0 && z < 200)
		return (0x00ff15);
	if (z >= 200 && z < 600)
		return (0xc5ff00);
	if (z >= 600 && z < 1500)
		return (0xfcff00);
	if (z >= 1500 && z < 3000)
		return (0xff8700);
	if (z >= 3000 && z < 4000)
		return (0xa56a29);
	return (0xffffff);
}

int			main(int ac, char **av)
{
	int		fd;

	parse_args(&fd, ac, &av);
	read_map(fd);
	mlx_key_hook(sg_mlx()->win, key_dispatcher, NULL);
	draw();
	mlx_loop(sg_mlx()->i);
	return (0);
}
