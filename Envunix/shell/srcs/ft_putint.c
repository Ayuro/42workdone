/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:42:35 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 14:42:36 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"

int		ft_putint(int c)
{
	write(get_fd(-1), &c, 1);
	return (1);
}