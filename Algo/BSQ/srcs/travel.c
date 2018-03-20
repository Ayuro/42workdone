/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:44:53 by flemaist          #+#    #+#             */
/*   Updated: 2017/07/25 15:44:57 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static int		check_line(t_map *map, int temp_l, int x, int y)
{
	int		surf;

	if (x + temp_l > map->w)
		return (RET_FAIL);
	surf = 0;
	while (surf < temp_l)
	{
		if ((map->origin[y][x + surf]) != map->key[0])
			return (RET_FAIL);
		surf++;
	}
	return (RET_OK);
}

static int		check_square(t_map *map, int temp_l, int x, int y)
{
	int		down;

	if (y + temp_l > map->h)
		return (RET_FAIL);
	down = 0;
	while (down < temp_l)
	{
		if ((check_line(map, temp_l, x, (y + down))) == RET_FAIL)
			return (RET_FAIL);
		down++;
	}
	return (RET_OK);
}

static int		assign_temp_l(t_map *map, int i, int j)
{
	int		temp_l;

	temp_l = map->bsql;
	while ((check_square(map, temp_l, i, j)) == RET_OK)
	{
		if (temp_l > map->bsql)
		{
			map->bsqx = i;
			map->bsqy = j;
			map->bsql = temp_l;
		}
		temp_l++;
	}
	if ((check_square(map, temp_l, i, j)) == RET_FAIL)
		return (RET_FAIL);
	return (RET_OK);
}

int				travel(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < map->h)
	{
		while (i < map->w)
		{
			assign_temp_l(map, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
