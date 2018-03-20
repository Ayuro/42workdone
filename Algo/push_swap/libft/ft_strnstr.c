/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:22:31 by flemaist          #+#    #+#             */
/*   Updated: 2013/12/23 13:56:01 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		while (s1[i] == s2[j] && s2[j] != '\0' && i < n)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)&(s1[i - j]));
		else
			i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
