/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:46:55 by flemaist          #+#    #+#             */
/*   Updated: 2014/12/12 19:46:57 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		gnl_endoffile(t_gnl *gnl, char **line)
{
	char	*found;

	gnl->tmp = ft_strjoin(gnl->tmp, gnl->buf);
	ft_strclr(gnl->buf);
	if ((found = ft_memchr(gnl->tmp, '\n', ft_strlen(gnl->tmp))) != NULL)
	{
		*line = ft_strsub(gnl->tmp, 0, ft_strlen(gnl->tmp) - ft_strlen(found));
		gnl->tmp = ft_strsub(found, 1, (ft_strlen(found)));
		return (GNL_EOL);
	}
	*line = ft_strsub(gnl->tmp, 0, (ft_strlen(gnl->tmp)));
	return (GNL_EOF);
}

static t_gnl	*build_struct(int fd, t_gnl *gnl)
{
	if ((gnl = (t_gnl*)malloc(sizeof(t_gnl))) == NULL ||
		(gnl->buf = (char*)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
		return (NULL);
	if ((gnl->tmp = (char*)malloc(sizeof(char))) == NULL)
		return (NULL);
	gnl->next = NULL;
	gnl->prev = NULL;
	gnl->fd = fd;
	return (gnl);
}

static t_gnl	*struct_init(int fd, t_gnl *gnl)
{
	if (gnl == NULL)
	{
		if ((gnl = build_struct(fd, gnl)) == NULL)
			return (NULL);
	}
	else if (gnl->fd != fd && gnl != NULL)
	{
		while (gnl->prev != NULL)
		{
			gnl = gnl->prev;
			if (gnl->fd == fd)
				return (gnl);
		}
		while (gnl->next != NULL)
		{
			gnl = gnl->next;
			if (gnl->fd == fd)
				return (gnl);
		}
		gnl->next = build_struct(fd, gnl->next);
		gnl->next->prev = gnl;
		gnl = gnl->next;
	}
	return (gnl);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*gnl = NULL;
	int				ret;

	if (line == NULL || fd < 0)
		return (GNL_ERROR);
	if (gnl == NULL || gnl->fd != fd)
		if ((gnl = struct_init(fd, gnl)) == NULL)
			return (GNL_ERROR);
	while ((ret = read(fd, gnl->buf, BUFF_SIZE)) == BUFF_SIZE)
		if (gnl_endoffile(gnl, line) == GNL_EOL)
			return (GNL_EOL);
	if (ret == -1)
		return (GNL_ERROR);
	if ((ret = gnl_endoffile(gnl, line)) == GNL_EOL)
		return (GNL_EOL);
	return (GNL_EOF);
}
