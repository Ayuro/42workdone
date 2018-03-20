/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_l_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:45:57 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:45:58 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen_l_base(long nb, int base)
{
	int		len;
	long	cpy;

	if (nb == 0)
		return (1);
	len = 0;
	cpy = nb;
	while (cpy != 0)
	{
		cpy /= base;
		len++;
	}
	return (nb > 0 ? len : len + 1);
}
