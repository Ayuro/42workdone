/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lu_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:45:09 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:45:10 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_lu_base(unsigned long nb, int base)
{
	if (nb / base == 0)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr_lu_base(nb / base, base);
		ft_putnbr_lu_base(nb % base, base);
	}
}
