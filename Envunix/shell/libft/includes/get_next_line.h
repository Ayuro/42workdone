/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:26:02 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 13:26:04 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define BUFF_SIZE 32

int						get_next_line(int const fd, char **line);

typedef struct			s_struct
{
	char				*b1;
	char				*b2;
	int					fd;
	struct s_struct		*next;
	struct s_struct		*prev;
}						t_struct;

#endif
