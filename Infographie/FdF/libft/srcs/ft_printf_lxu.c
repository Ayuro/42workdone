/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lxu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:06:25 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:06:26 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_lxu(void *c)
{
	long int	nb;

	nb = (long int)c;
	ft_putstr(nb >= 0 ? "0X" : "-0X");
	ft_putnbr_l_base_chrs(ABS(nb), "0123456789ABCDEF");
	return (ft_nbrlen_l_base_chrs(nb, "0123456789ABCDEF") + 2);
}
