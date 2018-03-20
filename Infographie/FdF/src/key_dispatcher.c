/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dispatcher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:55:47 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:55:48 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	key_dispatcher(int key)
{
	if (key == T_ESC)
		keycb_exit();
	if (key == T_DOWN || key == T_UP)
		keycb_rotx(key);
	if (key == T_LEFT || key == T_RIGHT)
		keycb_rotz(key);
	if (key == T_T || key == T_I || key == T_F)
		keycb_isom(key);
	if (key == T_PLUS || key == T_MINUS || key == T_C || key == T_V)
		keycb_altitude(key);
	return (0);
}
