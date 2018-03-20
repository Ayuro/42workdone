/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:36:58 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 19:36:59 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	beg;
	size_t	i;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	beg = 0;
	while (s1[beg + i] != '\0' && s2[i] != '\0' && (beg + i) < n)
	{
		while ((ft_memcmp(&(s1[beg + i]), &(s2[i]), 1) == 0) && (beg + i) < n)
		{
			i++;
			if (s2[i] == '\0' && (beg + i) <= n)
				return ((char *)s1 + beg);
		}
		i = 0;
		beg++;
	}
	return (NULL);
}
