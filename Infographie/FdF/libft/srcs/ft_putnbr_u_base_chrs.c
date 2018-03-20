/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_base_chrs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:44:49 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:44:50 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_u_base_chrs(unsigned int nb, char *base)
{
	int		len;

	len = ft_strlen(base);
	if (nb / len == 0)
		ft_putchar(base[nb]);
	else
	{
		ft_putnbr_u_base_chrs(nb / len, base);
		ft_putnbr_u_base_chrs(nb % len, base);
	}
}
