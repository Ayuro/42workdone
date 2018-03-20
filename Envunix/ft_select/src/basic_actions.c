/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:05:06 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:05:07 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		ft_unset_term(t_termios *term)
{
	tputs(tgetstr("ve", NULL), 0, ft_outc);
	tcsetattr(0, 0, term);
	return (0);
}

int		ft_set_term(t_termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if ((tcsetattr(0, TCSADRAIN, term)) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 0, ft_outc);
	tputs(tgetstr("vi", NULL), 0, ft_outc);
	return (0);
}

int		ft_init_term(t_termios *term, char *ttyname)
{
	if ((ttyname = getenv("TERM")) == NULL ||
		(tgetent(NULL, ttyname)) == -1 ||
		(tcgetattr(0, term)) == -1 ||
		(ft_set_term(term)) == -1)
	{
		ft_putendl("Couldn't initialize terminal; ft_select aborted");
		return (-1);
	}
	return (0);
}

int		ft_outc(int c)
{
	ft_putchar(c);
	return (0);
}

void	ft_clear_term(void)
{
	tputs(tgetstr("cl", NULL), 0, ft_outc);
	tputs(tgetstr("ce", NULL), 0, ft_outc);
	return ;
}
