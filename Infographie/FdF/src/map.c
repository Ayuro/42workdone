/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:56:03 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:56:04 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

t_map		*sg_map(void)
{
	static t_map	*map = NULL;

	if (map == NULL)
	{
		if ((map = (t_map*)malloc(sizeof(t_map))) == NULL)
			exit_failure_malloc();
		map->ptl = NULL;
		map->ptr = NULL;
		map->pbl = NULL;
		map->pbr = NULL;
		map->cp = NULL;
		map->cl = NULL;
		map->dim_w = 0;
		map->dim_l = 0;
		map->cx = 0;
		map->cy = 0;
		map->diag_14 = 0;
	}
	return (map);
}

void		map_add_point(long z)
{
	t_map	*map;
	t_point	*np;

	map = sg_map();
	if (map->cl == NULL)
	{
		np = point_new(0, 0, z);
		map->ptl = np;
		map->cp = np;
		map->cl = np;
		map->cx = map->cx + DEF_PADDING;
		return ;
	}
	np = point_new(map->cx, map->cy, z);
	map->cp = point_addonr(map->cp, np);
	map->cx = map->cx + DEF_PADDING;
}

void		map_add_line(long z)
{
	t_map	*map;
	t_point	*np;

	map = sg_map();
	if (map->cl == NULL)
	{
		np = point_new(0, 0, z);
		map->ptl = np;
		map->cp = np;
		map->cl = np;
		map->cx = map->cx + DEF_PADDING;
		return ;
	}
	np = point_new(0, map->cy + DEF_PADDING, z);
	map->cp = point_addonb(map->cl, np);
	map->cl = map->cp;
	map->cx = DEF_PADDING;
	map->cy = map->cy + DEF_PADDING;
}

void		map_this_was_last(void)
{
	t_map	*map;

	map = sg_map();
	map->pbl = map->cl;
	map->pbr = map->cp;
	map->dim_l = map->pbl->oy / DEF_PADDING;
	map->diag_14 = dist(map->ptl, map->pbr);
}

void		map_print(void)
{
	t_map	*map;

	map = sg_map();
	ft_putstr("ptl:");
	point_print_one(map->ptl, 'n');
	ft_putstr("ptr:");
	point_print_one(map->ptr, 'n');
	ft_putstr("pbl:");
	point_print_one(map->pbl, 'n');
	ft_putstr("pbr:");
	point_print_one(map->pbr, 'n');
	ft_printf("dim_h:%ld\n", map->dim_w);
	ft_printf("dim_l:%ld\n", map->dim_l);
}
