/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:43:30 by flemaist          #+#    #+#             */
/*   Updated: 2017/07/25 15:43:35 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static void		init_map(t_map *map)
{
	map->h = 0;
	map->w = 0;
	map->key[0] = 0;
	map->key[1] = 0;
	map->key[2] = 0;
	map->bsqx = 0;
	map->bsqy = 0;
	map->bsql = 0;
	map->origin = NULL;
}

static char		exec(char mode, char *file)
{
	t_map	map;

	init_map(&map);
	if (mode == 'f' && parser(&map, mode, file) == RET_FAIL)
		return (exit_failure_1s(ERR_PARSE, FALSE));
	else if (mode == 'e' && parser(&map, mode, NULL) == RET_FAIL)
		return (exit_failure_1s(ERR_PARSE, FALSE));
	travel(&map);
	display(&map);
	return (0);
}

int				main(int ac, char **av)
{
	int		i;

	if (ac == 1)
		exec('e', NULL);
	else
	{
		i = 1;
		while (i < ac)
		{
			exec('f', av[i]);
			i++;
			if (i != ac)
				ft_putchar('\n');
		}
	}
	return (0);
}
