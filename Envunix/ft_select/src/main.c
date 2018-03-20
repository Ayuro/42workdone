/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:06:03 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:06:05 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int	main_loop(t_display *g_tty_info, t_termios *term)
{
	int			key;

	key = 0;
	while (key != -1 && key != 1)
	{
		ft_clear_term();
		print_lst(g_tty_info, g_tty_info->fst);
		key = catch_key(g_tty_info);
		move_cursor(key, g_tty_info);
		update_lst(key, g_tty_info);
		if (g_tty_info->print_nb == 0)
			key = -1;
	}
	ft_unset_term(term);
	tputs(tgetstr("te", NULL), 0, ft_outc);
	return (key);
}

int			main(int ac, char **av)
{
	char			*ttyname;
	struct termios	term;
	t_select		*fst;

	ttyname = 0;
	fst = 0;
	if (ac == 1)
	{
		ft_putendl("ft_select needs arguments to start");
		return (-1);
	}
	if ((ft_init_term(&term, ttyname)) == -1)
		return (-1);
	if ((fst = put_to_lst(av, ac)) == NULL)
		return (-1);
	signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	g_tty_info = t_display_init(fst);
	if (main_loop(g_tty_info, &term) == 1)
		final_display(g_tty_info);
	t_display_free(g_tty_info);
	return (0);
}
