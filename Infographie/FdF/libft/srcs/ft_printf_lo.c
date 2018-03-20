/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:06:04 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:06:04 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_lo(void *c)
{
	long int	nb;

	nb = (long int)c;
	ft_putstr(nb >= 0 ? "0" : "-0");
	ft_putnbr_l_base(ABS(nb), 8);
	return (ft_nbrlen_l_base(nb, 8) + 1);
}
