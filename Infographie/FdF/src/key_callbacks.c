/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callbacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:55:34 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:55:39 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int		keycb_exit(void)
{
	ft_putendl(EXIT_MSG);
	exit (0);
}

void	keycb_rotx(int key)
{
	if (key == T_UP)
		sg_mods()->rx += STEP_ROT_X;
	if (key == T_DOWN)
		sg_mods()->rx -= STEP_ROT_X;
	mods_update();
	draw();
}

void	keycb_rotz(int key)
{
	if (key == T_LEFT)
		sg_mods()->rz -= STEP_ROT_Z;
	if (key == T_RIGHT)
		sg_mods()->rz += STEP_ROT_Z;
	mods_update();
	draw();
}

void	keycb_isom(int key)
{
	if (key == T_T || key == T_F)
	{
		sg_mods()->rz = 0;
		sg_mods()->rx = 0;
	}
	if (key == T_I)
	{
		sg_mods()->rz = M_PI / 4;
		sg_mods()->rx = M_PI / 4;
	}
	mods_update();
	draw();
}

void	keycb_altitude(int key)
{
	if (key == T_C)
		sg_opt()->colorstep = sg_opt()->colorstep * 1.2;
	if (key == T_V)
		sg_opt()->colorstep = sg_opt()->colorstep / 1.2;
	if (key == T_PLUS)
		sg_mods()->ratio_h = sg_mods()->ratio_h * 1.2;
	if (key == T_MINUS)
		sg_mods()->ratio_h = sg_mods()->ratio_h / 1.2;
	mods_update();
	draw();
}
