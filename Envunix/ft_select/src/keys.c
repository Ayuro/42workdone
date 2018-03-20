/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:05:27 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:05:29 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int	is_arrow(char c)
{
	if (c == MY_UP || c == MY_DN || c == MY_LFT || c == MY_RGT)
		return (c);
	return (0);
}

int			catch_key(t_display *g_tty_info)
{
	char	buf[6];

	buf[0] = 0;
	buf[1] = 0;
	buf[2] = 0;
	read(0, buf, 6);
	if (buf[0] == 32 && buf[1] == 0 && buf[2] == 0)
		return (MY_SP);
	if ((buf[0] == 127 && buf[1] == 0 && buf[2] == 0) ||
		(buf[0] == 27 && buf[1] == 91 && buf[2] == 51))
		return (MY_BSP);
	if (buf[0] == 27 && buf[1] == 0 && buf[2] == 0)
		return (-1);
	if (buf[0] == 10 && buf[1] == 0 && buf[2] == 0)
		return (1);
	if (buf[0] == 27 && buf[1] == 91)
		return (is_arrow(buf[2]));
	if (buf[0] == 96 && buf[1] == 0 && buf[2] == 0)
		return (GO_HO);
	if (ft_isprint(buf[0]) == SUCCESS && buf[1] == 0 && buf[2] == 0)
		return (find_syntax(&buf[0], g_tty_info));
	return (0);
}
