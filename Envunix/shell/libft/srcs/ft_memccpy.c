/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:51:34 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 18:51:49 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*temp;
	const char	*temp2;

	temp = dst;
	temp2 = src;
	while (n > 0)
	{
		*temp = *temp2;
		if (*temp2 == c)
			return (temp + 1);
		temp++;
		temp2++;
		n--;
	}
	return (NULL);
}
