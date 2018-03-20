/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:36:33 by flemaist          #+#    #+#             */
/*   Updated: 2013/11/25 13:32:54 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned char		*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (s1);
}
