/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:56:22 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:56:22 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

void		parse_args(int *fd, int ac, char ***av)
{
	char	*map_name;
	int		size;

	if (ac == 1)
		exit_failure_1s(ERR_NBARGS, TRUE);
	map_name = (*av)[1];
	*fd = open(map_name, O_RDONLY);
	if (*fd == -1)
		exit_failure_3s(ERR_OPENMAPFILE, map_name, "\"", TRUE);
	if (ac >= 3 && ft_strncmp((*av)[2], "-screen:", 8) == 0)
	{
		if (ft_strstr((*av)[2] + 8, ":") != NULL)
		{
			size = ft_atoi((*av)[2] + 8);
			if (size < 100 || size >= 3000)
				exit_failure_1s(ERR_SSIZE, TRUE);
			sg_screen()->w = size;
			size = ft_atoi(ft_strstr((*av)[2] + 8, ":") + 1);
			if (size < 100 || size >= 2000)
				exit_failure_1s(ERR_SSIZE, TRUE);
			sg_screen()->h = size;
			screen_dims_update();
		}
	}
}

t_iny		need_next_line(int fd, char **line)
{
	int		ret;

	ret = get_next_line(fd, line);
	if (ret == -1)
		exit_failure_1s(ERR_GNL, TRUE);
	if (*line[0] == '\0')
	{
		free(*line);
		return (FALSE);
	}
	return (TRUE);
}

void		rebase(void)
{
	const double	midx = (double)(sg_map()->pbr->ox) / 2;
	const double	midy = (double)(sg_map()->pbr->oy) / 2;
	t_point			*cp;
	t_point			*cl;

	cl = sg_map()->ptl;
	while (cl != NULL)
	{
		cp = cl;
		while (cp != NULL)
		{
			cp->ox = ((double)(cp->ox) - midx) * sg_mods()->sxy;
			cp->oy = ((double)(cp->oy) - midy) * sg_mods()->sxy;
			cp->oz = (double)(cp->oz);
			cp = cp->pr;
		}
		cl = cl->pb;
	}
}

void		read_map(int fd)
{
	char	*line;

	while (need_next_line(fd, &line) == TRUE)
	{
		parse_line_of_map(line);
		free(line);
	}
	if (sg_map()->cp == NULL)
		exit_failure_1s(ERR_MAPDIMS, TRUE);
	map_this_was_last();
	rebase();
}
