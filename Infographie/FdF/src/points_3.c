/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:56:44 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:56:45 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

void		point_print_one(t_point *p, char mode)
{
	if (mode == 't')
		ft_printf("%s t:", CLR_RED);
	if (mode == 'r')
		ft_printf("%s r:", CLR_BLUE);
	if (mode == 'b')
		ft_printf("%s b:", CLR_YELLOW);
	if (mode == 'l')
		ft_printf("%s l:", CLR_GREEN);
	if (p == NULL)
		ft_putstr("NULL\n");
	else
	{
		ft_printf("ox:%d:oy:%d:oz:%d", p->ox, p->oy, p->oz);
		ft_printf(" x:%d:y:%d\n", p->x, p->y);
	}
	if (mode == 'a')
	{
		point_print_one(p->pt, 't');
		point_print_one(p->pr, 'r');
		point_print_one(p->pb, 'b');
		point_print_one(p->pl, 'l');
	}
	if (mode != 'n' && mode != 'd')
		ft_putstr(CLR_DEF);
}

void		point_print_line(t_point *p, char mode)
{
	t_point	*cp;

	if (p == NULL)
		return ;
	cp = p;
	while (cp != NULL)
	{
		point_print_one(cp, mode);
		cp = cp->pr;
	}
}

void		point_print_map(t_point *p, char mode)
{
	t_point	*cl;

	if (p == NULL)
		return ;
	cl = p;
	while (cl != NULL)
	{
		point_print_line(cl, mode);
		cl = cl->pb;
	}
}
