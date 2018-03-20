/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:05:14 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:05:14 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_bu(void *c)
{
	int		nb;

	nb = (int)(long int)c;
	ft_putstr(nb >= 0 ? "0B" : "-0B");
	ft_putnbr_base(ABS(nb), 2);
	return (ft_nbrlen_base(nb, 2) + 2);
}
