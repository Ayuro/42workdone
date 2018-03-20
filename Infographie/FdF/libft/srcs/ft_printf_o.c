/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:06:32 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:06:33 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_o(void *c)
{
	int		nb;

	nb = (int)(long int)c;
	ft_putstr(nb >= 0 ? "0" : "-0");
	ft_putnbr_base(ABS(nb), 8);
	return (ft_nbrlen_base(nb, 8) + 1);
}
