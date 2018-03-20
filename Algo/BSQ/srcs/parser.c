/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:43:47 by flemaist          #+#    #+#             */
/*   Updated: 2017/07/25 15:43:51 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static char	get_map(t_map *map, char *str)
{
	map = map_malloc(map);
	fill_me_up(map, str);
	return (RET_OK);
}

static int	get_metadata(t_map *map, char *str)
{
	int		first_l;

	if ((first_l = (get_first_line(map, str))) == RET_FAIL)
		return (RET_FAIL);
	if ((get_width(map, str, first_l)) == RET_FAIL)
		return (RET_FAIL);
	if (map->h == 0 || map->w == 0)
		return (RET_FAIL);
	if (check_font(str, map, first_l) == RET_FAIL)
		return (RET_FAIL);
	return (RET_OK);
}

static char	get_str(char **str, int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	*str = "";
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		if (ret == -1)
			return (RET_FAIL);
		buf[ret] = '\0';
		*str = ft_strjoin(*str, buf);
	}
	return (RET_OK);
}

static char	open_file(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (RET_FAIL);
	return (RET_OK);
}

char		parser(t_map *map, char mode, char *file)
{
	int		fd;
	char	*str;

	fd = 0;
	if (mode == 'e')
		fd = 0;
	else if (mode == 'f' && (open_file(file, &fd) == RET_FAIL))
		return (RET_FAIL);
	if (get_str(&str, fd) == RET_FAIL)
		return (RET_FAIL);
	if (get_metadata(map, str) == RET_FAIL)
		return (RET_FAIL);
	if (get_map(map, str) == RET_FAIL)
		return (RET_FAIL);
	return (RET_OK);
}
