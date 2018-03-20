/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:44:08 by flemaist          #+#    #+#             */
/*   Updated: 2017/07/25 15:44:17 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		check_width(char *str, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (map->h == 1)
		return (RET_OK);
	while (str[i] != '\n')
		i++;
	while (str[i + j] != '\0')
	{
		if (str[i + j] != '\n')
			j++;
		if (str[i + j] == '\n' && (j % (map->w + 1) == 0))
			j++;
		if (str[i + j] == '\n' && (j % (map->w + 1) != 0))
			return (RET_FAIL);
		if (str[i + j] != '\n' && (j % (map->w + 1) == 0))
			return (RET_FAIL);
	}
	if (j / (map->w + 1) != map->h)
		return (RET_FAIL);
	return (RET_OK);
}

int		check_copy_collumn(char *str, char *hei, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		hei[i] = str[i];
	else
		return (RET_FAIL);
	return (RET_OK);
}

int		check_key_1(int j)
{
	if (j < 3)
	{
		exit_failure_1s(ERR_PARSE, FALSE);
		return (RET_FAIL);
	}
	return (RET_OK);
}

int		check_key_2(t_map *map)
{
	if (map->key[0] == map->key[1] ||
		map->key[1] == map->key[2] ||
		map->key[0] == map->key[2])
		return (RET_FAIL);
	return (RET_OK);
}

int		check_font(char *str, t_map *map, int first_l)
{
	int		i;

	i = first_l + 1;
	while (str[i] != '\0')
	{
		if (str[i] != map->key[0] && str[i] != map->key[1]
			&& str[i] != '\n')
			return (RET_FAIL);
		i++;
	}
	return (RET_OK);
}
