/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_display.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:06:50 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:06:52 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int	win_too_small(void)
{
	ft_clear_term();
	tputs("TOO SMALL", 0, ft_outc);
	return (-1);
}

static int	co_and_li(t_display *g_tty_info)
{
	int		mod;

	mod = 0;
	if (g_tty_info->win_w < g_tty_info->col_w)
		return (win_too_small());
	if (g_tty_info->win_h < g_tty_info->print_nb)
	{
		mod = (g_tty_info->print_nb % g_tty_info->win_h == 0) ? 0 : 1;
		g_tty_info->col_nb = g_tty_info->print_nb / g_tty_info->win_h + mod;
		if (g_tty_info->col_nb * g_tty_info->col_w > g_tty_info->win_w)
			return (win_too_small());
		g_tty_info->row_h = g_tty_info->win_h;
	}
	else
		g_tty_info->row_h = g_tty_info->print_nb;
	return (0);
}

int			t_display_update(t_display *g_tty_info)
{
	t_select		*travel;
	int				longest;

	travel = g_tty_info->fst;
	g_tty_info->print_nb = 0;
	longest = 0;
	g_tty_info->col_nb = 1;
	while (travel->nxt != g_tty_info->fst)
	{
		if (travel->print == 1)
		{
			g_tty_info->print_nb++;
			if ((int)ft_strlen(travel->name) > longest)
				longest = ft_strlen(travel->name);
		}
		travel = travel->nxt;
	}
	if (travel->print == 1)
	{
		g_tty_info->print_nb++;
		if ((int)ft_strlen(travel->name) > longest)
			longest = ft_strlen(travel->name);
	}
	g_tty_info->col_w = longest + 5;
	return (co_and_li(g_tty_info));
}

t_display	*t_display_init(t_select *fst)
{
	t_display		*new;

	new = (t_display*)malloc(sizeof(t_display));
	new->fst = fst;
	new->current = fst;
	new->row_h = 0;
	new->print_nb = 0;
	new->win_h = tgetnum("li");
	new->win_w = tgetnum("co");
	new->col_w = 0;
	new->col_nb = 1;
	new->small = 0;
	t_display_update(new);
	return (new);
}

void		t_display_free(t_display *g_tty_info)
{
	g_tty_info->row_h = 0;
	g_tty_info->print_nb = 0;
	g_tty_info->win_w = 0;
	g_tty_info->win_h = 0;
	g_tty_info->col_w = 0;
	g_tty_info->col_nb = 0;
	g_tty_info->small = 0;
	g_tty_info->current = NULL;
	free_lst(g_tty_info->fst);
	g_tty_info->fst = NULL;
	g_tty_info->search = NULL;
	free(g_tty_info);
}
