/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_styles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:06:14 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:06:15 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int	print_current(t_select *travel, int tcol, int trow)
{
	if (travel->print == 0)
		return (0);
	tputs(tgoto(tgetstr("cm", NULL), tcol, trow), 0, ft_outc);
	tputs(tgoto(tgetstr("us", NULL), tcol, trow), 0, ft_outc);
	if (travel->select == 1)
		tputs(tgoto(tgetstr("so", NULL), tcol, trow), 0, ft_outc);
	tputs(travel->name, 0, ft_outc);
	tputs(tgoto(tgetstr("ue", NULL), tcol, trow), 0, ft_outc);
	if (travel->select == 1)
		tputs(tgoto(tgetstr("se", NULL), tcol, trow), 0, ft_outc);
	tputs(tgetstr("me", NULL), 0, ft_outc);
	return (1);
}

int	print_select(t_select *travel, int tcol, int trow)
{
	if (travel->print == 0)
		return (0);
	tputs(tgoto(tgetstr("cm", NULL), tcol, trow), 0, ft_outc);
	tputs(tgoto(tgetstr("so", NULL), tcol, trow), 0, ft_outc);
	tputs(travel->name, 0, ft_outc);
	tputs(tgoto(tgetstr("se", NULL), tcol, trow), 0, ft_outc);
	tputs(tgetstr("me", NULL), 0, ft_outc);
	return (1);
}

int	print_simple(t_select *travel, int tcol, int trow)
{
	if (travel->print == 0)
		return (0);
	tputs(tgoto(tgetstr("cm", NULL), tcol, trow), 0, ft_outc);
	tputs(travel->name, 0, ft_outc);
	tputs(tgetstr("me", NULL), 0, ft_outc);
	return (1);
}
