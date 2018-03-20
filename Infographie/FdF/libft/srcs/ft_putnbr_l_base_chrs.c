/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_l_base_chrs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:44:31 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:44:32 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_l_base_chrs(long nb, char *base)
{
	int		len;

	len = ft_strlen(base);
	if (nb / len == 0)
	{
		ft_putstr(nb < 0 ? "-" : "");
		ft_putchar(base[ABS(nb)]);
	}
	else
	{
		ft_putnbr_l_base_chrs(nb / len, base);
		ft_putnbr_l_base_chrs(ABS(nb % len), base);
	}
}
