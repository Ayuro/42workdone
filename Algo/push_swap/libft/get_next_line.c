/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:06:06 by flemaist          #+#    #+#             */
/*   Updated: 2013/12/22 18:07:32 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_test_eol(char *buf, int *i, char **line)
{
	int		k;

	if (ft_strchr(&buf[*i], '\n'))
	{
		k = *i;
		while (buf[*i] != '\n')
			(*i)++;
		buf[*i] = '\0';
		*line = ft_strjoin(*line, &buf[k]);
		(*i)++;
		return (1);
	}
	return (0);
}

static int	ft_test_no_eol(char *buf, int *i, int fd, char **line)
{
	int		ret;

	while (ft_strchr(&buf[*i], '\n') == NULL)
	{
		*line = ft_strjoin(*line, &buf[*i]);
		*i = 0;
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
		{
			if (ft_strlen(*line) != 0)
				return (1);
			if (ret == -1)
				return (-1);
			return (0);
		}
		buf[ret] = '\0';
	}
	return (2);
}

int			get_next_line(int const fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	int			ret;
	static int	i = 0;
	int			j;

	if (line && fd >= 0 && BUFF_SIZE > 0)
	{
		*line = ft_strnew(1);
		if (i == 0)
		{
			ret = read(fd, buf, BUFF_SIZE);
			if (ret == -1)
				return (-1);
			if (ret == 0)
				return (0);
			buf[ret] = '\0';
		}
		if ((j = ft_test_no_eol(buf, &i, fd, line)) != 2)
			return (j);
		if (ft_test_eol(buf, &i, line) == 1)
			return (1);
		return (0);
	}
	return (-1);
}
