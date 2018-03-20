/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:56:30 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:56:30 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

t_point			*point_new(long x, long y, long z)
{
	t_point	*np;

	if ((np = (t_point *)malloc(sizeof(t_point))) == NULL)
		exit_failure_malloc();
	np->ox = x;
	np->oy = y;
	np->oz = z;
	np->x = 0;
	np->y = 0;
	np->pt = NULL;
	np->pr = NULL;
	np->pb = NULL;
	np->pl = NULL;
	return (np);
}
