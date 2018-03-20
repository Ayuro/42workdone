/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:06:36 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:06:37 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	handle_abort(t_termios *t)
{
	ft_clear_term();
	ft_unset_term(t);
	tputs(tgetstr("te", NULL), 0, ft_outc);
	ft_clear_term();
	exit(-1);
}

static void	handle_sigwinch(t_winsize *w)
{
	g_tty_info->win_w = w->ws_col;
	g_tty_info->win_h = w->ws_row;
	print_lst(g_tty_info, g_tty_info->fst);
	display_search(g_tty_info);
}

static void	handle_sigtstp(t_termios *t)
{
	char	cp[2];

	cp[0] = t->c_cc[VSUSP];
	cp[1] = 0;
	ft_clear_term();
	ft_unset_term(t);
	tputs(tgetstr("te", NULL), 0, ft_outc);
	ft_clear_term();
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCONT, signal_handler);
	ioctl(0, TIOCSTI, &(cp[0]));
}

static void	handle_sigcont(t_termios *t)
{
	struct winsize	w;

	ft_set_term(t);
	ft_clear_term();
	ioctl(0, TIOCGWINSZ, &w);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, SIG_DFL);
	handle_sigwinch(&w);
}

void		signal_handler(int c)
{
	struct winsize	w;
	struct termios	t;
	char			buff[2048];

	ioctl(0, TIOCGWINSZ, &w);
	tgetent(buff, getenv("TERM"));
	tcgetattr(0, &t);
	if (c == SIGWINCH)
		handle_sigwinch(&w);
	if (c == SIGTSTP)
		handle_sigtstp(&t);
	if (c == SIGCONT)
		handle_sigcont(&t);
	if (c == SIGQUIT || c == SIGINT)
		handle_abort(&t);
	return ;
}
