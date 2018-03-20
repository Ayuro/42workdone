/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:54:55 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:54:56 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

double		dist(t_point *p1, t_point *p2)
{
	const double	pow1 = pow((p1->ox - p2->ox), 2);
	const double	pow2 = pow((p1->oy - p2->oy), 2);

	return (sqrt(pow1 + pow2));
}
