/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:04:23 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:04:23 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_b(void *c)
{
	int		nb;

	nb = (int)(long int)c;
	ft_putstr(nb >= 0 ? "0b" : "-0b");
	ft_putnbr_base(ABS(nb), 2);
	return (ft_nbrlen_base(nb, 2) + 2);
}
