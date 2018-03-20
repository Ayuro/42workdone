/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:25:17 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:27:51 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nb, int base)
{
	if (nb / base == 0)
	{
		ft_putstr(nb < 0 ? "-" : "");
		ft_putchar(ABS(nb) + '0');
	}
	else
	{
		ft_putnbr_base(nb / base, base);
		ft_putnbr_base(ABS(nb % base), base);
	}
}
