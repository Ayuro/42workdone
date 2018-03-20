/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:06:26 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:06:27 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		display_search(t_display *g_tty_info)
{
	if (g_tty_info->search != NULL &&
		((g_tty_info->win_h - g_tty_info->row_h) / 2) > 1 &&
		g_tty_info->win_w > (25 + (int)ft_strlen(g_tty_info->search)))
	{
		tputs(tgoto(tgetstr("cm", NULL), 0, 0), 0, ft_outc);
		tputs(tgetstr("ce", NULL), 0, ft_outc);
		tputs("Currently searching for : ", 0, ft_outc);
		tputs(tgetstr("md", NULL), 0, ft_outc);
		tputs(g_tty_info->search, 0, ft_outc);
		tputs(tgetstr("me", NULL), 0, ft_outc);
		tputs("\n", 0, ft_outc);
		tputs("Press enter to search.", 0, ft_outc);
	}
	return ;
}

static void	change_current(t_display *g_tty_info)
{
	int			len;
	t_select	*travel;

	len = ft_strlen(g_tty_info->search);
	travel = g_tty_info->fst;
	while (travel->nxt != g_tty_info->fst)
	{
		if (travel->print == 1 &&
			ft_strncmp(g_tty_info->search, travel->name, len) == 0)
		{
			g_tty_info->current = travel;
			print_lst(g_tty_info, g_tty_info->fst);
			return ;
		}
		travel = travel->nxt;
	}
	if (travel->print == 1 &&
		ft_strncmp(g_tty_info->search, travel->name, len) == 0)
		g_tty_info->current = travel;
	print_lst(g_tty_info, g_tty_info->fst);
}

int			find_syntax(char *c, t_display *g_tty_info)
{
	char		buf[3];
	char		*tmp;

	g_tty_info->search = c;
	display_search(g_tty_info);
	read(0, buf, 3);
	while (ft_isprint(buf[0]) == SUCCESS && buf[1] == 0 && buf[2] == 0)
	{
		tmp = ft_strjoin(g_tty_info->search, &(buf[0]));
		if (ft_strlen(g_tty_info->search) > 2)
			ft_strfree(g_tty_info->search);
		g_tty_info->search = tmp;
		buf[0] = 0;
		display_search(g_tty_info);
		read(0, buf, 3);
	}
	if (buf[0] == 27 && buf[1] == 0 && buf[2] == 0)
		return (-1);
	change_current(g_tty_info);
	g_tty_info->search = NULL;
	return (0);
}
