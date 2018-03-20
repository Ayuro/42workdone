/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:31:07 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/19 18:31:08 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		put_padded(char *str, int nbr, int width)
{
	int		len;

	if (str)
	{
		len = ft_strlen(str) - 1;
		ft_putchar(' ');
		ft_putstr(str);
		while ((width - len) > 0)
		{
			ft_putchar(' ');
			width--;
		}
	}
	else
	{
		len = ft_intsize(nbr);
		while ((width - len) > 0)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putnbr(nbr);
	}
}

void		put_majmin(dev_t rdev, t_maxl *maxl)
{
	put_padded(NULL, MAJOR(rdev) / 16, maxl->masize + 1);
	ft_putstr(",");
	put_padded(NULL, MINOR(rdev), maxl->masize + 1);
}

void		putlink(char *str)
{
	char	target[256];
	int		i;

	ft_putstr(" -> ");
	i = readlink(str, target, 256);
	target[i] = '\0';
	ft_putstr(target);
}
