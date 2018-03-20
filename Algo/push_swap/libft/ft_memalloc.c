/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:22:03 by flemaist          #+#    #+#             */
/*   Updated: 2013/12/03 17:30:54 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	int	*ptr;

	ptr = (void*)malloc(sizeof(*ptr) * (size + 1));
	if (!ptr)
		return (NULL);
	return (ptr);
}
