/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:52:00 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 18:52:01 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	if (s == NULL || n <= 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return ((void *)((size_t)s + i));
		i++;
	}
	return (NULL);
}
