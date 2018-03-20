/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:51:17 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 18:51:18 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t		i;
	void		*str;

	i = 0;
	if ((str = malloc(size)) == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}
