/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 16:09:38 by flemaist          #+#    #+#             */
/*   Updated: 2013/12/23 13:51:01 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*str;
	int		i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l1 + l2) + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (i < l1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		str[i + l1] = s2[i];
		i++;
	}
	str[i + l1] = '\0';
	return (str);
}
