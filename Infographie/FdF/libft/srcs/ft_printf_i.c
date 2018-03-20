/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:05:30 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:05:30 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_i(void *c)
{
	int	nb;

	nb = (int)(long int)c;
	ft_putnbr_base(nb, 10);
	return (ft_nbrlen_base(nb, 10));
}
