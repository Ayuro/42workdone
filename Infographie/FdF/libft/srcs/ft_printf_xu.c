/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:03:57 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:04:02 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_xu(void *c)
{
	int		nb;

	nb = (int)(long int)c;
	ft_putstr(nb >= 0 ? "0X" : "-0X");
	ft_putnbr_base_chrs(ABS(nb), "0123456789ABCDEF");
	return (ft_nbrlen_base_chrs(nb, "0123456789ABCDEF") + 2);
}
