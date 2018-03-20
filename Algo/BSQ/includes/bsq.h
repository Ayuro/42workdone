/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:42:18 by flemaist          #+#    #+#             */
/*   Updated: 2017/07/25 15:55:27 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

/*
*** SYSTEM LIBRARIES
*/

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <errno.h>

/*
*** MACROS & STRUCTS
*/

# define BUF_SIZE 	1000

# define RET_OK		0
# define RET_FAIL	-1

# define TRUE		0
# define FALSE		1

# define ERR_DIR		"Can't display a directory.\n"
# define ERR_PARSE	"map error\n"

typedef struct	s_map
{
	int			h;
	int			w;
	char		key[3];
	int			bsqx;
	int			bsqy;
	int			bsql;
	char		**origin;
}				t_map;

/*
*** MAIN FUNCTION PROTOTYPES (IN CALL ORDER)
*/

char			parser(t_map *map, char mode, char *file);
int				travel(t_map *map);
void			display(t_map *end);

void			ft_error(int error);
char			exit_failure_1s(char *s, char exitmode);

/*
*** PARSING FUNCTION PROTOTYPES (IN ALPHABETICAL ORDER)
*/

int				check_copy_collumn(char *str, char *hei, int i);
int				check_font(char *str, t_map *map, int first_l);
int				check_key_1(int j);
int				check_key_2(t_map *map);
int				check_width(char *str, t_map *map);
void			fill_me_up(t_map *map, char *str);
int				get_first_line(t_map *map, char *str);
int				get_width(t_map *map, char *str, int j);
t_map			*map_malloc(t_map *map);

/*
*** BASICS (IN ALPHABETICAL ORDER)
*/

int				ft_atoi(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int i);
void			ft_putstr(char *str);
void			ft_putstr_err(char *str);
char			*ft_strcat(char *stdin, char *buf);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str);

#endif
