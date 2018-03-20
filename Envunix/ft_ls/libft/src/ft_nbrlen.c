/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:53:33 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 18:53:34 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrlen(long int nb)
{
	int			len;
	char		sign;
	int			deci;

	len = 0;
	sign = (nb < 0 ? 'n' : 'p');
	nb = (nb < 0 ? -nb : nb);
	deci = 1;
	while (nb / deci != 0)
	{
		deci *= 10;
		len++;
	}
	len = (nb == 0 ? 1 : len);
	if (sign == 'p')
		return (len);
	return (len + 1);
}
