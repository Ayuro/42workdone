/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:05:38 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:05:38 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_lb(void *c)
{
	long int	nb;

	nb = (long int)c;
	ft_putstr(nb >= 0 ? "0b" : "-0b");
	ft_putnbr_l_base(ABS(nb), 2);
	return (ft_nbrlen_l_base(nb, 2) + 2);
}
