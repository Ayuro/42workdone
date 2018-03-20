/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:06:38 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:06:39 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_p(void *c)
{
	unsigned long		nb;
	int					n0;

	nb = (unsigned long)c;
	if (nb == 0)
	{
		ft_putstr("0p00000000");
		return (10);
	}
	n0 = 8 - ft_nbrlen_lu_base(nb, 16);
	ft_putstr("0p");
	while (n0 != 0)
	{
		ft_putchar('0');
		n0--;
	}
	ft_putnbr_lu_base_chrs(nb, "0123456789abcdef");
	return (10);
}
