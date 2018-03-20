/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:33:34 by flemaist          #+#    #+#             */
/*   Updated: 2013/11/25 13:36:13 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 1;
	while (i <= n)
	{
		((unsigned char *)s)[i - 1] = '\0';
		i++;
	}
}