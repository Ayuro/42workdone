/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 16:12:05 by sol               #+#    #+#             */
/*   Updated: 2015/05/11 13:50:54 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# include "libft.h"
# include "structs.h"
# include "mlx.h"

# define ERR_PNAME			"Error: "
# define ERR_MALLOC			"malloc seems unhappy"
# define ERR_NBARGS			"wrong number of arguments"
# define ERR_OPENMAPFILE 	"could not open file \""
# define ERR_MAPDIMS		"map given has something wrong in its dimentions"
# define ERR_GNL			"map file kinda odd"
# define ERR_MLX			"mlx said 'no'. Thats mean"
# define ERR_SSIZE			"screen size given is odd"
# define EXIT_MSG			"FdF successfully ended"

# define STDIN			0
# define STDOUT			1
# define STDERR			2

# define CLR_RED		"\033[0;31m"
# define CLR_YELLOW		"\033[0;33m"
# define CLR_BLUE		"\033[0;34m"
# define CLR_GREEN		"\033[0;32m"
# define CLR_DEF		"\033[0;0m"

# define SPACES			" \n\t\v\f\r"
# define DEF_SC_W		1200
# define DEF_SC_H		600
# define DEF_SC_PAD_W	- 25.0 / 100.0
# define DEF_SC_PAD_H	- 25.0 / 100.0
# define STEP_ROT_X		M_PI / 32.0
# define STEP_ROT_Z		M_PI / 32.0
# define DEF_RATIO_H	1.0
# define DEF_PADDING	10
# define DEF_CLRSTEP	50
# define DEF_COLOR		0xff7f00

# define OPT_CLSNONE	0
# define OPT_CLSFUN		1
# define OPT_CLSGEO		2
# define OPT_ROTISO		0
# define OPT_ROTFLAT	1

# if defined  (__linux__)
#  include "key_mapping_linux.h"
# elif defined  (__APPLE__) && defined  (__MACH__)
#  include "key_mapping_macos.h"
# endif

/*
** Errors
*/
int			exit_failure_malloc(void);
int			exit_failure_1s(char *s, t_bool exitmode);
int			exit_failure_2s(char *s1, char *s2, t_bool exitmode);
int			exit_failure_3s(char *s1, char *s2, char *s3, t_bool exitmode);
/*
** Points
*/
t_point		*point_new(long x, long y, long z);
void		point_print_one(t_point *p, char mode);
void		point_print_line(t_point *p, char mode);
void		point_print_map(t_point *p, char mode);
t_point		*point_addonr(t_point *left, t_point *np);
t_point		*point_addonb(t_point *top, t_point *np);
/*
** Map
*/
t_map		*sg_map();
void		map_add_point(long z);
void		map_add_line(long z);
void		map_this_was_last();
void		map_print();
/*
** Other singletons
*/
t_screen	*sg_screen();
void		screen_dims_update();
t_mods		*sg_mods();
void		mods_update();
t_mlxd		*sg_mlx();
t_optionset	*sg_opt();
/*
** Parser and right after parser
*/
void		parse_args(int *fd, int ac, char ***av);
void		read_map(int fd);
void		parse_line_of_map(const char *s);
void		rebase();
/*
** Key handling and callbacks
*/
int			key_dispatcher(int key);
int			keycb_exit(void);
void		keycb_rotx(int key);
void		keycb_rotz(int key);
void		keycb_isom(int key);
void		keycb_altitude(int key);
/*
** Div
*/
double		dist(t_point *p1, t_point *p2);
void		calc();
void		draw();
void		put_points_to_img();
void		lines_of_point_to_img(t_point *p);
void		put_point_to_img(int x, int y, int color);

int			rgb(int r, int g, int b);
int			color_of(int z);

#endif
