/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:07:04 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:07:05 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_x(void *c)
{
	int		nb;

	nb = (int)(long int)c;
	ft_putstr(nb >= 0 ? "0x" : "-0x");
	ft_putnbr_base_chrs(ABS(nb), "0123456789abcdef");
	return (ft_nbrlen_base_chrs(nb, "0123456789abcdef") + 2);
}
