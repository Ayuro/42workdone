/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:43:04 by flemaist          #+#    #+#             */
/*   Updated: 2017/07/25 15:43:08 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static void	st_display_sq(t_map *end, int j)
{
	int		i;

	i = 0;
	while (i <= (end->w))
	{
		while (i >= (end->bsqx) && i < ((end->bsqx) + (end->bsql)))
		{
			ft_putchar(end->key[2]);
			i++;
		}
		ft_putchar(end->origin[j][i]);
		i++;
	}
}

void		display(t_map *end)
{
	int		j;

	j = 0;
	while (j < end->h)
	{
		while (j >= (end->bsqy) && j < ((end->bsqy) + (end->bsql)))
		{
			st_display_sq(end, j);
			j++;
		}
		if (j < end->h)
		{
			ft_putstr(end->origin[j]);
			j++;
		}
	}
}
