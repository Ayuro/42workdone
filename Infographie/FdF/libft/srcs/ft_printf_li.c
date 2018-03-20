/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_li.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:05:52 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:05:53 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_li(void *c)
{
	int	nb;

	nb = (int)(long int)c;
	ft_putnbr_l_base(nb, 10);
	return (ft_nbrlen_l_base(nb, 10));
}