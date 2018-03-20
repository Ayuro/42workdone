/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_metadata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:44:35 by flemaist          #+#    #+#             */
/*   Updated: 2017/07/25 15:44:38 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int			get_first_line(t_map *map, char *str)
{
	int		i;
	int		j;
	char	*hei;

	i = 0;
	j = 0;
	while (str[j] != '\n')
		j++;
	if (check_key_1(j) == RET_FAIL)
		return (RET_FAIL);
	hei = (char*)malloc(sizeof(char) * (j - 3));
	while (i < (j - 3))
	{
		if (check_copy_collumn(str, hei, i) == RET_FAIL)
			return (RET_FAIL);
		i++;
	}
	hei[i] = '\0';
	map->h = (ft_atoi(hei));
	map->key[0] = str[i];
	map->key[1] = str[i + 1];
	map->key[2] = str[i + 2];
	if (check_key_2(map) == RET_FAIL)
		return (RET_FAIL);
	return (j);
}

int			get_width(t_map *map, char *str, int j)
{
	int		k;

	k = 0;
	if (str[j + 1] == '\0')
		return (RET_FAIL);
	while (str[j + k + 1] != '\n')
		k++;
	map->w = k;
	if (check_width(str, map) == RET_FAIL)
		return (RET_FAIL);
	return (RET_OK);
}

static char	*fill_line(char *map_i, char *str, int *head)
{
	int		j;

	*head += 1;
	j = 0;
	while (str[*head] != '\n')
	{
		map_i[j] = str[*head];
		j++;
		(*head)++;
	}
	map_i[j] = '\n';
	map_i[j + 1] = '\0';
	return (map_i);
}

void		fill_me_up(t_map *map, char *str)
{
	int		i;
	int		key;
	int		head;

	key = 0;
	while (str[key] != '\n')
		key++;
	i = 0;
	head = key;
	while (i < map->h)
	{
		fill_line(map->origin[i], str, &head);
		i++;
	}
}

t_map		*map_malloc(t_map *map)
{
	int		i;

	i = 0;
	map->origin = (char**)malloc(sizeof(char *) * (map->h));
	while (i <= map->h)
	{
		map->origin[i] = (char*)malloc(sizeof(char) * ((map->w) + 2));
		i++;
	}
	return (map);
}
