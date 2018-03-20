/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:56:53 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:56:54 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

t_screen	*sg_screen(void)
{
	static	t_screen	*sc = NULL;

	if (sc == NULL)
	{
		if ((sc = (t_screen *)malloc(sizeof(t_screen))) == NULL)
			exit_failure_malloc();
		sc->w = sg_opt()->screen_w;
		sc->h = sg_opt()->screen_h;
		screen_dims_update();
	}
	return (sc);
}

void		screen_dims_update(void)
{
	t_screen	*sc;

	sc = sg_screen();
	sc->inner_w = (double)(sc->w) - (double)(sc->w) * DEF_SC_PAD_W;
	sc->inner_h = (double)(sc->h) - (double)(sc->h) * DEF_SC_PAD_H;
	sc->mid_w = sc->w / 2;
	sc->mid_h = sc->h / 2;
}

t_mods		*sg_mods(void)
{
	static t_mods	*md = NULL;

	if (md == NULL)
	{
		if ((md = (t_mods *)malloc(sizeof(t_mods))) == NULL)
			exit_failure_malloc();
		md->sxy = MIN(sg_screen()->inner_w, sg_screen()->inner_h);
		md->sxy = md->sxy / sg_map()->diag_14;
		md->ratio_h = DEF_RATIO_H;
		md->rz = sg_opt()->rotation == OPT_ROTISO ? M_PI / 4 : 0;
		md->rx = sg_opt()->rotation == OPT_ROTISO ? M_PI / 4 : 0;
		mods_update();
	}
	return (md);
}

void		mods_update(void)
{
	t_mods		*md;

	md = sg_mods();
	md->cos_rz = cos(md->rz);
	md->sin_rz = sin(md->rz);
	md->cos_rx = cos(md->rx);
	md->sin_rx = sin(md->rx);
	md->sz = md->ratio_h * md->sxy;
}

t_mlxd		*sg_mlx(void)
{
	static t_mlxd	*mlx = NULL;
	t_screen		*sc;
	int				a;

	if (mlx == NULL)
	{
		if ((mlx = (t_mlxd *)malloc(sizeof(t_mlxd))) == NULL)
			exit_failure_malloc();
		if ((mlx->i = mlx_init()) == NULL)
			exit_failure_1s(ERR_MLX, TRUE);
		sc = sg_screen();
		if ((mlx->win = mlx_new_window(mlx->i, sc->w, sc->h, "FdF")) == NULL)
			exit_failure_1s(ERR_MLX, TRUE);
		a = 0x11223344;
		mlx->lendian = (((unsigned char *)&a)[0] == 0x11) ? 1 : 0;
		mlx->bpp = 0;
		mlx->opp = 0;
	}
	if (mlx->opp == 0)
		mlx->opp = mlx->bpp / 8;
	return (mlx);
}
