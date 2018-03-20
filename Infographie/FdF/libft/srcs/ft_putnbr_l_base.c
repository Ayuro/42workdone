/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_l_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:44:18 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:44:19 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_l_base(long nb, int base)
{
	if (nb / base == 0)
	{
		ft_putstr(nb < 0 ? "-" : "");
		ft_putchar(ABS(nb) + '0');
	}
	else
	{
		ft_putnbr_l_base(nb / base, base);
		ft_putnbr_l_base(ABS(nb % base), base);
	}
}
