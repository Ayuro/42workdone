/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:22:15 by flemaist          #+#    #+#             */
/*   Updated: 2015/01/12 18:22:16 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrendl(int n)
{
	if (n < 0)
		ft_putchar('-');
	else
		n = -n;
	if (n < -9)
		ft_putnbr(-(n / 10));
	ft_putchar(48 + -(n % 10));
	write(STDOUT_FILENO, "\n", 1);
}
