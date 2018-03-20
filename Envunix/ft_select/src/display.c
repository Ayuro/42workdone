/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:05:17 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:05:19 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	update_tmp_pos(int *trow, int *tcol, t_display *g_tty_info)
{
	int			x_margin;

	x_margin = ((g_tty_info->win_h - g_tty_info->row_h) / 2);
	if (*trow == g_tty_info->row_h + x_margin)
	{
		*trow = x_margin;
		*tcol += g_tty_info->col_w;
	}
	return ;
}

void		print_lst(t_display *g_tty_info, t_select *fst)
{
	t_select	*travel;
	int			tcol;
	int			trow;
	int			flag;

	travel = fst;
	if (t_display_update(g_tty_info) == -1)
		return ;
	ft_clear_term();
	tcol = ((g_tty_info->win_w - (g_tty_info->col_nb * g_tty_info->col_w)) / 2);
	trow = ((g_tty_info->win_h - g_tty_info->row_h) / 2);
	flag = 0;
	while (flag == 0 || travel != fst)
	{
		if (ft_strcmp(travel->name, g_tty_info->current->name) == 0)
			trow += print_current(travel, tcol, trow);
		else if (travel->select == 1)
			trow += print_select(travel, tcol, trow);
		else
			trow += print_simple(travel, tcol, trow);
		travel = travel->nxt;
		flag++;
		update_tmp_pos(&trow, &tcol, g_tty_info);
	}
	return ;
}

static int	count_selected(t_select *fst)
{
	t_select	*travel;
	int			count;

	count = (fst->print == 0) ? 0 : 1;
	travel = fst->nxt;
	while (travel != fst)
	{
		if (travel->print == 1)
			count++;
		travel = travel->nxt;
	}
	return (count);
}

static void	do_job(t_select *travel, t_winsize *w, int *row, int *col)
{
	if (travel->select == 1)
	{
		if ((*col = *col + ft_strlen(travel->name) + 1) > w->ws_col)
		{
			*col = 0;
			*row = *row + 1;
			if (*row > w->ws_row)
			{
				ft_clear_term();
				return ((void)tputs("TOO SMALL", 0, ft_outc));
			}
			print_simple(travel, *col, *row);
		}
		else
			print_simple(travel, (*col - ft_strlen(travel->name) - 1), *row);
	}
}

void		final_display(t_display *g_tty_info)
{
	t_select	*travel;
	t_winsize	w;
	int			row;
	int			col;

	ft_clear_term();
	ioctl(0, TIOCGWINSZ, &w);
	if (w.ws_col < g_tty_info->col_w)
		return ((void)tputs("TOO SMALL", 0, ft_outc));
	if (count_selected(g_tty_info->fst) == 0)
		return ;
	travel = g_tty_info->fst;
	row = 0;
	col = 0;
	while (travel->nxt != g_tty_info->fst)
	{
		do_job(travel, &w, &row, &col);
		travel = travel->nxt;
	}
	do_job(travel, &w, &row, &col);
	tputs("\n", 0, ft_outc);
	return ;
}
