/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/28 23:23:34 by flemaist          #+#    #+#             */
/*   Updated: 2014/09/28 23:23:36 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE		8
# define GNL_ERROR		-1
# define GNL_EOF		0
# define GNL_EOL		1

typedef struct			s_gnl
{
	char				*buf;
	char				*tmp;
	int					fd;
	struct s_gnl		*next;
	struct s_gnl		*prev;
}						t_gnl;

int						get_next_line(int const fd, char **line);

#endif
