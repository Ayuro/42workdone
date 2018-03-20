/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:34:36 by flemaist          #+#    #+#             */
/*   Updated: 2013/12/23 13:22:09 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*str2;
	unsigned char		*str1;
	char				*ptr;

	ptr = NULL;
	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)(c))
		{
			i++;
			return (&str1[i]);
		}
		i++;
	}
	return (ptr);
}
