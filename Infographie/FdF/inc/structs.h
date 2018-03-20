/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 17:53:37 by sol               #+#    #+#             */
/*   Updated: 2015/05/11 13:05:46 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct s_point		t_point;
typedef	struct s_map		t_map;
typedef	struct s_screen		t_screen;
typedef	struct s_mods		t_mods;
typedef	struct s_mlxd		t_mlxd;
typedef	struct s_ldata		t_ldata;
typedef	struct s_optionset	t_optionset;

struct		s_point
{
	long	ox;
	long	oy;
	long	oz;
	long	x;
	long	y;
	t_point	*pt;
	t_point	*pr;
	t_point	*pb;
	t_point	*pl;
};

struct		s_map
{
	t_point	*ptl;
	t_point	*ptr;
	t_point	*pbl;
	t_point	*pbr;
	t_point *cp;
	t_point	*cl;
	long	dim_w;
	long	dim_l;
	long	cx;
	long	cy;
	double	diag_14;
};

struct		s_screen
{
	int		w;
	int		h;
	int		inner_w;
	int		inner_h;
	int		mid_w;
	int		mid_h;
};

struct		s_mods
{
	double	sxy;
	double	ratio_h;
	double	sz;
	double	rx;
	double	rz;
	double	cos_rz;
	double	sin_rz;
	double	cos_rx;
	double	sin_rx;
};

struct		s_mlxd
{
	void			*i;
	void			*win;
	void			*img;
	unsigned char	*data;
	int				lendian;
	int				endian;
	int				sl;
	int				bpp;
	int				opp;
};

struct		s_ldata
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
};

struct		s_optionset
{
	t_iny	colorset;
	int		colorstep;
	int		padding;
	double	rotation;
	int		screen_w;
	int		screen_h;
};

#endif
