/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:06:10 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:06:11 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_lu(void *c)
{
	unsigned long		nb;

	nb = (unsigned long)(long int)c;
	ft_putnbr_lu_base(nb, 10);
	return (ft_nbrlen_lu_base(nb, 10));
}
