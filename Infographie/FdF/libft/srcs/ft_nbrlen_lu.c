/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_lu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:46:21 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:46:21 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrlen_lu(unsigned long nb)
{
	int				len;
	unsigned long	cpy;

	if (nb == 0)
		return (1);
	len = 0;
	cpy = nb;
	while (cpy != 0)
	{
		cpy /= 10;
		len++;
	}
	return (nb > 0 ? len : len + 1);
}
