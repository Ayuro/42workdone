/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:46:16 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:46:16 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrlen_u(unsigned int nb)
{
	int				len;
	unsigned int	cpy;

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
