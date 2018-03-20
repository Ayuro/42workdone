/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:06:18 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:06:18 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_lx(void *c)
{
	long int		nb;

	nb = (long int)c;
	ft_putstr(nb >= 0 ? "0x" : "-0x");
	ft_putnbr_l_base_chrs(ABS(nb), "0123456789abcdef");
	return (ft_nbrlen_l_base_chrs(nb, "0123456789abcdef") + 2);
}
