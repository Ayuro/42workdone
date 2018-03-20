/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:05:51 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:05:52 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	move_cursor(int key, t_display *g_tty_info)
{
	if (key == GO_HO)
	{
		g_tty_info->current = g_tty_info->fst;
		while (g_tty_info->current->print == 0)
			g_tty_info->current = g_tty_info->current->nxt;
	}
	if (key == MY_LFT || key == MY_RGT)
		key = (key == MY_RGT) ? MY_UP : MY_DN;
	if (key == MY_UP)
	{
		g_tty_info->current = g_tty_info->current->prv;
		while (g_tty_info->current->print == 0)
			g_tty_info->current = g_tty_info->current->prv;
	}
	if (key == MY_DN)
	{
		g_tty_info->current = g_tty_info->current->nxt;
		while (g_tty_info->current->print == 0)
			g_tty_info->current = g_tty_info->current->nxt;
	}
}

void	update_lst(int key, t_display *g_tty_info)
{
	if (key == MY_SP)
	{
		g_tty_info->current->select =
		(g_tty_info->current->select == 1) ? 0 : 1;
		move_cursor(MY_DN, g_tty_info);
	}
	else if (key == MY_BSP)
	{
		g_tty_info->current->print = 0;
		g_tty_info->print_nb--;
		while (g_tty_info->print_nb != 0 && g_tty_info->current->print == 0)
			g_tty_info->current = g_tty_info->current->nxt;
	}
	return ;
}
