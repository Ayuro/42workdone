/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:06:58 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:06:59 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_u(void *c)
{
	unsigned int		nb;

	nb = (unsigned int)(long int)c;
	ft_putnbr_u_base(nb, 10);
	return (ft_nbrlen_u_base(nb, 10));
}
